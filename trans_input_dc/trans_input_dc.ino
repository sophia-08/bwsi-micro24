#define MOTOR 9

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
  Serial.println("enter a speed from 0 to 225");
}

void loop() {
  // digital turn on and off
  // digitalWrite(MOTOR, HIGH);
  // delay(2000);
  // digitalWrite(MOTOR, LOW);
  // delay(5000);

  //different speeds
  // int speed = Serial.parseInt();
  // if (speed >= 0 && speed <= 255) {
  //   analogWrite(MOTOR, speed);
  //   delay(3000);
  // }

  if (Serial.available() > 0) {
    int speedValue = Serial.parseInt();
    if (speedValue >= 0 && speedValue <= 255) {
      analogWrite(MOTOR, speedValue);  
      Serial.print("Motor speed set to: ");
      Serial.println(speedValue);
    } else {
      Serial.println("Invalid speed value. Enter a value between 0 and 255.");
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }

  // for (int i = 75; i < 255; i+=10){
  //   analogWrite(MOTOR, i);
  //   delay(800);
  // }
  // for (int i = 255; i >=75; i-=10){
  //   analogWrite(MOTOR, i);
  //   delay(800);
  // }
}
