#pragma once

#include "Operators/FilterOperator.h"
#include "Operators/MapOperator.h"

using namespace Eloquent::ML::Data::Operators;

namespace Eloquent {
    namespace ML {
        namespace Data {
            template <uint16_t size>
            class Array {
            public:
                Array() :
                    _filter(NULL),
                    _mapper(NULL) {
                    clear();
                }

                /**
                 * Get number of inserted elements
                 * @return
                 */
                inline virtual uint16_t count() {
                    return _count;
                }

                /**
                 * Get number of elements in the array
                 * @return
                 */
                inline virtual uint16_t length() {
                    return min(count(), size);
                }

                /**
                 * Test if array reached its maximum capacity
                 * @return
                 */
                inline virtual bool isFull() {
                    return count() >= size;
                }

                /**
                 * Get element at given index
                 * @param index
                 * @return
                 */
                virtual float at(int16_t index) {
                    return _array[index];
                }

                /**
                 *
                 * @return
                 */
                virtual float last() {
                    return this->at(_count - 1);
                }

                /**
                 * Get elements mean
                 * @param startIndex
                 * @return
                 */
                virtual float mean(int16_t startIndex = 0) {
                    float sum = 0;

                    for (uint16_t i = (startIndex + size) % size; i < length(); i++)
                        sum += this->at(i);

                    return sum / length();
                }

                /**
                 * Get elements standard deviation
                 * @param startIndex
                 * @return
                 */
                virtual float std(int16_t startIndex = 0) {
                    float variance = 0;
                    float mean = this->mean();

                    for (uint16_t i = (startIndex + size) % size; i < length(); i++)
                        variance += pow(this->at(i) - mean, 2);

                    return sqrt(variance / length());
                }

                /**
                 * Insert element at the end of the array
                 * @param value
                 */
                virtual bool insert(float value) {
                    if (isFull())
                        return false;

                    if (!passes(value))
                        return false;

                    _array[_count++] = resolve(value);

                    return true;
                }

                /**
                 * Delete array elements (set to 0 and reset count)
                 */
                virtual void clear() {
                    for (uint16_t i = 0; i < size; i++)
                        _array[i] = 0;

                    _count = 0;
                }

                /**
                 * Convert to plain array
                 * @param dest
                 * @return
                 */
                virtual float* toArray(float *dest = NULL) {
                    if (dest == NULL)
                        return _array;

                    memcpy(dest, _array, size * sizeof(float));

                    return dest;
                }

                /**
                 *
                 * @param stream
                 * @param delimiter
                 */
                virtual void printTo(Stream& stream, const char delimiter = ',') {
                    for (uint16_t i = 0; i < size; i++) {
                        stream.print(at(i), 6);
                        stream.print(i == size - 1? '\n' : delimiter);
                    }
                }

                /**
                 * Add filter operator
                 * @param mapper
                 */
                void filter(FilterOperator* filter) {
                    if (_filter == NULL) {
                        _filter = filter;
                    }
                    else {
                        _filter->then(filter);
                    }
                }

                /**
                 * Add map operator
                 * @param mapper
                 */
                void map(MapOperator* mapper) {
                    if (_mapper == NULL) {
                        _mapper = mapper;
                    }
                    else {
                        _mapper->then(mapper);
                    }
                }

            protected:
                uint16_t _count;
                float _array[size];
                FilterOperator *_filter;
                MapOperator *_mapper;

                /**
                 * Resolve filters chain
                 * @param value
                 * @return
                 */
                bool passes(float value) {
                    if (_filter == NULL)
                        return true;

                    return _filter->resolve(value, count(), size, _array);
                }

                /**
                 * Resolve mappers chain
                 * @param value
                 * @return
                 */
                float resolve(float value) {
                    if (_mapper) {
                        return _mapper->resolve(value, count(), size, _array);
                    }

                    return value;
                }
            };
        }
    }
}