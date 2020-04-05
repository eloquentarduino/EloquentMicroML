#pragma once

#ifdef ESP32
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define abs(x) ((x) > 0 ? (x) : -(x))
#endif

namespace Eloquent {
    namespace ML {

        /**
         * Dot product
         * @tparam size
         * @param x
         * @param w
         * @return
         */
        template<unsigned int size>
        float dot(float x[size], float w[size]) {
            float sum = 0;

            for (unsigned int i = 0; i < size; i++)
                sum += x[i] * w[i];

            return sum;
        }
    }
}