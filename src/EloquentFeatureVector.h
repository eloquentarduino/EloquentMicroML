#pragma once

namespace Eloquent {
    namespace ML {

        template <uint16_t size>
        class FeatureVector {
        public:
            /**
             *
             */
            FeatureVector() {
                _window = false;
                _head = 0;
                _count = 0;
                _mean = sqrt(-1);
                _std = sqrt(-1);
                _low = sqrt(-1);
                _high = sqrt(-1);

                for (uint16_t i = 0; i < size; i++)
                    _array[i] = 0;
            }

            /**
             * Alias for insert()
             * @param value
             * @return
             */
            FeatureVector& operator+=(const float value) {
                insert(value);

                return *this;
            }

            /**
             *
             * @return the number of elements in the vector
             */
            inline uint16_t count() {
                return min(_count, size);
            }

            /**
             *
             * @return if the vector contains {size} elements
             */
            inline bool isFull() {
                return count() == size;
            }

            /**
             * Get difference of current value from nth previous value
             * @return
             */
            inline float delta(uint16_t lookBack = 1) {
                return _array[(_head - 1 + size) % size] - _array[(_head - i - lookBack + size) % size]
            }

            /**
             * Turn on windowing, that is: you can append values to
             * the vector endlessly
             */
            inline void window() {
                _window = true;
            }

            /**
             * Clamp range of vector elements
             * @param low
             * @param high
             */
            inline void range(float low, float high) {
                _low = low < high ? low : high;
                _high = high > low ? high : low;
            }

            /**
             * Apply zero-mean to vector elements (a.k.a. substract {mean} from all elements)
             * @param mean
             */
            inline void mean(float mean) {
                _mean = mean;
            }

            /**
             * Apply unitary-std to vector elements (a.k.a. divide each element by given {std})
             * @param std
             */
            inline void std(float std) {
                _std = std;
            }

            /**
             * Normalize vector elements in range [0, 1]
             * @param low
             * @param high
             */
            void normalize(float low, float high) {
                if (low == high)
                    return;

                range(low, high);
                mean(low);
                std(high - low);
            }

            /**
             * Set all elements to 0 and start inserting from the beginning
             */
            void clear() {
                for (uint16_t i = 0; i < size; i++)
                    _array[i] = 0;

                _head = 0;
            }

            /**
             * Append element to the vector
             * @param value
             * @return
             */
            bool insert(float value) {
                if (!_window && isFull())
                    return false;

                if (!isnan(_low) && !isnan(_high))
                    value = value > _high ? _high : (value < _low ? _low : value);

                if (!isnan(_mean))
                    value -= _mean;

                if (!isnan(_std))
                    value /= _std;

                _array[_head] = value;
                _head = (_head + 1) % size;

                return true;
            }

            /**
             * Convert to plain array
             * @return a copy of the inner array (so you can apply transformations eg. PCA)
             */
            float toArray() {
                static float copy[size] = { 0 };

                // If windowing, slide the window to the beginning
                if (!_window) {
                    for (uint16_t i = 0; i < size; i++)
                        copy[i] = _array[(_head + i) % size];
                }
                else {
                    memcpy(copy, _array, count() * sizeof(float));
                }

                return copy;
            }

        protected:
            float _array[size];
            bool _window;
            uint16_t _head;
            uint32_t _count;
            float _mean;
            float _std;
            float _low;
            float _high;
        };
    }
}