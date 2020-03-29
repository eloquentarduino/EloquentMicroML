#define FEATURES_DIM 30
#define POSITIVE_SAMPLES 40
#define NEGATIVE_SAMPLES 40

float X_positive[POSITIVE_SAMPLES][FEATURES_DIM] = {
        {13.540000,14.360000,87.460000,566.300000,0.097790,0.081290,0.066640,0.047810,0.188500,0.057660,0.269900,0.788600,2.058000,23.560000,0.008462,0.014600,0.023870,0.013150,0.019800,0.002300,15.110000,19.260000,99.700000,711.200000,0.144000,0.177300,0.239000,0.128800,0.297700,0.072590},
        {13.080000,15.710000,85.630000,520.000000,0.107500,0.127000,0.045680,0.031100,0.196700,0.068110,0.185200,0.747700,1.383000,14.670000,0.004097,0.018980,0.016980,0.006490,0.016780,0.002425,14.500000,20.490000,96.090000,630.500000,0.131200,0.277600,0.189000,0.072830,0.318400,0.081830},
        {9.504000,12.440000,60.340000,273.900000,0.102400,0.064920,0.029560,0.020760,0.181500,0.069050,0.277300,0.976800,1.909000,15.700000,0.009606,0.014320,0.019850,0.014210,0.020270,0.002968,10.230000,15.660000,65.130000,314.900000,0.132400,0.114800,0.088670,0.062270,0.245000,0.077730},
        {13.030000,18.420000,82.610000,523.800000,0.089830,0.037660,0.025620,0.029230,0.146700,0.058630,0.183900,2.342000,1.170000,14.160000,0.004352,0.004899,0.013430,0.011640,0.026710,0.001777,13.300000,22.810000,84.460000,545.900000,0.097010,0.046190,0.048330,0.050130,0.198700,0.061690},
        {8.196000,16.840000,51.710000,201.900000,0.086000,0.059430,0.015880,0.005917,0.176900,0.065030,0.156300,0.956700,1.094000,8.205000,0.008968,0.016460,0.015880,0.005917,0.025740,0.002582,8.964000,21.960000,57.260000,242.200000,0.129700,0.135700,0.068800,0.025640,0.310500,0.074090},
        {12.050000,14.630000,78.040000,449.300000,0.103100,0.090920,0.065920,0.027490,0.167500,0.060430,0.263600,0.729400,1.848000,19.870000,0.005488,0.014270,0.023220,0.005660,0.014280,0.002422,13.760000,20.700000,89.880000,582.600000,0.149400,0.215600,0.305000,0.065480,0.274700,0.083010},
        {13.490000,22.300000,86.910000,561.000000,0.087520,0.076980,0.047510,0.033840,0.180900,0.057180,0.233800,1.353000,1.735000,20.200000,0.004455,0.013820,0.020950,0.011840,0.016410,0.001956,15.150000,31.820000,99.000000,698.800000,0.116200,0.171100,0.228200,0.128200,0.287100,0.069170},
        {11.760000,21.600000,74.720000,427.900000,0.086370,0.049660,0.016570,0.011150,0.149500,0.058880,0.406200,1.210000,2.635000,28.470000,0.005857,0.009758,0.011680,0.007445,0.024060,0.001769,12.980000,25.720000,82.980000,516.500000,0.108500,0.086150,0.055230,0.037150,0.243300,0.065630},
        {13.640000,16.340000,87.210000,571.800000,0.076850,0.060590,0.018570,0.017230,0.135300,0.059530,0.187200,0.923400,1.449000,14.550000,0.004477,0.011770,0.010790,0.007956,0.013250,0.002551,14.670000,23.190000,96.080000,656.700000,0.108900,0.158200,0.105000,0.085860,0.234600,0.080250},
        {11.940000,18.240000,75.710000,437.600000,0.082610,0.047510,0.019720,0.013490,0.186800,0.061100,0.227300,0.632900,1.520000,17.470000,0.007210,0.008380,0.013110,0.008000,0.019960,0.002635,13.100000,21.330000,83.670000,527.200000,0.114400,0.089060,0.092030,0.062960,0.278500,0.074080},
        {11.520000,18.750000,73.340000,409.000000,0.095240,0.054730,0.030360,0.022780,0.192000,0.059070,0.324900,0.959100,2.183000,23.470000,0.008328,0.008722,0.013490,0.008670,0.032180,0.002386,12.840000,22.470000,81.810000,506.200000,0.124900,0.087200,0.090760,0.063160,0.330600,0.070360},
        {13.050000,19.310000,82.610000,527.200000,0.080600,0.037890,0.000692,0.004167,0.181900,0.055010,0.404000,1.214000,2.595000,32.960000,0.007491,0.008593,0.000692,0.004167,0.021900,0.002990,14.230000,22.250000,90.240000,624.100000,0.102100,0.061910,0.001845,0.011110,0.243900,0.062890},
        {8.618000,11.790000,54.340000,224.500000,0.097520,0.052720,0.020610,0.007799,0.168300,0.071870,0.155900,0.579600,1.046000,8.322000,0.010110,0.010550,0.019810,0.005742,0.020900,0.002788,9.507000,15.400000,59.900000,274.900000,0.173300,0.123900,0.116800,0.044190,0.322000,0.090260},
        {10.170000,14.880000,64.550000,311.900000,0.113400,0.080610,0.010840,0.012900,0.274300,0.069600,0.515800,1.441000,3.312000,34.620000,0.007514,0.010990,0.007665,0.008193,0.041830,0.005953,11.020000,17.450000,69.860000,368.600000,0.127500,0.098660,0.021680,0.025790,0.355700,0.080200},
        {8.598000,20.980000,54.660000,221.800000,0.124300,0.089630,0.030000,0.009259,0.182800,0.067570,0.358200,2.067000,2.493000,18.390000,0.011930,0.031620,0.030000,0.009259,0.033570,0.003048,9.565000,27.040000,62.060000,273.900000,0.163900,0.169800,0.090010,0.027780,0.297200,0.077120},
        {9.173000,13.860000,59.200000,260.900000,0.077210,0.087510,0.059880,0.021800,0.234100,0.069630,0.409800,2.265000,2.608000,23.520000,0.008738,0.039380,0.043120,0.015600,0.041920,0.005822,10.010000,19.230000,65.590000,310.100000,0.098360,0.167800,0.139700,0.050870,0.328200,0.084900},
        {9.465000,21.010000,60.110000,269.400000,0.104400,0.077730,0.021720,0.015040,0.171700,0.068990,0.235100,2.011000,1.660000,14.200000,0.010520,0.017550,0.017140,0.009333,0.022790,0.004237,10.410000,31.560000,67.030000,330.700000,0.154800,0.166400,0.094120,0.065170,0.287800,0.092110},
        {11.310000,19.040000,71.800000,394.100000,0.081390,0.047010,0.037090,0.022300,0.151600,0.056670,0.272700,0.942900,1.831000,18.150000,0.009282,0.009216,0.020630,0.008965,0.021830,0.002146,12.330000,23.840000,78.000000,466.700000,0.129000,0.091480,0.144400,0.069610,0.240000,0.066410},
        {9.029000,17.330000,58.790000,250.500000,0.106600,0.141300,0.313000,0.043750,0.211100,0.080460,0.327400,1.194000,1.885000,17.670000,0.009549,0.086060,0.303800,0.033220,0.041970,0.009559,10.310000,22.650000,65.500000,324.700000,0.148200,0.436500,1.252000,0.175000,0.422800,0.117500},
        {12.780000,16.490000,81.370000,502.500000,0.098310,0.052340,0.036530,0.028640,0.159000,0.056530,0.236800,0.873200,1.471000,18.330000,0.007962,0.005612,0.015850,0.008662,0.022540,0.001906,13.460000,19.760000,85.670000,554.900000,0.129600,0.070610,0.103900,0.058820,0.238300,0.064100},
        {8.888000,14.640000,58.790000,244.000000,0.097830,0.153100,0.086060,0.028720,0.190200,0.089800,0.526200,0.852200,3.168000,25.440000,0.017210,0.093680,0.056710,0.017660,0.025410,0.021930,9.733000,15.670000,62.560000,284.400000,0.120700,0.243600,0.143400,0.047860,0.225400,0.108400},
        {12.310000,16.520000,79.190000,470.900000,0.091720,0.068290,0.033720,0.022720,0.172000,0.059140,0.250500,1.025000,1.740000,19.680000,0.004854,0.018190,0.018260,0.007965,0.013860,0.002304,14.110000,23.210000,89.710000,611.100000,0.117600,0.184300,0.170300,0.086600,0.261800,0.076090},
        {13.530000,10.940000,87.910000,559.200000,0.129100,0.104700,0.068770,0.065560,0.240300,0.066410,0.410100,1.014000,2.652000,32.650000,0.013400,0.028390,0.011620,0.008239,0.025720,0.006164,14.080000,12.490000,91.360000,605.500000,0.145100,0.137900,0.085390,0.074070,0.271000,0.071910},
        {12.860000,18.000000,83.190000,506.300000,0.099340,0.095460,0.038890,0.023150,0.171800,0.059970,0.265500,1.095000,1.778000,20.350000,0.005293,0.016610,0.020710,0.008179,0.017480,0.002848,14.240000,24.820000,91.880000,622.100000,0.128900,0.214100,0.173100,0.079260,0.277900,0.079180},
        {11.450000,20.970000,73.810000,401.500000,0.110200,0.093620,0.045910,0.022330,0.184200,0.070050,0.325100,2.174000,2.077000,24.620000,0.010370,0.017060,0.025860,0.007506,0.018160,0.003976,13.110000,32.160000,84.530000,525.100000,0.155700,0.167600,0.175500,0.061270,0.276200,0.088510},
        {13.340000,15.860000,86.490000,520.000000,0.107800,0.153500,0.116900,0.069870,0.194200,0.069020,0.286000,1.016000,1.535000,12.960000,0.006794,0.035750,0.039800,0.013830,0.021340,0.004603,15.530000,23.190000,96.660000,614.900000,0.153600,0.479100,0.485800,0.170800,0.352700,0.101600},
        {12.000000,15.650000,76.950000,443.300000,0.097230,0.071650,0.041510,0.018630,0.207900,0.059680,0.227100,1.255000,1.441000,16.160000,0.005969,0.018120,0.020070,0.007027,0.019720,0.002607,13.670000,24.900000,87.780000,567.900000,0.137700,0.200300,0.226700,0.076320,0.337900,0.079240},
        {12.360000,21.800000,79.780000,466.100000,0.087720,0.094450,0.060150,0.037450,0.193000,0.064040,0.297800,1.502000,2.203000,20.950000,0.007112,0.024930,0.027030,0.012930,0.019580,0.004463,13.830000,30.500000,91.460000,574.700000,0.130400,0.246300,0.243400,0.120500,0.297200,0.092610},
        {14.640000,15.240000,95.770000,651.900000,0.113200,0.133900,0.099660,0.070640,0.211600,0.063460,0.511500,0.737200,3.814000,42.760000,0.005508,0.044120,0.044360,0.016230,0.024270,0.004841,16.340000,18.240000,109.400000,803.600000,0.127700,0.308900,0.260400,0.139700,0.315100,0.084730},
        {14.620000,24.020000,94.570000,662.700000,0.089740,0.086060,0.031020,0.029570,0.168500,0.058660,0.372100,1.111000,2.279000,33.760000,0.004868,0.018180,0.011210,0.008606,0.020850,0.002893,16.110000,29.110000,102.900000,803.700000,0.111500,0.176600,0.091890,0.069460,0.252200,0.072460},
        {13.270000,14.760000,84.740000,551.700000,0.073550,0.050550,0.032610,0.026480,0.138600,0.053180,0.405700,1.153000,2.701000,36.350000,0.004481,0.010380,0.013580,0.010820,0.010690,0.001435,16.360000,22.350000,104.500000,830.600000,0.100600,0.123800,0.135000,0.100100,0.202700,0.062060},
        {13.450000,18.300000,86.600000,555.100000,0.102200,0.081650,0.039740,0.027800,0.163800,0.057100,0.295000,1.373000,2.099000,25.220000,0.005884,0.014910,0.018720,0.009366,0.018840,0.001817,15.100000,25.940000,97.590000,699.400000,0.133900,0.175100,0.138100,0.079110,0.267800,0.066030},
        {12.180000,17.840000,77.790000,451.100000,0.104500,0.070570,0.024900,0.029410,0.190000,0.066350,0.366100,1.511000,2.410000,24.440000,0.005433,0.011790,0.011310,0.015190,0.022200,0.003408,12.830000,20.920000,82.140000,495.200000,0.114000,0.093580,0.049800,0.058820,0.222700,0.073760},
        {9.787000,19.940000,62.110000,294.500000,0.102400,0.053010,0.006829,0.007937,0.135000,0.068900,0.335000,2.043000,2.132000,20.050000,0.011130,0.014630,0.005308,0.005250,0.018010,0.005667,10.920000,26.290000,68.810000,366.100000,0.131600,0.094730,0.020490,0.023810,0.193400,0.089880},
        {11.600000,12.840000,74.340000,412.600000,0.089830,0.075250,0.041960,0.033500,0.162000,0.065820,0.231500,0.539100,1.475000,15.750000,0.006153,0.013300,0.016930,0.006884,0.016510,0.002551,13.060000,17.160000,82.960000,512.500000,0.143100,0.185100,0.192200,0.084490,0.277200,0.087560},
        {6.981000,13.430000,43.790000,143.500000,0.117000,0.075680,0.000000,0.000000,0.193000,0.078180,0.224100,1.508000,1.553000,9.833000,0.010190,0.010840,0.000000,0.000000,0.026590,0.004100,7.930000,19.540000,50.410000,185.200000,0.158400,0.120200,0.000000,0.000000,0.293200,0.093820},
        {12.180000,20.520000,77.220000,458.700000,0.080130,0.040380,0.023830,0.017700,0.173900,0.056770,0.192400,1.571000,1.183000,14.680000,0.005080,0.006098,0.010690,0.006797,0.014470,0.001532,13.340000,32.840000,84.580000,547.800000,0.112300,0.088620,0.114500,0.074310,0.269400,0.068780},
        {9.876000,19.400000,63.950000,298.300000,0.100500,0.096970,0.061540,0.030290,0.194500,0.063220,0.180300,1.222000,1.528000,11.770000,0.009058,0.021960,0.030290,0.011120,0.016090,0.003570,10.760000,26.830000,72.220000,361.200000,0.155900,0.230200,0.264400,0.097490,0.262200,0.084900},
        {10.490000,19.290000,67.410000,336.100000,0.099890,0.085780,0.029950,0.012010,0.221700,0.064810,0.355000,1.534000,2.302000,23.130000,0.007595,0.022190,0.028800,0.008614,0.027100,0.003451,11.540000,23.310000,74.220000,402.800000,0.121900,0.148600,0.079870,0.032030,0.282600,0.075520},
        {11.640000,18.330000,75.170000,412.500000,0.114200,0.101700,0.070700,0.034850,0.180100,0.065200,0.306000,1.657000,2.155000,20.620000,0.008540,0.023100,0.029450,0.013980,0.015650,0.003840,13.140000,29.260000,85.510000,521.700000,0.168800,0.266000,0.287300,0.121800,0.280600,0.090970},
};

