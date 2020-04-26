#pragma once

#include "EloquentMLMath.h"
#include "EloquentAbstractClassifier.h"

namespace Eloquent {
    namespace ML {

        /**
         * Stochastic gradient descent
         */
        template<unsigned int num_features>
        class SGD : public AbstractClassifier<num_features> {
        public:
            /**
             *
             * @param alpha
             */
            SGD(float alpha = 0.001) :
                    _alpha(alpha) {
                _params.normalizeAlpha = false;
                _params.momentum = 0;

                for (unsigned int i = 0; i < num_features + 1; i++)
                    _weights[i] = _updates[i] = 0;
            }

            /**
             *
             * @param param
             * @param value
             */
            void set(const char *param, float value) {
                this->setParam(param, "alpha", &_alpha, value);
                this->setParam(param, "momentum", &_params.momentum, value);
                this->setParam(param, "normalize", &_params.normalizeAlpha, value > 0);
            }

            /**
             *
             */
            void normalizeLearningRate() {
                _params.normalizeAlpha = true;
            }

            /**
             *
             * @param momentum
             */
            void momentum(float momentum) {
                _params.momentum = momentum;
            }

            /**
             *
             * @param x
             * @param y
             */
            void fitOne(float x[num_features], int y) {
                int predicted = predict(x);
                int error = predicted - y;
                float alpha = _alpha;
                float updates[num_features + 1] = {0};

                if (error == 0)
                    return;

                if (_params.normalizeAlpha)
                    alpha /= 1 + _alpha * dot<num_features>(x, x);

                // compute and apply updates
                _updates[0] = (_params.momentum * _updates[0]) - (alpha * error);
                _weights[0] += _updates[0];

                for (unsigned int i = 0; i < num_features; i++) {
                    float momentum = _params.momentum * _updates[i + 1];
                    float correction = alpha * x[i] * error;

                    _updates[i + 1] = momentum - correction;
                    _weights[i + 1] += _updates[i + 1];
                }
            }

            /**
             *
             * @param x
             * @return
             */
            int predict(float x[num_features]) {
                float xx[num_features + 1] = {1};

                for (unsigned int i = 0; i < num_features; i++)
                    xx[i + 1] = x[i];

                return (1.0f / (1 + exp(-dot<num_features+1>(x, _weights)))) > 0.5 ? 1 : 0;
            }

        protected:
            float _alpha;
            float _weights[num_features + 1];
            float _updates[num_features + 1];
            struct {
                bool normalizeAlpha;
                float momentum;
            } _params;
        };
    }
}