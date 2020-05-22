#pragma once

#include "EloquentAbstractClassifier.h"

namespace Eloquent {
    namespace ML {
        /**
         *
         * @tparam T
         * @tparam numFeatures
         */
        template<typename T, uint16_t numFeatures>
        class CsvReader {
        public:
            CsvReader(const char separator = ',') :
                    _separator(separator) {

            }

            /**
             *
             */
            void begin(File& file) {
                _file = file;
                _file.seek(0);
            }

            /**
             *
             */
            void close() {
                if (_file)
                    _file.close();
            }

            /**
             * Read the next line as array
             */
            bool next(T features[numFeatures + 1], int *label) {
                if (!_file || !_file.available())
                    return false;

                for (int i = 0; i < numFeatures; i++)
                    features[i] = (T) _file.readStringUntil(_separator).toFloat();

                *label = _file.readStringUntil('\n').toFloat();

                return true;
            }

            /**
             * Use the contents of the file as samples for a classifier
             * @param file
             * @param clf
             * @param repeat
             */
            void fit(File& file, AbstractClassifier<numFeatures> *clf, uint8_t repeat = 1) {
                T features[numFeatures];
                int label;

                for (uint8_t k = 0; k < repeat; k++) {
                    begin(file);

                    while ((next(features, &label)))
                        clf->fitOne(features, label);

                    close();
                }
            }

        protected:
            const char _separator;
            File _file;
        };
    }
}