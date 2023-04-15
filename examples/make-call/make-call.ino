/*************************************************************************************
 *  Created By: Tauseef Ahmad
 *  Created On: 15 April, 2023
 *  
 *  Tutorial: https://youtu.be/lYN8hqNAKbU
 *  My Channel: https://www.youtube.com/channel/UCOXYfOHgu-C-UfGyDcu5sYw/
 ***********************************************************************************/
 
 #include <SIM800L.h>

SIM800L sim800l(2, 3); //Rx, Tx

//Enter the phone number of the person whom you want to make a call
String PHONE = "+923001234567";

void handleSMS(String number, String message) {
  Serial.println("number: " + number + "\nMessage: " + message);
}

void handleCall(String number) {
  Serial.println("New call from " + number);
}

void setup() {
  Serial.begin(9600);
  
  sim800l.begin(9600);
  
  sim800l.setSMSCallback(handleSMS);
  sim800l.setCallCallback(handleCall);
  
  sim800l.makeCall(PHONE);
}

void loop() {
  sim800l.listen();
}