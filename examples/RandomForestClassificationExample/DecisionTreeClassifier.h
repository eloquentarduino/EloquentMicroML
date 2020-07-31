#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTreeClassifier {
            public:
                /**
                * Predict class for features vector
                */
                int predict(float *x) {
                    if (x[20] <= 16.795000076293945) {
                        if (x[27] <= 0.13580000400543213) {
                            if (x[13] <= 48.97500038146973) {
                                if (x[23] <= 785.75) {
                                    if (x[21] <= 33.35000038146973) {
                                        return 1;
                                    }

                                    else {
                                        if (x[24] <= 0.13410000503063202) {
                                            return 1;
                                        }

                                        else {
                                            return 1;
                                        }
                                    }
                                }

                                else {
                                    if (x[20] <= 16.214999198913574) {
                                        return 1;
                                    }

                                    else {
                                        return 1;
                                    }
                                }
                            }

                            else {
                                return 1;
                            }
                        }

                        else {
                            if (x[21] <= 25.670000076293945) {
                                if (x[23] <= 805.8999938964844) {
                                    if (x[24] <= 0.15075000375509262) {
                                        return 1;
                                    }

                                    else {
                                        return 1;
                                    }
                                }

                                else {
                                    return 0;
                                }
                            }

                            else {
                                if (x[6] <= 0.09679000079631805) {
                                    return 0;
                                }

                                else {
                                    return 0;
                                }
                            }
                        }
                    }

                    else {
                        if (x[1] <= 16.109999656677246) {
                            if (x[7] <= 0.06625999882817268) {
                                return 1;
                            }

                            else {
                                return 0;
                            }
                        }

                        else {
                            if (x[26] <= 0.190700002014637) {
                                return 0;
                            }

                            else {
                                return 0;
                            }
                        }
                    }
                }
            };
        }
    }
}