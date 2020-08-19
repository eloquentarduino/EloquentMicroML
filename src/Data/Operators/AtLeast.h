#pragma once

#include "FilterOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Discard values less than threshold
                 */
                class AtLeast : public FilterOperator {
                public:
                    AtLeast(float low) :
                            _low(low) {

                    }


                    bool filter(float value, uint16_t count, uint16_t size, float *array) {
                        return value >= _low;
                    }


                protected:
                    float _low;
                };
            }
        }
    }
}