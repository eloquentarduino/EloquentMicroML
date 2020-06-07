#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class PCA {
            public:
                /**
                * Apply dimensionality reduction
                * @warn Will override the source vector if no dest provided!
                */
                void transform(float *x, float *dest = NULL) {
                    static float u[2] = { 0 };
                    u[0] = dot(x,   0.361386591785  , -0.084522514065  , 0.85667060595  , 0.358289197152 );
                    u[1] = dot(x,   0.656588771287  , 0.730161434785  , -0.173372662796  , -0.075481019917 );
                    memcpy(dest != NULL ? dest : x, u, sizeof(float) * 2);
                }

            protected:
                /**
                * Compute dot product with varargs
                */
                float dot(float *x, ...) {
                    va_list w;
                    va_start(w, 4);
                    static float mean[] = {  5.843333333333 , 3.057333333333 , 3.758 , 1.199333333333  };
                    float dot = 0.0;

                    for (uint16_t i = 0; i < 4; i++) {
                        dot += (x[i] - mean[i]) * va_arg(w, double);
                    }

                    return dot;
                }
            };
        }
    }
}