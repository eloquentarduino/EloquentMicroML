#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Transform values to mean = 0, std = 1
                 */
                class StandardScaler : public MapOperator {
                public:

                    /**
                     *
                     * @param mean
                     * @param std
                     * @return
                     */
                    StandardScaler(float mean, float std) :
                            _mean(mean),
                            _std(std) {

                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        return (value - _mean) / _std;
                    }

                protected:
                    float _mean;
                    float _std;
                };
            }
        }
    }
}