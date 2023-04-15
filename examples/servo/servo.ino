/*************************************************************************************
 *  Created By: Tauseef Ahmad
 *  Created On: 15 April, 2023
 *  
 *  Tutorial: https://youtu.be/lYN8hqNAKbU
 *  My Channel: https://www.youtube.com/channel/UCOXYfOHgu-C-UfGyDcu5sYw/
 ***********************************************************************************/
 
#include <SIM800L.h>
#include <Servo.h>

SIM800L sim800l(2, 3); //Rx, Tx

#define SERVO_PIN 9
Servo myservo;  // create servo object

void handleSMS(String number, String message) {
  Serial.println("number: " + number + "\nMessage: " + message);
  //received angle from your phone and then write to Servo
  //send the angle between 0-180
  myservo.write(message.toInt());
}

void handleCall(String number) {
  Serial.println("New call from " + number);
}

void setup() {
  Serial.begin(9600);
  
  sim800l.begin(9600);
  
  myservo.attach(SERVO_PIN);
  
  sim800l.setSMSCallback(handleSMS);
  sim800l.setCallCallback(handleCall);
}

void loop() {
  sim800l.listen();
}