#pragma once

namespace Eloquent {
    namespace ML {

        /**
         *
         */
        typedef float (*kernelFunction)(float *x, float *w, unsigned int dimension);

        /**
         *
         * @param x
         * @param w
         * @param dimension
         * @return
         */
        float linearKernel(float *x, float *w, unsigned int dimension) {
            float sum = 0;

            for (unsigned int i = 0; i < dimension; i++)
                sum += x[i] * w[i];

            return sum;
        }

        /**
         * This really is a bad hack, but it's the most straightforward
         * implementation I could come up with
         * @param x
         * @param w
         * @param dimension
         * @return
         */
#if defined(KERNEL_GAMMA)
        float rbfKernel(float *x, float *w, unsigned int dimension) {
            float sum = 0;

            for(unsigned int i = 0; i < dimension; i++)
                sum += (x[i] - w[i]) * (x[i] - w[i]);

            return exp(-sum / (2 * KERNEL_GAMMA * KERNEL_GAMMA));
        }
#endif

    }
}