/**
 * 1. Install the Arduino ESP32 filesystem uploader plugin from https://github.com/me-no-dev/arduino-esp32fs-plugin
 * 2. Put your dataset file inside a "data" folder
 * 3. Tools > ESP32 Sketch Data Upload
 * 4. Flash this sketch
 *
 * The dataset file MUST contain one feature vector + the class label
 * for each line. E.g. x11,x12,x13,x14,y1
 */

#include <FS.h>
#include <SPIFFS.h>
#include <EloquentCsvReader.h>
#include <EloquentSGD.h>
#include <EloquentPassiveAggressive.h>
#include <EloquentAccuracyScorer.h>

#include "iris_test.h"

using namespace Eloquent::ML;


void setup() {
    Serial.begin(115200);
    SPIFFS.begin(true);
}

void loop() {
    float *features;
    PassiveAggressive<FEATURES_DIM> clf;
    CsvReader<float, FEATURES_DIM> loader;
    AccuracyScorer scorer;
    File file = SPIFFS.open("/iris.csv");

    // train from file
    clf.set("momentum", 0.5);
    loader.fit(file, &clf, 3);

    // test
    for (int i = 0; i < TEST_SAMPLES; i++) {
        int y_pred = clf.predict(X_test[i]);

        Serial.print("Predicted ");
        Serial.print(y_pred);
        Serial.print(" vs ");
        Serial.println(y_test[i]);
        scorer.scoreOne(y_test[i], y_pred);
    }

    Serial.print("Accuracy: ");
    Serial.print(scorer.accuracy());
    Serial.println("%");
    delay(5000);
}