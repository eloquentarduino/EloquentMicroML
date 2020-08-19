#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Apply exponential smoothing
                 */
                class ExponentialSmoothing : public MapOperator {
                public:

                    /**
                     *
                     * @param smoothing in range ]0, 1[
                     */
                    ExponentialSmoothing(float smoothing) :
                        _smoothing(smoothing),
                        _prev(0) {

                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        float prev = (1 - _smoothing) * _prev;

                        _prev = value * _smoothing;

                        return _prev + prev;
                    }

                protected:
                    float _smoothing;
                    float _prev;
                };
            }
        }
    }
}