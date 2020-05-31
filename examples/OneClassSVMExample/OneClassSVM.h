#pragma once

namespace Eloquent {
    namespace ML {
        namespace Port {
            class OneClassSVM {
            public:
                OneClassSVM() {
                }

                /**
                 * Predict class for features vector
                 */
                int predict(float *x) {
                    float kernels[103] = { 0 };
                    kernels[0] = compute_kernel(x,   2.081648079  , 2.416976782 );
                    kernels[1] = compute_kernel(x,   1.79433007  , 1.837164471 );
                    kernels[2] = compute_kernel(x,   1.995388516  , 1.14901922 );
                    kernels[3] = compute_kernel(x,   1.862821384  , 2.255965555 );
                    kernels[4] = compute_kernel(x,   2.088530558  , 2.183950831 );
                    kernels[5] = compute_kernel(x,   1.720917923  , 2.008188222 );
                    kernels[6] = compute_kernel(x,   2.108806288  , 1.801064047 );
                    kernels[7] = compute_kernel(x,   1.781646761  , 2.115410606 );
                    kernels[8] = compute_kernel(x,   2.110753564  , 1.756399603 );
                    kernels[9] = compute_kernel(x,   1.80194797  , 2.091460009 );
                    kernels[10] = compute_kernel(x,   1.76220929  , 1.659126614 );
                    kernels[11] = compute_kernel(x,   1.948884899  , 2.23334939 );
                    kernels[12] = compute_kernel(x,   1.46389555  , 2.934052651 );
                    kernels[13] = compute_kernel(x,   1.579996388  , 1.582843765 );
                    kernels[14] = compute_kernel(x,   1.985205945  , 1.869465048 );
                    kernels[15] = compute_kernel(x,   2.173248745  , 2.069327414 );
                    kernels[16] = compute_kernel(x,   2.650293485  , 1.495215265 );
                    kernels[17] = compute_kernel(x,   2.160612294  , 1.55679672 );
                    kernels[18] = compute_kernel(x,   1.963624616  , 2.406900003 );
                    kernels[19] = compute_kernel(x,   1.815162698  , 2.159282828 );
                    kernels[20] = compute_kernel(x,   1.969904504  , 1.965944482 );
                    kernels[21] = compute_kernel(x,   2.111640653  , 1.982980846 );
                    kernels[22] = compute_kernel(x,   1.576583393  , 1.872107243 );
                    kernels[23] = compute_kernel(x,   2.057858459  , 2.376426847 );
                    kernels[24] = compute_kernel(x,   1.619048574  , 2.261960119 );
                    kernels[25] = compute_kernel(x,   2.255068446  , 2.132113582 );
                    kernels[26] = compute_kernel(x,   1.341181745  , 2.686502098 );
                    kernels[27] = compute_kernel(x,   1.949245809  , 2.048934272 );
                    kernels[28] = compute_kernel(x,   2.183188207  , 1.914652138 );
                    kernels[29] = compute_kernel(x,   1.645817108  , 2.031532459 );
                    kernels[30] = compute_kernel(x,   1.934286029  , 2.043886454 );
                    kernels[31] = compute_kernel(x,   2.162413295  , 2.189314859 );
                    kernels[32] = compute_kernel(x,   2.024071339  , 1.470810491 );
                    kernels[33] = compute_kernel(x,   2.234804628  , 1.940228406 );
                    kernels[34] = compute_kernel(x,   2.087009103  , 2.054050869 );
                    kernels[35] = compute_kernel(x,   2.518966926  , 2.001222381 );
                    kernels[36] = compute_kernel(x,   2.729061074  , 1.583097433 );
                    kernels[37] = compute_kernel(x,   2.527237168  , 1.960235339 );
                    kernels[38] = compute_kernel(x,   1.823510918  , 1.749421015 );
                    kernels[39] = compute_kernel(x,   2.056878991  , 1.791454238 );
                    kernels[40] = compute_kernel(x,   1.898372129  , 1.809228787 );
                    kernels[41] = compute_kernel(x,   1.361456659  , 1.807088784 );
                    kernels[42] = compute_kernel(x,   1.58887235  , 2.804500593 );
                    kernels[43] = compute_kernel(x,   1.707850216  , 1.77460317 );
                    kernels[44] = compute_kernel(x,   2.179893976  , 1.909972513 );
                    kernels[45] = compute_kernel(x,   1.772598779  , 1.85031504 );
                    kernels[46] = compute_kernel(x,   1.77936648  , 2.220097951 );
                    kernels[47] = compute_kernel(x,   2.141393923  , 1.602564934 );
                    kernels[48] = compute_kernel(x,   2.319060201  , 2.078959749 );
                    kernels[49] = compute_kernel(x,   1.934328157  , 1.47532657 );
                    kernels[50] = compute_kernel(x,   2.135892335  , 1.826700798 );
                    kernels[51] = compute_kernel(x,   1.738609972  , 2.389921252 );
                    kernels[52] = compute_kernel(x,   1.849065396  , 1.773402741 );
                    kernels[53] = compute_kernel(x,   -1.974541276  , -2.394569985 );
                    kernels[54] = compute_kernel(x,   -2.20566993  , -2.162835529 );
                    kernels[55] = compute_kernel(x,   -2.004611484  , -2.85098078 );
                    kernels[56] = compute_kernel(x,   -2.109130391  , -2.296375504 );
                    kernels[57] = compute_kernel(x,   -2.525269114  , -2.107003397 );
                    kernels[58] = compute_kernel(x,   -2.279082077  , -1.991811778 );
                    kernels[59] = compute_kernel(x,   -1.891193712  , -2.198935953 );
                    kernels[60] = compute_kernel(x,   -2.218353239  , -1.884589394 );
                    kernels[61] = compute_kernel(x,   -2.384303916  , -2.195291289 );
                    kernels[62] = compute_kernel(x,   -2.484930309  , -2.259952145 );
                    kernels[63] = compute_kernel(x,   -1.889246436  , -2.243600397 );
                    kernels[64] = compute_kernel(x,   -2.19805203  , -1.908539991 );
                    kernels[65] = compute_kernel(x,   -2.23779071  , -2.340873386 );
                    kernels[66] = compute_kernel(x,   -2.53610445  , -1.065947349 );
                    kernels[67] = compute_kernel(x,   -1.848339171  , -2.605966599 );
                    kernels[68] = compute_kernel(x,   -2.420003612  , -2.417156235 );
                    kernels[69] = compute_kernel(x,   -1.804209994  , -2.238867466 );
                    kernels[70] = compute_kernel(x,   -2.014794055  , -2.130534952 );
                    kernels[71] = compute_kernel(x,   -2.785716978  , -2.086395722 );
                    kernels[72] = compute_kernel(x,   -2.522697742  , -1.917692521 );
                    kernels[73] = compute_kernel(x,   -2.246350837  , -1.784573199 );
                    kernels[74] = compute_kernel(x,   -1.920500584  , -2.419735102 );
                    kernels[75] = compute_kernel(x,   -1.839387706  , -2.44320328 );
                    kernels[76] = compute_kernel(x,   -2.184837302  , -1.840717172 );
                    kernels[77] = compute_kernel(x,   -2.030095496  , -2.034055518 );
                    kernels[78] = compute_kernel(x,   -2.218454814  , -2.369859939 );
                    kernels[79] = compute_kernel(x,   -2.423416607  , -2.127892757 );
                    kernels[80] = compute_kernel(x,   -2.380951426  , -1.738039881 );
                    kernels[81] = compute_kernel(x,   -2.658818255  , -1.313497902 );
                    kernels[82] = compute_kernel(x,   -1.839385728  , -2.20085493 );
                    kernels[83] = compute_kernel(x,   -2.354182892  , -1.968467541 );
                    kernels[84] = compute_kernel(x,   -2.369824595  , -1.948891695 );
                    kernels[85] = compute_kernel(x,   -2.352728376  , -2.003333791 );
                    kernels[86] = compute_kernel(x,   -2.358150622  , -2.256508317 );
                    kernels[87] = compute_kernel(x,   -1.975928661  , -2.529189509 );
                    kernels[88] = compute_kernel(x,   -2.503715876  , -2.453924977 );
                    kernels[89] = compute_kernel(x,   -2.176489082  , -2.250578985 );
                    kernels[90] = compute_kernel(x,   -1.943121009  , -2.208545762 );
                    kernels[91] = compute_kernel(x,   -2.101627871  , -2.190771213 );
                    kernels[92] = compute_kernel(x,   -2.638543341  , -2.192911216 );
                    kernels[93] = compute_kernel(x,   -2.31054141  , -2.283292726 );
                    kernels[94] = compute_kernel(x,   -2.292149784  , -2.22539683 );
                    kernels[95] = compute_kernel(x,   -2.154025649  , -2.110703002 );
                    kernels[96] = compute_kernel(x,   -2.227401221  , -2.14968496 );
                    kernels[97] = compute_kernel(x,   -1.858606077  , -2.397435066 );
                    kernels[98] = compute_kernel(x,   -2.000438757  , -2.300489977 );
                    kernels[99] = compute_kernel(x,   -2.065671843  , -2.52467343 );
                    kernels[100] = compute_kernel(x,   -1.864107665  , -2.173299202 );
                    kernels[101] = compute_kernel(x,   -2.320107091  , -1.902360513 );
                    kernels[102] = compute_kernel(x,   -2.150934604  , -2.226597259 );
                    float decision = -1.05e-06 - ( + kernels[0]   + kernels[1]   + kernels[2]   + kernels[3]   + kernels[4]   + kernels[5] * 0.6564548  + kernels[6]   + kernels[7]   + kernels[8]   + kernels[9]   + kernels[10]   + kernels[11]   + kernels[12]   + kernels[13]   + kernels[14]   + kernels[15]   + kernels[16]   + kernels[17]   + kernels[18]   + kernels[19]   + kernels[20]   + kernels[21]   + kernels[22]   + kernels[23]   + kernels[24]   + kernels[25]   + kernels[26]   + kernels[27]   + kernels[28]   + kernels[29]   + kernels[30]   + kernels[31]   + kernels[32]   + kernels[33]   + kernels[34]   + kernels[35]   + kernels[36]   + kernels[37] * 0.999600007  + kernels[38]   + kernels[39]   + kernels[40]   + kernels[41]   + kernels[42]   + kernels[43]   + kernels[44]   + kernels[45]   + kernels[46]   + kernels[47]   + kernels[48]   + kernels[49]   + kernels[50]   + kernels[51]   + kernels[52]   + kernels[53]   + kernels[54]   + kernels[55]   + kernels[56]   + kernels[57]   + kernels[58]   + kernels[59]   + kernels[60]   + kernels[61]   + kernels[62]   + kernels[63]   + kernels[64]   + kernels[65]   + kernels[66] * 0.007927676  + kernels[67]   + kernels[68]   + kernels[69] * 0.992072324  + kernels[70]   + kernels[71]   + kernels[72]   + kernels[73]   + kernels[74]   + kernels[75]   + kernels[76] * 0.3435452  + kernels[77]   + kernels[78]   + kernels[79]   + kernels[80]   + kernels[81] * 0.000399993  + kernels[82]   + kernels[83]   + kernels[84]   + kernels[85]   + kernels[86]   + kernels[87]   + kernels[88]   + kernels[89]   + kernels[90]   + kernels[91]   + kernels[92]   + kernels[93]   + kernels[94]   + kernels[95]   + kernels[96]   + kernels[97]   + kernels[98]   + kernels[99]   + kernels[100]   + kernels[101]   + kernels[102]  );
                    return decision > 0 ? 0 : 1;
                }

            protected:
                /**
                * Compute kernel between feature vector and support vector.
                * Kernel type: linear
                */
                float compute_kernel(float x[2], ...) {
                    va_list w;
                    va_start(w, 2);
                    float kernel = 0.0;
                    for (uint16_t i = 0; i < 2; i++) {
                        kernel += x[i] * va_arg(w, double);
                    }
                    return kernel;
                }
            };
        }
    }
}