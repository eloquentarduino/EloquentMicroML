#pragma once


namespace Eloquent {
    namespace ML {
        /**
         * Compute accuracy of predictions
         */
        class AccuracyScorer {
        public:
            AccuracyScorer() :
                    _tp(0),
                    _tn(0),
                    _fp(0),
                    _fn(0) {

            }

            /**
             *
             * @param actual
             * @param predicted
             */
            void scoreOne(int actual, int predicted) {
                if (predicted > 0 && predicted == actual)
                    _tp++;
                else if (predicted > 0 && predicted != actual)
                    _fp++;
                else if (predicted <= 0 && predicted == actual)
                    _tn++;
                else
                    _fn++;
            }

            /**
             *
             * @return
             */
            float accuracy() {
                return (1.0f * _tp + _tn) / support();
            }

            /**
             *
             * @return
             */
            unsigned int support() {
                return _tp + _tn + _fp + _fn;
            }

        protected:
            unsigned int _tp;
            unsigned int _tn;
            unsigned int _fp;
            unsigned int _fn;
        };
    }
}