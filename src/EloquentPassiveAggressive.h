#pragma once

#include "EloquentMLMath.h"
#include "EloquentAbstractClassifier.h"


namespace Eloquent {
    namespace ML {

        template<unsigned int numFeatures>
        class PassiveAggressive : public AbstractClassifier<numFeatures> {
        public:
            /**
             *
             */
            PassiveAggressive() {
                _params.C = 0.01;

                for (unsigned int i = 0; i < numFeatures; i++)
                    _weights[i] = 0;
            }

            /**
             * Set regularization factor
             * @param C
             */
            void setC(float C) {
                set("C", C);
            }

            /**
             *
             * @param x
             * @param label
             * @return
             */
            void fitOne(float x[numFeatures], int label) {
                label = label > 0 ? 1 : -1;

                float loss = max(0, 1 - (label * dot<numFeatures>(x, _weights)));
                float xnorm = dot<numFeatures>(x, x);
                float tau = loss / (xnorm + (1 / (2 * _params.C))) * label;

                for (unsigned int i = 0; i < numFeatures; i++)
                    _weights[i] += tau * x[i];
            }

            /**
             *
             * @param x
             * @return
             */
            int predict(float x[numFeatures]) {
                return dot<numFeatures>(x, _weights) > 0 ? 1 : 0;
            }

            /**
             *
             * @param param
             * @param value
             */
            void set(const char *param, float value) {
                this->setParam(param, "C", &_params.C, value);
            }

        protected:
            struct {
                float C;
            } _params;
            float _weights[numFeatures];
        };
    }
}