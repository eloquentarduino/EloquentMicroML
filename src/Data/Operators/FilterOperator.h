#pragma once

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Discard elements based on filter result
                 */
                class FilterOperator {
                public:
                    /**
                     *
                     * @param value
                     * @param count
                     * @param size
                     * @param array
                     * @return
                     */
                    virtual bool filter(float value, uint16_t count, uint16_t size, float *array) = 0;

                    /**
                     * Concatenate operators
                     * @param next
                     */
                    void then(FilterOperator *next) {
                        if (_next == NULL)
                            _next = next;
                        else
                            _next->then(next);
                    }

                    /**
                     * Resolve filters chain
                     * @param value
                     * @param index
                     * @param array
                     * @return
                     */
                    float resolve(float value, uint16_t count, uint16_t size, float *array) {
                        return this->filter(value, count, size, array) &&
                                (_next == NULL || _next->resolve(value, count, size, array));
                    }

                protected:
                    FilterOperator *_next = NULL;
                };
            }
        }
    }
}