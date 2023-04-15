/*************************************************************************************
 *  Created By: Tauseef Ahmad
 *  Created On: 15 April, 2023
 *  
 *  Tutorial: https://youtu.be/lYN8hqNAKbU
 *  My Channel: https://www.youtube.com/channel/UCOXYfOHgu-C-UfGyDcu5sYw/
 ***********************************************************************************/
 
 #include <SIM800L.h>

SIM800L sim800l(2, 3); //Rx, Tx

#define LED_PIN 13

void handleSMS(String number, String message) {
  Serial.println("number: " + number + "\nMessage: " + message);
  if(message == "on") {
    digitalWrite(LED_PIN, HIGH);
  } 
  else if(message == "off") {
    digitalWrite(LED_PIN, LOW);
  }
}

void handleCall(String number) {
  Serial.println("New call from " + number);
  boolean flag = digitalRead(LED_PIN);
  digitalWrite(LED_PIN, !flag);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  
  sim800l.begin(9600);
  
  sim800l.setSMSCallback(handleSMS);
  sim800l.setCallCallback(handleCall);
}

void loop() {
  sim800l.listen();
}
