#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[2] <= -41.5) {
                            return 3;
                        }

                        else {
                            if (x[6] <= 25.0) {
                                if (x[5] <= 50.0) {
                                    return 2;
                                }

                                else {
                                    return 1;
                                }
                            }

                            else {
                                return 0;
                            }
                        }
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* predictLabel(float *x) {
                        switch (predict(x)) {
                            case 0:
                            return "Bathroom";
                            case 1:
                            return "Bedroom";
                            case 2:
                            return "Kitchen";
                            case 3:
                            return "kitchen";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                };
            }
        }
    }
