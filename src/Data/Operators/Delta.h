#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Return absolute value
                 */
                class Delta : public MapOperator {
                public:
                    Delta() :
                        _prev(0) {

                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        float delta = value - _prev;

                        _prev = value;

                        return delta;
                    }

                protected:
                    float _prev;
                };
            }
        }
    }
}