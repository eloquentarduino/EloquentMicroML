#pragma once

#include "EloquentMLMath.h"
#include "EloquentAbstractClassifier.h"


namespace Eloquent {
    namespace ML {

        template<unsigned int features_dim>
        class PassiveAggressive : public AbstractClassifier<features_dim> {
        public:
            /**
             *
             */
            PassiveAggressive() {
                _params.C = 0.01;

                for (unsigned int i = 0; i < features_dim; i++)
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
            void fitOne(float x[features_dim], int label) {
                label = label > 0 ? 1 : -1;

                float loss = max(0, 1 - (label * dot<features_dim>(x, _weights)));
                float xnorm = dot<features_dim>(x, x);
                float tau = loss / (xnorm + (1 / (2 * _params.C))) * label;

                for (unsigned int i = 0; i < features_dim; i++)
                    _weights[i] += tau * x[i];
            }

            /**
             *
             * @param x
             * @return
             */
            int predict(float x[features_dim]) {
                return dot<features_dim>(x, _weights) > 0 ? 1 : -1;
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
            float _weights[features_dim];
        };
    }
}