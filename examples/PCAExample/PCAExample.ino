#include "pca.h"

float X_train[10][4] = {
        {5.1, 3.5, 1.4, 0.2},
        {4.9, 3.0, 1.4, 0.2},
        {4.7, 3.2, 1.3, 0.2},
        {4.6, 3.1, 1.5, 0.2},
        {5.0, 3.6, 1.4, 0.2},
        {5.4, 3.9, 1.7, 0.4},
        {4.6, 3.4, 1.4, 0.3},
        {5.0, 3.4, 1.5, 0.2},
        {4.4, 2.9, 1.4, 0.2},
        {4.9, 3.1, 1.5, 0.1}
};

float X_test[10][2] = {
        {-2.68412563, 0.31939725},
        {-2.71414169, -0.17700123},
        {-2.88899057, -0.14494943},
        {-2.74534286, -0.31829898},
        {-2.72871654, 0.32675451},
        {-2.28085963, 0.74133045},
        {-2.82053775, -0.08946138},
        {-2.62614497, 0.16338496},
        {-2.88638273, -0.57831175},
        {-2.6727558, -0.11377425}
};

Eloquent::ML::Port::PCA pca;


void setup() {
    Serial.begin(115200);
    delay(3000);

    for (int i = 0; i < 10; i++)
        test(X_train[i], X_test[i]);
}

void loop() {
    // put your main code here, to run repeatedly:

}


void test(float x_train[4], float x_test[2]) {
    float x_pca[2];

    pca.transform(x_train, x_pca);

    Serial.println(compare_arrays(x_pca, x_test) ? "OK" : "ERR");
}

bool compare_arrays(float pred[2], float test[2]) {
    return abs(pred[0] - test[0]) < 0.0001 && abs(pred[1] - test[1]) < 0.0001;
}