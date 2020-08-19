#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Truncate values ot of range
                 */
                class Clip : public MapOperator {
                public:
                    Clip(float low, float high) :
                        _low(low),
                        _high(high) {

                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        return value > _high ? _high : (value < _low ? _low : value);
                    }


                protected:
                    float _low;
                    float _high;
                };
            }
        }
    }
}