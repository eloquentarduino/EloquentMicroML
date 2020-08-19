#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Return absolute value
                 */
                class Absolute : public MapOperator {
                public:
                    Absolute() {

                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        return abs(value);
                    }
                };
            }
        }
    }
}