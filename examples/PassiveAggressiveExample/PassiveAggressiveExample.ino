#include <EloquentPassiveAggressiveClassifier.h>
#include <EloquentAccuracyScorer.h>
#include "cleveland_heart_disease.h"

// #define VERBOSE

using namespace Eloquent::ML;


void setup() {
    Serial.begin(115200);
    delay(3000);
}


void loop() {
    int trainSamples;
    PassiveAggressiveClassifier<FEATURES_DIM> clf;
    AccuracyScorer scorer;

    trainSamples = readSerialNumber("How many samples will you use as training?", DATASET_SIZE - 2);

    if (trainSamples == 0)
        return;

    clf.setC(1);

    // train
    for (uint16_t i = 0; i < trainSamples; i++)
        clf.fitOne(X[i], y[i]);

    // predict
    for (uint16_t i = trainSamples; i < DATASET_SIZE; i++) {
        int predicted = clf.predict(X[i]);
        int actual = y[i] > 0 ? 1 : -1;

        scorer.scoreOne(actual, predicted);

#if defined(VERBOSE)
        Serial.print(predicted == actual ? "[ OK]" : "[ERR]");
        Serial.print(" Predicted ");
        Serial.print(predicted > 0 ? "+" : "");
        Serial.print(predicted);
        Serial.print(" vs ");
        Serial.print(actual > 0 ? "+" : "");
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