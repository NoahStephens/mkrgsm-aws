#include <ArduinoJson.h>



#include <MKRGSM.h>
//#include <ArduinoJson.h>



// modem verification object
GSMModem modem;

// IMEI variable
String IMEI = "";

void setup() {
  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  modem.begin();
    
}

void loop() {
    // get modem IMEI
    IMEI = modem.getIMEI();
    
    //Serial.println("IMEI);

if (modem.begin()) {
  DynamicJsonBuffer jBuffer;
  JsonObject& root = jBuffer.createObject();

  root["afr_source_dir"] = "../..";
  root["thing_name"] = IMEI;
  root["wifi_password"] = "password";
  root["wifi_security"] = "wpa2";

  root.prettyPrintTo(Serial);
  Serial.println();


}

while (true);


}



  