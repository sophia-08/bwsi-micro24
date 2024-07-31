#include <Servo.h>

Servo myServo;
#define POT A0
#define SERVO 2

void setup() {
  // put your setup code here, to run once
  myServo.attach(SERVO);
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(POT);
  val = map(val, 1, 1023, 0, 180);
  Serial.println(val);
  myServo.write(val);
  delay(70);
}