float X_negative[NEGATIVE_SAMPLES][FEATURES_DIM] = {
        {17.990000,10.380000,122.800000,1001.000000,0.118400,0.277600,0.300100,0.147100,0.241900,0.078710,1.095000,0.905300,8.589000,153.400000,0.006399,0.049040,0.053730,0.015870,0.030030,0.006193,25.380000,17.330000,184.600000,2019.000000,0.162200,0.665600,0.711900,0.265400,0.460100,0.118900},
        {20.570000,17.770000,132.900000,1326.000000,0.084740,0.078640,0.086900,0.070170,0.181200,0.056670,0.543500,0.733900,3.398000,74.080000,0.005225,0.013080,0.018600,0.013400,0.013890,0.003532,24.990000,23.410000,158.800000,1956.000000,0.123800,0.186600,0.241600,0.186000,0.275000,0.089020},
        {19.690000,21.250000,130.000000,1203.000000,0.109600,0.159900,0.197400,0.127900,0.206900,0.059990,0.745600,0.786900,4.585000,94.030000,0.006150,0.040060,0.038320,0.020580,0.022500,0.004571,23.570000,25.530000,152.500000,1709.000000,0.144400,0.424500,0.450400,0.243000,0.361300,0.087580},
        {11.420000,20.380000,77.580000,386.100000,0.142500,0.283900,0.241400,0.105200,0.259700,0.097440,0.495600,1.156000,3.445000,27.230000,0.009110,0.074580,0.056610,0.018670,0.059630,0.009208,14.910000,26.500000,98.870000,567.700000,0.209800,0.866300,0.686900,0.257500,0.663800,0.173000},
        {20.290000,14.340000,135.100000,1297.000000,0.100300,0.132800,0.198000,0.104300,0.180900,0.058830,0.757200,0.781300,5.438000,94.440000,0.011490,0.024610,0.056880,0.018850,0.017560,0.005115,22.540000,16.670000,152.200000,1575.000000,0.137400,0.205000,0.400000,0.162500,0.236400,0.076780},
        {12.450000,15.700000,82.570000,477.100000,0.127800,0.170000,0.157800,0.080890,0.208700,0.076130,0.334500,0.890200,2.217000,27.190000,0.007510,0.033450,0.036720,0.011370,0.021650,0.005082,15.470000,23.750000,103.400000,741.600000,0.179100,0.524900,0.535500,0.174100,0.398500,0.124400},
        {18.250000,19.980000,119.600000,1040.000000,0.094630,0.109000,0.112700,0.074000,0.179400,0.057420,0.446700,0.773200,3.180000,53.910000,0.004314,0.013820,0.022540,0.010390,0.013690,0.002179,22.880000,27.660000,153.200000,1606.000000,0.144200,0.257600,0.378400,0.193200,0.306300,0.083680},
        {13.710000,20.830000,90.200000,577.900000,0.118900,0.164500,0.093660,0.059850,0.219600,0.074510,0.583500,1.377000,3.856000,50.960000,0.008805,0.030290,0.024880,0.014480,0.014860,0.005412,17.060000,28.140000,110.600000,897.000000,0.165400,0.368200,0.267800,0.155600,0.319600,0.115100},
        {13.000000,21.820000,87.500000,519.800000,0.127300,0.193200,0.185900,0.093530,0.235000,0.073890,0.306300,1.002000,2.406000,24.320000,0.005731,0.035020,0.035530,0.012260,0.021430,0.003749,15.490000,30.730000,106.200000,739.300000,0.170300,0.540100,0.539000,0.206000,0.437800,0.107200},
        {12.460000,24.040000,83.970000,475.900000,0.118600,0.239600,0.227300,0.085430,0.203000,0.082430,0.297600,1.599000,2.039000,23.940000,0.007149,0.072170,0.077430,0.014320,0.017890,0.010080,15.090000,40.680000,97.650000,711.400000,0.185300,1.058000,1.105000,0.221000,0.436600,0.207500},
        {16.020000,23.240000,102.700000,797.800000,0.082060,0.066690,0.032990,0.033230,0.152800,0.056970,0.379500,1.187000,2.466000,40.510000,0.004029,0.009269,0.011010,0.007591,0.014600,0.003042,19.190000,33.880000,123.800000,1150.000000,0.118100,0.155100,0.145900,0.099750,0.294800,0.084520},
        {15.780000,17.890000,103.600000,781.000000,0.097100,0.129200,0.099540,0.066060,0.184200,0.060820,0.505800,0.984900,3.564000,54.160000,0.005771,0.040610,0.027910,0.012820,0.020080,0.004144,20.420000,27.280000,136.500000,1299.000000,0.139600,0.560900,0.396500,0.181000,0.379200,0.104800},
        {19.170000,24.800000,132.400000,1123.000000,0.097400,0.245800,0.206500,0.111800,0.239700,0.078000,0.955500,3.568000,11.070000,116.200000,0.003139,0.082970,0.088900,0.040900,0.044840,0.012840,20.960000,29.940000,151.700000,1332.000000,0.103700,0.390300,0.363900,0.176700,0.317600,0.102300},
        {15.850000,23.950000,103.700000,782.700000,0.084010,0.100200,0.099380,0.053640,0.184700,0.053380,0.403300,1.078000,2.903000,36.580000,0.009769,0.031260,0.050510,0.019920,0.029810,0.003002,16.840000,27.660000,112.000000,876.500000,0.113100,0.192400,0.232200,0.111900,0.280900,0.062870},
        {13.730000,22.610000,93.600000,578.300000,0.113100,0.229300,0.212800,0.080250,0.206900,0.076820,0.212100,1.169000,2.061000,19.210000,0.006429,0.059360,0.055010,0.016280,0.019610,0.008093,15.030000,32.010000,108.800000,697.700000,0.165100,0.772500,0.694300,0.220800,0.359600,0.143100},
        {14.540000,27.540000,96.730000,658.800000,0.113900,0.159500,0.163900,0.073640,0.230300,0.070770,0.370000,1.033000,2.879000,32.550000,0.005607,0.042400,0.047410,0.010900,0.018570,0.005466,17.460000,37.130000,124.100000,943.200000,0.167800,0.657700,0.702600,0.171200,0.421800,0.134100},
        {14.680000,20.130000,94.740000,684.500000,0.098670,0.072000,0.073950,0.052590,0.158600,0.059220,0.472700,1.240000,3.195000,45.400000,0.005718,0.011620,0.019980,0.011090,0.014100,0.002085,19.070000,30.880000,123.400000,1138.000000,0.146400,0.187100,0.291400,0.160900,0.302900,0.082160},
        {16.130000,20.680000,108.100000,798.800000,0.117000,0.202200,0.172200,0.102800,0.216400,0.073560,0.569200,1.073000,3.854000,54.180000,0.007026,0.025010,0.031880,0.012970,0.016890,0.004142,20.960000,31.480000,136.800000,1315.000000,0.178900,0.423300,0.478400,0.207300,0.370600,0.114200},
        {19.810000,22.150000,130.000000,1260.000000,0.098310,0.102700,0.147900,0.094980,0.158200,0.053950,0.758200,1.017000,5.865000,112.400000,0.006494,0.018930,0.033910,0.015210,0.013560,0.001997,27.320000,30.880000,186.800000,2398.000000,0.151200,0.315000,0.537200,0.238800,0.276800,0.076150},
        {15.340000,14.260000,102.500000,704.400000,0.107300,0.213500,0.207700,0.097560,0.252100,0.070320,0.438800,0.709600,3.384000,44.910000,0.006789,0.053280,0.064460,0.022520,0.036720,0.004394,18.070000,19.080000,125.100000,980.900000,0.139000,0.595400,0.630500,0.239300,0.466700,0.099460},
        {21.160000,23.040000,137.200000,1404.000000,0.094280,0.102200,0.109700,0.086320,0.176900,0.052780,0.691700,1.127000,4.303000,93.990000,0.004728,0.012590,0.017150,0.010380,0.010830,0.001987,29.170000,35.590000,188.000000,2615.000000,0.140100,0.260000,0.315500,0.200900,0.282200,0.075260},
        {16.650000,21.380000,110.000000,904.600000,0.112100,0.145700,0.152500,0.091700,0.199500,0.063300,0.806800,0.901700,5.455000,102.600000,0.006048,0.018820,0.027410,0.011300,0.014680,0.002801,26.460000,31.560000,177.000000,2215.000000,0.180500,0.357800,0.469500,0.209500,0.361300,0.095640},
        {17.140000,16.400000,116.000000,912.700000,0.118600,0.227600,0.222900,0.140100,0.304000,0.074130,1.046000,0.976000,7.276000,111.400000,0.008029,0.037990,0.037320,0.023970,0.023080,0.007444,22.250000,21.400000,152.400000,1461.000000,0.154500,0.394900,0.385300,0.255000,0.406600,0.105900},
        {14.580000,21.530000,97.410000,644.800000,0.105400,0.186800,0.142500,0.087830,0.225200,0.069240,0.254500,0.983200,2.110000,21.050000,0.004452,0.030550,0.026810,0.013520,0.014540,0.003711,17.620000,33.210000,122.400000,896.900000,0.152500,0.664300,0.553900,0.270100,0.426400,0.127500},
        {18.610000,20.250000,122.100000,1094.000000,0.094400,0.106600,0.149000,0.077310,0.169700,0.056990,0.852900,1.849000,5.632000,93.540000,0.010750,0.027220,0.050810,0.019110,0.022930,0.004217,21.310000,27.260000,139.900000,1403.000000,0.133800,0.211700,0.344600,0.149000,0.234100,0.074210},
        {15.300000,25.270000,102.400000,732.400000,0.108200,0.169700,0.168300,0.087510,0.192600,0.065400,0.439000,1.012000,3.498000,43.500000,0.005233,0.030570,0.035760,0.010830,0.017680,0.002967,20.270000,36.710000,149.300000,1269.000000,0.164100,0.611000,0.633500,0.202400,0.402700,0.098760},
        {17.570000,15.050000,115.000000,955.100000,0.098470,0.115700,0.098750,0.079530,0.173900,0.061490,0.600300,0.822500,4.655000,61.100000,0.005627,0.030330,0.034070,0.013540,0.019250,0.003742,20.010000,19.520000,134.900000,1227.000000,0.125500,0.281200,0.248900,0.145600,0.275600,0.079190},
        {18.630000,25.110000,124.800000,1088.000000,0.106400,0.188700,0.231900,0.124400,0.218300,0.061970,0.830700,1.466000,5.574000,105.000000,0.006248,0.033740,0.051960,0.011580,0.020070,0.004560,23.150000,34.010000,160.500000,1670.000000,0.149100,0.425700,0.613300,0.184800,0.344400,0.097820},
        {11.840000,18.700000,77.930000,440.600000,0.110900,0.151600,0.121800,0.051820,0.230100,0.077990,0.482500,1.030000,3.475000,41.000000,0.005551,0.034140,0.042050,0.010440,0.022730,0.005667,16.820000,28.120000,119.400000,888.700000,0.163700,0.577500,0.695600,0.154600,0.476100,0.140200},
        {17.020000,23.980000,112.800000,899.300000,0.119700,0.149600,0.241700,0.120300,0.224800,0.063820,0.600900,1.398000,3.999000,67.780000,0.008268,0.030820,0.050420,0.011120,0.021020,0.003854,20.880000,32.090000,136.100000,1344.000000,0.163400,0.355900,0.558800,0.184700,0.353000,0.084820},
        {19.270000,26.470000,127.900000,1162.000000,0.094010,0.171900,0.165700,0.075930,0.185300,0.062610,0.555800,0.606200,3.528000,68.170000,0.005015,0.033180,0.034970,0.009643,0.015430,0.003896,24.150000,30.900000,161.400000,1813.000000,0.150900,0.659000,0.609100,0.178500,0.367200,0.112300},
        {16.130000,17.880000,107.000000,807.200000,0.104000,0.155900,0.135400,0.077520,0.199800,0.065150,0.334000,0.685700,2.183000,35.030000,0.004185,0.028680,0.026640,0.009067,0.017030,0.003817,20.210000,27.260000,132.700000,1261.000000,0.144600,0.580400,0.527400,0.186400,0.427000,0.123300},
        {16.740000,21.590000,110.100000,869.500000,0.096100,0.133600,0.134800,0.060180,0.189600,0.056560,0.461500,0.919700,3.008000,45.190000,0.005776,0.024990,0.036950,0.011950,0.027890,0.002665,20.010000,29.020000,133.500000,1229.000000,0.156300,0.383500,0.540900,0.181300,0.486300,0.086330},
        {14.250000,21.720000,93.630000,633.000000,0.098230,0.109800,0.131900,0.055980,0.188500,0.061250,0.286000,1.019000,2.657000,24.910000,0.005878,0.029950,0.048150,0.011610,0.020280,0.004022,15.890000,30.360000,116.200000,799.600000,0.144600,0.423800,0.518600,0.144700,0.359100,0.101400},
        {14.990000,25.200000,95.540000,698.800000,0.093870,0.051310,0.023980,0.028990,0.156500,0.055040,1.214000,2.188000,8.077000,106.000000,0.006883,0.010940,0.018180,0.019170,0.007882,0.001754,14.990000,25.200000,95.540000,698.800000,0.093870,0.051310,0.023980,0.028990,0.156500,0.055040},
        {13.480000,20.820000,88.400000,559.200000,0.101600,0.125500,0.106300,0.054390,0.172000,0.064190,0.213000,0.591400,1.545000,18.520000,0.005367,0.022390,0.030490,0.012620,0.013770,0.003187,15.530000,26.020000,107.300000,740.400000,0.161000,0.422500,0.503000,0.225800,0.280700,0.107100},
        {13.440000,21.580000,86.180000,563.000000,0.081620,0.060310,0.031100,0.020310,0.178400,0.055870,0.238500,0.826500,1.572000,20.530000,0.003280,0.011020,0.013900,0.006881,0.013800,0.001286,15.930000,30.250000,102.500000,787.900000,0.109400,0.204300,0.208500,0.111200,0.299400,0.071460},
        {10.950000,21.350000,71.900000,371.100000,0.122700,0.121800,0.104400,0.056690,0.189500,0.068700,0.236600,1.428000,1.822000,16.970000,0.008064,0.017640,0.025950,0.010370,0.013570,0.003040,12.840000,35.340000,87.220000,514.000000,0.190900,0.269800,0.402300,0.142400,0.296400,0.096060},
        {19.070000,24.810000,128.300000,1104.000000,0.090810,0.219000,0.210700,0.099610,0.231000,0.063430,0.981100,1.666000,8.830000,104.900000,0.006548,0.100600,0.097230,0.026380,0.053330,0.007646,24.090000,33.170000,177.400000,1651.000000,0.124700,0.744400,0.724200,0.249300,0.467000,0.103800},
        {14.780000,23.940000,97.400000,668.300000,0.117200,0.147900,0.126700,0.090290,0.195300,0.066540,0.357700,1.281000,2.450000,35.240000,0.006703,0.023100,0.023150,0.011840,0.019000,0.003224,17.310000,33.390000,114.600000,925.100000,0.164800,0.341600,0.302400,0.161400,0.332100,0.089110}
};