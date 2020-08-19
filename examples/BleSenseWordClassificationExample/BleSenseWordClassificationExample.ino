#include "EloquentML.h"
#include "Mic.h"
#include "SVM.h"
#include "RandomForest.h"
#include "GaussianNB.h"

#define SAMPLES 64
#define GAIN

using namespace Eloquent::ML::Data;
using namespace Eloquent::ML::Data::Operators;
using namespace Eloquent::ML::Port;


Array<SAMPLES> features;
Mic mic;
SVM clf;
// RandomForest clf;
// GaussianNB clf;


/**
 *
 */
void setup() {
    Serial.begin(115200);
    PDM.onReceive(onAudio);
    mic.begin();
    features.map(new Quantize(GAIN));
    delay(3000);
}


/**
 * Record a sample and classify
 */
void loop() {
    if (record()) {
        features.printTo(Serial);
        classify();

        features.clear();
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
    if (mic.hasData() && mic.data() > 1500) {
        while (!features.isFull()) {
            if (mic.hasData()) {
                features.insert(mic.data());
                mic.reset();
            }
        }

        return true;
    }

    return false;
}


/**
 * Run ML classification
 */
void classify() {
    float input[SAMPLES];

    features.toArray(input);
    Serial.print("You said: ");
    Serial.println(clf.predictLabel(input));
}