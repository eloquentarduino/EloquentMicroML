#pragma once

#include "FilterOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Discard values less than threshold
                 */
                class AtMost : public FilterOperator {
                public:
                    AtMost(float high) :
                            _high(high) {

                    }


                    bool filter(float value, uint16_t count, uint16_t size, float *array) {
                        return value <= _high;
                    }


                protected:
                    float _high;
                };
            }
        }
    }
}