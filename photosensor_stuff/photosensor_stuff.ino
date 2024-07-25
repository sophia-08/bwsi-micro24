#define red_pin 2
#define green_pin 4
#define yellow_pin 3
// #define pr_pin A0
#define stop_button 5
#define go_button 6

int mode = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(stop_button, INPUT);
  pinMode(go_button, INPUT);
  // pinMode(pr_pin, INPUT);
}

void loop() {
  // if (analogRead(pr_pin) > 50){
  //   digitalWrite(green_pin, HIGH);
  //   digitalWrite(red_pin, LOW);
  // }
  // else{
  //   digitalWrite(red_pin, HIGH);
  //   digitalWrite(green_pin, LOW);
  // }
  // delay(500);
  for (int i=0; i<150; i++){
    if (digitalRead(go_button) == HIGH){
      break;
    }
    digitalWrite(red_pin, HIGH);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, LOW);
    delay(100);
  }
  for (int i=0; i<150; i++){
    if (digitalRead(stop_button) == HIGH){
      break;
    }
    digitalWrite(red_pin, LOW);
    digitalWrite(yellow_pin, LOW);
    digitalWrite(green_pin, HIGH);
    delay(100)
  }
  
  delay(10000);
  digitalWrite(red_pin, LOW);
  digitalWrite(yellow_pin, HIGH);
  digitalWrite(green_pin, LOW);
  delay(5000);

}

void greenOn(){

}
