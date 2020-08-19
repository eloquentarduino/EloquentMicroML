#pragma once

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                class MapOperator {
                public:
                    /**
                     * Apply a map operation (element-wise)
                     * @param value
                     * @param count
                     * @param size
                     * @param array
                     * @return
                     */
                    virtual float map(float value, uint16_t count, uint16_t size, float *array) = 0;

                    /**
                     * Concatenate operators
                     * @param next
                     */
                    void then(MapOperator *next) {
                        if (_next == NULL)
                            _next = next;
                        else
                            _next->then(next);
                    }

                    /**
                     * Resolve mappers chain
                     * @param value
                     * @param index
                     * @param array
                     * @return
                     */
                    float resolve(float value, uint16_t count, uint16_t size, float *array) {
                        value = this->map(value, count, size, array);

                        if (_next != NULL) {
                            return _next->resolve(value, count, size, array);
                        }

                        return value;
                    }

                protected:
                    MapOperator *_next = NULL;
                };
            }
        }
    }
}