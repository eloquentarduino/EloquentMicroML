// PLATFORM: Esp32
// Esp32 has some problems with min/max
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
// you will actually need only one of SGD or PassiveAggressive
#include <EloquentSGD.h>
#include <EloquentPassiveAggressive.h>
#include <EloquentOneVsOne.h>
#include <EloquentAccuracyScorer.h>
// this file defines NUM_FEATURES, NUM_CLASSES, TRAIN_SAMPLES and TEST_SAMPLES
#include "dataset.h"

using namespace Eloquent::ML;


void setup() {
    Serial.begin(115200);
    delay(3000);
}


void loop() {
    AccuracyScorer scorer;
    // OneVsOne needs the actual classifier class, the number of features and the number of classes
    OneVsOne<SGD<FEATURES_DIM>, FEATURES_DIM, NUM_CLASSES> clf;

    // clf.set() propagates the configuration to the actual classifiers
    // if a parameter does not exists on the classifier, it does nothing
    // in this example, alpha and momentum refer to SGD, C to Passive-Aggressive
    clf.set("alpha", 1);
    clf.set("momentum", 0.7);
    clf.set("C", 0.1);

    // fit
    // I noticed that repeating the training a few times over the same dataset increases performance  to a certain extent: if you re-train it too much, performance will decay
    for (unsigned int i = 0; i < TRAIN_SAMPLES * 5; i++) {
        clf.fitOne(X_train[i % TRAIN_SAMPLES], y_train[i % TRAIN_SAMPLES]);
    }

    // predict
    for (int i = 0; i < TEST_SAMPLES; i++) {
        int y_true = y_test[i];
        int y_pred = clf.predict(X_test[i]);

        Serial.print("Predicted ");
        Serial.print(y_pred);
        Serial.print(" vs ");
        Serial.println(y_true);
        scorer.scoreOne(y_true, y_pred);
    }

    Serial.print("Accuracy = ");
    Serial.print(scorer.accuracy() * 100);
    Serial.print(" out of ");
    Serial.print(scorer.support());
    Serial.println(" samples");
    delay(30000);
}