#define TRANSISTOR 9

void setup() {
  // put your setup code here, to run once:
  pinMode(TRANSISTOR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRANSISTOR, HIGH);
  delay(1000);
  digitalWrite(TRANSISTOR, LOW);
  delay(1000);
}
