#include <Stepper.h>

//steps per revolution
const int SPR = 32*64;

//IN1, IN3, IN2, IN4
Stepper myStepper(SPR, 8, 11, 9, 10);

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(15);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("cw");
  myStepper.step(SPR);
  delay(500);

  Serial.println("ccw");
  myStepper.step(-SPR);
  delay(500);
}
