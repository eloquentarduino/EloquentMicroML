#ifdef ESP32
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define abs(x) ((x) > 0 ? (x) : -(x))
#endif
#define d(k, v) Serial.print(k); Serial.print(" = "); Serial.println(v);

#define KERNEL_GAMMA 0.001
#include <EloquentSVMSMO.h>
#include "digits.h"

#define TOTAL_SAMPLES (POSITIVE_SAMPLES + NEGATIVE_SAMPLES)

using namespace Eloquent::ML;


float X_train[TOTAL_SAMPLES][FEATURES_DIM];
float X_test[TOTAL_SAMPLES][FEATURES_DIM];
int y_train[TOTAL_SAMPLES];
int y_test[TOTAL_SAMPLES];
float cache[TOTAL_SAMPLES * TOTAL_SAMPLES];
SVMSMO<FEATURES_DIM> classifier(linearKernel);


void setup() {
    Serial.begin(115200);
    delay(3000);

    // configure classifier
    classifier.setC(10);
    classifier.setTol(1e-5);
    classifier.setMaxIter(10000);
//    classifier.setKernelCache(cache);
}


void loop() {
    int tp = 0;
    int tn = 0;
    int fp = 0;
    int fn = 0;

    int positiveSamples = readSerialNumber("How many positive samples will you use for training? ", POSITIVE_SAMPLES);

    if (positiveSamples > POSITIVE_SAMPLES - 1) {
        Serial.println("Too many positive samples entered. All but one will be used instead");
        positiveSamples = POSITIVE_SAMPLES - 1;
    }

    int negativeSamples = readSerialNumber("How many negative samples will you use for training? ", NEGATIVE_SAMPLES);

    if (negativeSamples > NEGATIVE_SAMPLES - 1) {
        Serial.println("Too many negative samples entered. All but one will be used instead");
        negativeSamples = NEGATIVE_SAMPLES - 1;
    }

    loadDataset(positiveSamples, negativeSamples);
    time_t start = millis();
    classifier.fit(X_train, y_train, positiveSamples + negativeSamples);
    Serial.print("It took ");
    Serial.print(millis() - start);
    Serial.print("ms to train on ");
    Serial.print(positiveSamples + negativeSamples);
    Serial.println(" samples");

    start = millis();

    for (int i = 0; i < TOTAL_SAMPLES - positiveSamples - negativeSamples; i++) {
        int y_pred = classifier.predict(X_train, X_test[i]);
        int y_true = y_test[i];

        /*Serial.print("[");
        Serial.print(y_pred == y_true ? "OK " : "ERR");
        Serial.print("] Predicted ");
        Serial.print(y_pred);
        Serial.print(" vs ");
        Serial.print(y_true);
        Serial.println(" true");*/

        if (y_pred == y_true && y_pred ==  1) tp += 1;
        if (y_pred == y_true && y_pred == -1) tn += 1;
        if (y_pred != y_true && y_pred ==  1) fp += 1;
        if (y_pred != y_true && y_pred == -1) fn += 1;
    }

    Serial.print("It took ");
    Serial.print(millis() - start);
    Serial.print("ms to test on ");
    Serial.print(TOTAL_SAMPLES - positiveSamples - negativeSamples);
    Serial.println(" samples");

    printConfusionMatrix(tp, tn, fp, fn);
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

    return n;
}

/**
 * Divide training and test data
 */
void loadDataset(int positiveSamples, int negativeSamples) {
    int positiveTestSamples = POSITIVE_SAMPLES - positiveSamples;

    for (int i = 0; i < positiveSamples; i++) {
        memcpy(X_train[i], X_positive[i], FEATURES_DIM);
        y_train[i] = 1;
    }

    for (int i = 0; i < negativeSamples; i++) {
        memcpy(X_train[i + positiveSamples], X_negative[i], FEATURES_DIM);
        y_train[i + positiveSamples] = -1;
    }

    for (int i = 0; i < positiveTestSamples; i++) {
        memcpy(X_test[i], X_positive[i + positiveSamples], FEATURES_DIM);
        y_test[i] = 1;
    }

    for (int i = 0; i < NEGATIVE_SAMPLES - negativeSamples; i++) {
        memcpy(X_test[i + positiveTestSamples], X_negative[i + negativeSamples], FEATURES_DIM);
        y_test[i + positiveTestSamples] = -1;
    }
}

/**
 * Dump confusion matrix to Serial monitor
 * @param tp
 * @param tn
 * @param fp
 * @param fn
 */
void printConfusionMatrix(int tp, int tn, int fp, int fn) {
    Serial.print("Overall accuracy ");
    Serial.print(100.0 * (tp + tn) / (tp + tn + fp + fn));
    Serial.println("%");
    Serial.println("Confusion matrix");
    Serial.print("          | Predicted 1 | Predicted -1 |\n");
    Serial.print("----------------------------------------\n");
    Serial.print("Actual  1 |      ");
    Serial.print(tp);
    Serial.print("     |      ");
    Serial.print(fn);
    Serial.print("       |\n");
    Serial.print("----------------------------------------\n");
    Serial.print("Actual -1 |      ");
    Serial.print(fp);
    Serial.print("      |      ");
    Serial.print(tn);
    Serial.print("       |\n");
    Serial.print("----------------------------------------\n\n\n");
}