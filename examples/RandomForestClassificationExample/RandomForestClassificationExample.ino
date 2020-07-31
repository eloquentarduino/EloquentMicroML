#include "DecisionTreeClassifier.h"
#include "RandomForestClassifier.h"
#include "IrisTestSet.h"


using namespace Eloquent::ML::Port;
using namespace Eloquent::ML::Test;


void setup() {
    Serial.begin(115200);
    Serial.println("Begin...");
}

void loop() {
    RandomForestClassifier clf;
    //DecisionTreeClassifier clf;
    TestSet testSet;

    testSet.test(clf);
    Serial.println(testSet.dump());
    delay(5000);
}