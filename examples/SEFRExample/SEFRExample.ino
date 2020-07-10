#include "EloquentSEFR.h"
#include "BreastCancerTrain.h"
#include "BreastCancerTest.h"

#define benchmark(msg, x) {time_t start = micros(); x; Serial.print("It took "); Serial.print(micros() - start); Serial.println(" micros to " msg); }


void setup() {
    Serial.begin(115200);
    delay(3000);
}

void loop() {
    Eloquent::ML::SEFR<30> clf;
    Eloquent::ML::Train::TrainSet trainSet;
    Eloquent::ML::Test::TestSet testSet;

    benchmark("train", trainSet.fit(&clf));
    benchmark("test", testSet.test(clf));

    Serial.println(testSet.dump());
    delay(5000);
}