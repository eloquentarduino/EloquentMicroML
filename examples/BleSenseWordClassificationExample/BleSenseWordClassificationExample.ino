#include "EloquentML.h"
#include "Mic.h"
#include "Classifier.h"

// tune as per your needs
#define SAMPLES 64
#define GAIN (1/50)
#define SOUND_THRESHOLD 2000

using namespace Eloquent::ML::Port;


float features[SAMPLES];
Mic mic;
SVM clf;


/**
 *
 */
void setup() {
    Serial.begin(115200);
    PDM.onReceive(onAudio);
    mic.begin();
    delay(3000);
}


/**
 * Record a sample and classify
 */
void loop() {
    if (record()) {
        // print features
        for (int i = 0; i < SAMPLES; i++) {
            Serial.print(features[i], 6);
            Serial.print(i == SAMPLES - 1 ? '\n' : ',');
        }

        // un-comment when you have your model exported
//        Serial.print("You said: ");
//        Serial.println(clf.predictLabel(features));

        delay(500);
    }

    delay(20);
}


/**
 * PDM callback to update mic object
 */
void onAudio() {
    mic.update();
}


/**
 * Read given number of samples from mic
 */
bool record() {
    if (mic.hasData() && mic.data() > SOUND_THRESHOLD) {

        for (int i = 0; i < SAMPLES; i++) {
            while (!mic.hasData())
                delay(1);

            features[i] = mic.pop() * GAIN;
        }

        return true;
    }

    return false;
}