//beware
#define buzzer 11
#define pir_pin A0
#define led_pin 4

int state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(pir_pin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int val = analogRead(pir_pin);
  if (val > 512){
    digitalWrite(led_pin, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);

    if (state == LOW){
      Serial.println("motion detected");
      state = HIGH;
    }
  }
  else{
    digitalWrite(led_pin, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);

    if (state == HIGH){
      Serial.println("motion stopped");
      state = LOW;
    }
  }
  delay(500);
}
