#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Apply quantization to values
                 */
                class Quantize : public MapOperator {
                public:

                    /**
                     *
                     * @param quant
                     * @return
                     */
                    Quantize(float quant) :
                        _quant(quant) {

                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        return floor(value / _quant);
                    }

                protected:
                    float _quant;
                };
            }
        }
    }
}