/* Sweep Edge

Sweeps a servo 90 degrees on a rising or falling edge
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// this constant won't change:
const int inputPin = 2;  

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

#define TURN_TIME 175

void setup() {
  // initialize the button pin as a input:
  pinMode(inputPin, INPUT);
  myservo.attach(9);  
  myservo.write(90);
  delay(TURN_TIME);
  myservo.detach(); // save some energy
  Serial.begin(9600);
}

void loop() {

  // read the pushbutton input pin:
  buttonState = digitalRead(inputPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      Serial.println("on");
      turn_left();
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
      turn_right();
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;


}

void turn_left() {
  myservo.attach(9);
  myservo.write(135);
  delay(TURN_TIME);
  myservo.detach();
  Serial.println("Done turning left");
}

void turn_right() {
  myservo.attach(9);
  myservo.write(45);
  delay(TURN_TIME);
  myservo.detach();
  Serial.println("Done turning right");
}
