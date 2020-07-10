#pragma once

namespace Eloquent {
    namespace ML {

        /**
         * SEFR: A Fast Linear-Time Classifier for Ultra-LowPower Devices
         * @see https://arxiv.org/pdf/2006.04620.pdf
         * @tparam numFetures
         */
        template<uint16_t numFetures>
        class SEFR {
        public:

            /**
             *
             */
            SEFR() {
                reset();
            }

            /**
             * Set all weights to 0
             */
            void reset() {
                _bias = 0;

                for (uint16_t i = 0; i < numFetures; i++)
                    _weights[i] = 0;
            }

            /**
             * Train classifier on give dataset
             * @param X
             * @param y
             */
            void fit(float X[][numFetures], int *y, uint16_t numSamples) {
                uint16_t positiveSamples = 0;
                uint16_t negativeSamples = 0;
                float positiveFeatures[numFetures] = {0};
                float negativeFeatures[numFetures] = {0};

                // accumulate positive and negative features
                for (uint16_t i = 0; i < numSamples; i++) {
                    Serial.println(i);

                    if (y[i] > 0) {
                        positiveSamples += 1;

                        for (uint16_t j = 0; j < numFetures; j++)
                            positiveFeatures[j] += X[i][j];
                    }
                    else {
                        negativeSamples += 1;

                        for (uint16_t j = 0; j < numFetures; j++)
                            negativeFeatures[j] += X[i][j];
                    }
                }

                Serial.println("#1");

                // compute weights
                for (uint16_t j = 0; j < numFetures; j++) {
                    positiveFeatures[j] /= positiveSamples;
                    negativeFeatures[j] /= negativeSamples;

                    float sum = positiveFeatures[j] + negativeFeatures[j];

                    _weights[j] = (sum != 0) ? (positiveFeatures[j] - negativeFeatures[j]) / sum : 0;
                }

                // compute bias
                float positiveTau = 0;
                float negativeTau = 0;

                for (uint16_t i = 0; i < numSamples; i++) {
                    float sampleScore = score(X[i]);

                    if (y[i] > 0)
                        positiveTau += sampleScore;
                    else
                        negativeTau += sampleScore;
                }

                positiveTau /= positiveSamples;
                negativeTau /= negativeSamples;

                _bias = - ((positiveTau * negativeSamples) + (negativeTau * positiveSamples)) / numSamples;
            }

            /**
             * Classify sample
             * @param x
             * @return
             */
            int predict(float *x) {
                return score(x) > -_bias ? 1 : 0;
            }


        protected:
            float _bias;
            float _weights[numFetures];

            /**
             * Compute score of sample
             * @param x
             * @return
             */
            float score(float *x) {
                float dot = 0;

                for (uint16_t j = 0; j < numFetures; j++)
                    dot += x[j] * _weights[j];

                return dot;
            }
        };
    }
}