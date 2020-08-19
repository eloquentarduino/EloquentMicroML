#pragma once

#include "Array.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            template <uint16_t size>
            class EndlessArray : public Array<size> {
            public:

                /**
                 * Endless array is never full
                 * @return
                 */
                inline bool isFull() {
                    return false;
                }

                /**
                 * Get element at given index
                 * @param index
                 * @return
                 */
                float at(int16_t index) {
                    return this->_array[idx(index)];
                }

                /**
                 * Insert element at the end of the array
                 * @param value
                 */
                bool insert(float value) {
                    if (!this->passes(value))
                        return false;

                    this->_array[idx(0)] = this->resolve(value);
                    this->_count += 1;

                    return true;
                }

                /**
                 * Convert to plain array
                 * @param dest
                 * @return
                 */
                float* toArray(float *dest) {
                    for (uint16_t i = 0; i < size; i++)
                        dest[i] = at(i);

                    return dest;
                }

            protected:
                /**
                 * Convert logical index to physical index
                 * @param logicalIndex
                 * @return
                 */
                uint16_t idx(int16_t logicalIndex = 0) {
                    return (this->_count + logicalIndex + size) % size;
                }
            };
        }
    }
}