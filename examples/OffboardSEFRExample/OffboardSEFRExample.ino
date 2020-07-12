#include "IrisSEFR.h"
#include "IrisTest.h"


void setup() {
    Serial.begin(115200);
}

void loop() {
    Eloquent::ML::Port::SEFR clf;
    Eloquent::ML::Test::IrisTestSet testSet;

    testSet.test(clf);
    Serial.println(testSet.dump());
    delay(5000);
}