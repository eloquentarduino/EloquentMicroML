#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class GaussianNB {
            public:
                /**
                * Predict class for features vector
                */
                int predict(float *x) {
                    float votes[3] = { 0.0f };
                    float theta[4] = { 0 };
                    float sigma[4] = { 0 };
                    theta[0] = 5.006; theta[1] = 3.428; theta[2] = 1.462; theta[3] = 0.246;
                    sigma[0] = 0.121794955027; sigma[1] = 0.140846955027; sigma[2] = 0.029586955027; sigma[3] = 0.010914955027;
                    votes[0] = 0.333333333333 - gauss(x, theta, sigma);
                    theta[0] = 5.936; theta[1] = 2.77; theta[2] = 4.26; theta[3] = 1.326;
                    sigma[0] = 0.261134955027; sigma[1] = 0.096530955027; sigma[2] = 0.216430955027; sigma[3] = 0.038354955027;
                    votes[1] = 0.333333333333 - gauss(x, theta, sigma);
                    theta[0] = 6.588; theta[1] = 2.974; theta[2] = 5.552; theta[3] = 2.026;
                    sigma[0] = 0.396286955027; sigma[1] = 0.101954955027; sigma[2] = 0.298526955027; sigma[3] = 0.073954955027;
                    votes[2] = 0.333333333333 - gauss(x, theta, sigma);
                    // return argmax of votes
                    uint8_t classIdx = 0;
                    float maxVotes = votes[0];

                    for (uint8_t i = 1; i < 3; i++) {
                        if (votes[i] > maxVotes) {
                            classIdx = i;
                            maxVotes = votes[i];
                        }
                    }

                    return classIdx;
                }

            protected:
                /**
                * Compute gaussian value
                */
                float gauss(float *x, float *theta, float *sigma) {
                    float gauss = 0.0f;

                    for (uint16_t i = 0; i < 4; i++) {
                        gauss += log(sigma[i]);
                        gauss += pow(x[i] - theta[i], 2) / sigma[i];
                    }

                    return gauss;
                }
            };
        }
    }
}