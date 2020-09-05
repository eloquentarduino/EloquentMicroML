#include "PrincipalFFT.h"
#include "GaussianNB.h"
#include "RandomForest.h"
#include "MNIST.h"
#include "arduinoFFT.h"


Eloquent::ML::Port::RandomForest clf;


void fft(float* features) {
  double imag[64];
  double real[64];
  
  arduinoFFT fft;

  fft.Compute(real, imag, 64, 1000);
  fft.ComplexToMagnitude(real, imag, 64);
}


void setup() {
  Serial.begin(115200);
  delay(3000);
}

void loop() {
  int correct = 0;
  
  for (int i = 0; i < SAMPLES; i++) {
    float featuresFFT[10] = {0};

    time_t start = micros();
    //principalFFT(X[i], featuresFFT);
    //fft(X[i]);
    time_t delta = micros() - start;
    Serial.print("It took ");
    Serial.print(delta);
    Serial.println(" micros");

    for (int i = 0; i < 10; i++) {
      Serial.println(featuresFFT[i]);
    }

    delay(50000);
    delay(50000);

    
    int actual = y[i];
    int predicted = clf.predict(featuresFFT);

    Serial.print(predicted == actual ? "[OK ] " : "[ERR] ");
    Serial.print("Predicted ");
    Serial.print(predicted);
    Serial.print(" vs ");
    Serial.print(actual);
    Serial.println();

    if (predicted == actual)
      correct += 1;
  }

  Serial.print("Correct ");
  Serial.print(correct);
  Serial.print(" out of ");
  Serial.print(SAMPLES);
  Serial.print(" (");
  Serial.print(100 * (1.0f * correct / SAMPLES));
  Serial.print("% accuracy)");
  Serial.println("------------------------");
  delay(3000);

}
