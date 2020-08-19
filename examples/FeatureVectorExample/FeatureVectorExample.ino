#include "EloquentFeatureWindow.h"
#define SIZE 20
#define WINDOW 10

Eloquent::ML::Window<SIZE, WINDOW> features;


void setup() {
    Serial.begin(115200);
    delay(3000);

    // 1. No values transformation, no endless
    // expected: 0,1,2,3,...,19
    for (int i = 0; i < SIZE + 1; i++)
        features += i;

    features.printTo(Serial);
    features.clear();

    // 2. Endless values: append SIZE+1 values
    // expected: 1,2,3,...,20
    features.endless();

    for (int i = 0; i < SIZE + 1; i++)
        features += i;

    features.printTo(Serial);
    features.clear();

    // 3. MinMaxScaler: map values from [0, 20] to [0, 10]
    // expected: 0,0.5,1,1.5,2,...,9.5
    features.endless(false);
    features.minmaxScaler(0, 20, 0, 10);

    for (int i = 0; i < SIZE; i++)
        features += i;

    features.printTo(Serial);
    features.clear();

    // 4. Slide window
    // expected 10,11,12,...,19,0,0,0...
    features.minmaxScaler(0, 20, 0, 20);

    for (int i = 0; i < SIZE + 1; i++)
        features += i;

    features.slide();
    features.printTo(Serial);
    features.clear();
}

void loop() {
}