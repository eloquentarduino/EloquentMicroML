#pragma once

#include "EloquentMLMath.h"


namespace Eloquent {
    namespace ML {

        template<unsigned int features_dim>
        class PassiveAggressiveClassifier {
        public:
            /**
             *
             */
            PassiveAggressiveClassifier() {
                _params.C = 0.01;

                for (unsigned int i = 0; i < features_dim; i++)
                    _weights[i] = 0;
            }

            /**
             * Set regularization factor
             * @param C
             */
            void setC(float C) {
                _params.C = C;
            }

            /**
             *
             * @param x
             * @param label
             * @return
             */
            bool fitOne(float x[features_dim], int label) {
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

        protected:
            struct {
                float C;
            } _params;
            float _weights[features_dim];
        };
    }
}