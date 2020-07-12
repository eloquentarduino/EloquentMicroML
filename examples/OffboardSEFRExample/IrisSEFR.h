#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SEFR {
            public:
                /**
                * Predict class for features vector
                */
                int predict(float *x) {
                    return dot(x,   -0.033926433731  , -0.22068374821  , 0.391616088384  , 0.619492582103 ) <= 0.08944621779720162 ? 0 : 1;
                }

            protected:
                /**
                * Compute dot product between features vector and classifier weights
                */
                float dot(float *x, ...) {
                    va_list w;
                    va_start(w, 4);
                    float kernel = 0.0;

                    for (uint16_t i = 0; i < 4; i++) {
                        kernel += x[i] * va_arg(w, double);
                    }

                    return kernel;
                }
            };
        }
    }
}