#include "OneClassSVM.h"
#include "test_set.h"

Eloquent::ML::Port::SVM clf;
Eloquent::ML::Test::TestSet test;

void setup() {
    Serial.begin(115200);
    delay(2000);
    
    test.test(clf);
    Serial.println(test.dump());
}

void loop() {}