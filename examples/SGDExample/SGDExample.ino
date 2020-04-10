#include <EloquentSGD.h>
#include <EloquentAccuracyScorer.h>
#include "iris.h"

#define VERBOSE

using namespace Eloquent::ML;


void setup() {
    Serial.begin(115200);
    delay(3000);
}


void loop() {
    int trainSamples;
    int retrainingCycles;
    SGD<FEATURES_DIM> clf;
    AccuracyScorer scorer;

    clf.momentum(0.5);
    trainSamples = readSerialNumber("How many samples will you use as training?", DATASET_SIZE - 2);
    retrainingCycles = readSerialNumber("How many times will you cycle through the training samples?", 100);

    if (trainSamples == 0 || retrainingCycles == 0)
        return;

    // train
    for (uint16_t cycle = 0; cycle < retrainingCycles; cycle++)
        for (uint16_t i = 0; i < trainSamples; i++)
            clf.fitOne(X[i], y[i]);

    // predict
    for (uint16_t i = trainSamples; i < DATASET_SIZE; i++) {
        int predicted = clf.predict(X[i]);
        int actual = y[i];

        scorer.scoreOne(actual, predicted);

#if defined(VERBOSE)
        Serial.print(predicted == actual ? "[ OK]" : "[ERR]");
        Serial.print(" Predicted ");
        Serial.print(predicted);
        Serial.print(" vs ");
        Serial.print(actual);
        Serial.println(" actual");
#endif
    }

    Serial.print("Accuracy: ");
    Serial.print(round(100 * scorer.accuracy()));
    Serial.print("% out of ");
    Serial.print(scorer.support());
    Serial.println(" predictions");
}

/**
 * Ask the user to enter a numeric value
 */
int readSerialNumber(String prompt, int maxAllowed) {
    Serial.print(prompt);
    Serial.print(" (");
    Serial.print(maxAllowed);
    Serial.print(" max) ");

    while (!Serial.available()) delay(1);

    int n = Serial.readStringUntil('\n').toInt();

    Serial.println(n);

    return max(0, min(n, maxAllowed));
}