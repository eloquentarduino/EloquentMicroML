#pragma once

#include "EloquentFeatureVector.h"

namespace Eloquent {
    namespace ML {
        template<uint16_t vectorSize, uint16_t windowSize>
        class Window : public FeatureVector<vectorSize> {
        public:

            /**
             * Test if window is full
             * @return
             */
            bool isFull() {
                if (!FeatureVector<vectorSize>::isFull())
                    return false;

                return (FeatureVector<vectorSize>::length() % windowSize) == 0;
            }

            /**
             * Window cannot be endless
             * @param endless
             */
            void endless(bool endless = true) {

            }

            /**
             *
             */
            void slide() {
                memcpy(FeatureVector<vectorSize>::_array, FeatureVector<vectorSize>::_array + windowSize, sizeof(float) * windowSize);
                FeatureVector<vectorSize>::_count = windowSize;

                // zero the remaining elements
                for (uint16_t i = windowSize; i < vectorSize; i++)
                    FeatureVector<vectorSize>::_array[i] = 0;
            }

        };
    }
}