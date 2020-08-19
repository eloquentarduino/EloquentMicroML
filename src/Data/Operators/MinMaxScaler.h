#pragma once

#include "MapOperator.h"

namespace Eloquent {
    namespace ML {
        namespace Data {
            namespace Operators {
                /**
                 * Translates the input values from the range [inputMin, inputMax]
                 * to the range [outputMin, outputMax]
                 */
                class MinMaxScaler : public MapOperator {
                public:

                    /**
                     *
                     * @param inputMin
                     * @param inputMax
                     * @param outputMin
                     * @param outputMax
                     */
                    MinMaxScaler(float inputMin, float inputMax, float outputMin = 0, float outputMax = 1) :
                        _inputMin(inputMin),
                        _inputMax(inputMax),
                        _outputMin(outputMin) {
                            _coeff = (outputMax - outputMin) / (inputMax - inputMin);
                    }


                    float map(float value, uint16_t count, uint16_t size, float *array) {
                        return _outputMin + (constrain(value, _inputMin, _inputMax) - _inputMin) * _coeff;
                    }

                protected:
                    float _inputMin;
                    float _inputMax;
                    float _outputMin;
                    float _coeff;
                };
            }
        }
    }
}