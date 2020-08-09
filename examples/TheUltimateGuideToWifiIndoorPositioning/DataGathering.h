#include <WiFi.h>

#define print(string) Serial.print(string);
#define quote(string) print('"'); print(string); print('"');


String location = "";


/**
 * 
 */
void setup() {
  Serial.begin(115200);
  delay(3000);
  WiFi.disconnect();
}

/**
 * 
 */
void loop() {  
  // if location is set, scan networks
  if (location != "") {
    int numNetworks = WiFi.scanNetworks();

    // print location
    print('{');
    quote("__location");
    print(": ");
    quote(location);
    print(", ");
  
    // print each network SSID and RSSI
    for (int i = 0; i < numNetworks; i++) {
      quote(WiFi.SSID(i));
      print(": ");
      print(WiFi.RSSI(i));
      print(i == numNetworks - 1 ? "}\n" : ", ");
    }
      
    delay(1000);
  }
  // else wait for user to enter the location
  else {
    String input;
    
    Serial.println("Enter 'scan {location}' to start the scanning");

    while (!Serial.available())
      delay(200);
      
    input = Serial.readStringUntil('\n');

    if (input.indexOf("scan ") == 0) {
      input.replace("scan ", "");
      location = input;
    }
    else {
      location = "";
    }
  }
}
