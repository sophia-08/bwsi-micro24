#define led 3
#define mic A0

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  // pinMode(mic, INPUT);
}

void loop() {
  int sound = analogRead(mic);
  Serial.println(sound);
  if (sound >= 101){
    digitalWrite(led, HIGH);
    // Serial.println("high");
    delay(500);
  }
  else{
    digitalWrite(led, LOW);
    // Serial.println("low");
  }
  delay(100);
}
