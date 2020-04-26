#pragma once

#include <string.h>


namespace Eloquent {
    namespace ML {
        template<unsigned int num_features>
        class AbstractClassifier {
        public:
            /**
             *
             * @param x
             * @param y
             */
            virtual void fitOne(float x[num_features], int y) = 0;

            /**
             *
             * @param x
             * @return
             */
            virtual int predict(float x[num_features]) = 0;

            /**
             * Update classifier parameter.
             * Implementation specific
             * @param param
             * @param value
             */
            virtual void set(const char *param, float value) {

            }

        protected:
            /**
             *
             * @param paramName
             * @param targetName
             * @param param
             * @param value
             */
            template<typename T>
            void setParam(const char *paramName, const char* targetName, T *param, T value) {
                if (strcmp(paramName, targetName) == 0)
                    *param = value;
            }
        };
    }
}