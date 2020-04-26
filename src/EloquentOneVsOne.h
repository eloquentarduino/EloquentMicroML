#pragma once


namespace Eloquent {
    namespace ML {

        template<class Classifier, int numFeatures, int numClasses>
        class OneVsOne : AbstractClassifier<numFeatures> {
        public:
            /**
             *
             * @param classifierGenerator
             */
            OneVsOne() {
                for (int i = 0; i < numClassifiers(); i++)
                    _classifiers[i] = new Classifier();
            }

            /**
             *
             * @param x
             * @param y
             */
            void fitOne(float x[numFeatures], int y) {
                int k = 0;

                for (int i = 0; i < numClasses - 1; i++) {
                    for (int j = i + 1; j < numClasses; j++) {
                        if (i == y || j == y) {
                            _classifiers[k]->fitOne(x, y == i ? 1 : 0);
                        }
                        k++;
                    }
                }
            }

            /**
             * Predict by votes
             * @param x
             * @return
             */
            int predict(float x[numFeatures]) {
                int k = 0;
                int votes[numClasses] = {0};

                for (int i = 0; i < numClasses - 1; i++) {
                    for (int j = i + 1; j < numClasses; j++) {
                        int y_pred = _classifiers[k]->predict(x);
                        votes[y_pred > 0 ? i : j] += 1;
                        k++;
                    }
                }

                // pick class with most votes
                int maxVotes = -1;
                int classIdx = -1;

                for (int i = 0; i < numClasses; i++) {
                    if (votes[i] > maxVotes) {
                        maxVotes = votes[i];
                        classIdx = i;
                    }
                }

                return classIdx;
            }

            /**
             *
             * @param param
             * @param value
             */
            void set(const char *param, float value) {
                for (int i = 0; i < numClassifiers(); i++)
                    _classifiers[i]->set(param, value);
            }

        protected:
            Classifier *_classifiers[numClasses * (numClasses - 1) / 2];

            /**
             *
             * @return
             */
            int numClassifiers() {
                return numClasses * (numClasses - 1) / 2;
            }
        };
    }
}

