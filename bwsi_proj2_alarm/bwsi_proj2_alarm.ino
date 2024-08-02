//libraries
#include <Servo.h>
#include "DHT.h"
#include <LiquidCrystal.h>

//pins
#define DRILLBUTTON A1
#define STOPBUTTON A3
#define SERVO 7
#define DHTS 2
#define PHOTORES A0
#define WLED 6
#define POT A2
#define REDL 11
#define GREENL 5
#define BLUEL 3
#define RS 13
#define EN 12
#define D4 10
#define D5 9
#define D6 4
#define D7 8

//constants
#define BRIGHT_THR 180
#define TEMP_THR 60
#define HUM_THR 50

//vars
int update = 0;
bool alarmMode = false;

//components
Servo myServo;
#define DHTTYPE DHT11
DHT dht(DHTS, DHTTYPE);
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO);
  // pinMode(DRILLBUTTON, INPUT);
  // pinMode(STOPBUTTON, INPUT);
  pinMode(PHOTORES, INPUT);
  pinMode(WLED, OUTPUT);
  // pinMode(POT, INPUT);
  pinMode(REDL, OUTPUT);
  pinMode(GREENL, OUTPUT);
  pinMode(BLUEL, OUTPUT);
  dht.begin();
  lcd.begin(16, 2);
  randomSeed(analogRead(0));
}

int red =0;

void loop() {
  // Serial.println(analogRead(STOPBUTTON));
  Serial.println(checkStop());
  // Serial.println(isDrill());
  int bright = analogRead(PHOTORES);
  int temp = (dht.readTemperature()*9)/5 + 32;
  int hum = dht.readHumidity();

  if (update % 400 == 0){
    updateLCD_normal(bright, temp, hum);
    randomColor();
  }
  update++;

  controlLed();

  if (possibleFire(bright, temp, hum)){
    updateLCD_fire();
    digitalWrite(WLED, LOW);
    while (checkStop()){
      // Serial.println(checkStop());
      turnLEDRed();
      if(!checkStop()){
        break;
      }
      
      myServo.write(0);
      delay(250);
      if(!checkStop()){
        break;
      }
      myServo.write(60);
      delay(250);
      if(!checkStop()){
        break;
      }
      // delay(400);
      turnLEDOff();
      delay(300);
    }
    updateLCD_stop();
    delay(500);
  }

  if (isDrill()){
    updateLCD_drill();
    delay(500);
    int drillTime = 0;
    while (checkStop() && drillTime < 10){
      turnLEDPurple();
      turnSprinklerOn();
      if(!checkStop()){
        break;
      }
      // delay(400);
      turnLEDOff();
      if(!checkStop()){
        break;
      }
      delay(300);
      drillTime+=1;
    }
    updateLCD_over();
    delay(500);
  }

  // red ++;
  // red %=10;
  // if (red <4){
  //   digitalWrite(REDL, HIGH);
  // }
  // else{
  //   digitalWrite(REDL, LOW);
  // }


  // setColor(255, 0, 0);
  // delay(1000);
  // setColor(100, 0, 0);
  // delay(1000);
  // setColor(0, 255, 0);
  // delay(1000);
  // setColor(0, 100, 0);

  // Serial.println(digitalRead(DRILLBUTTON));

  delay(1);

  // myServo.write(0);
  // delay(700);
  // myServo.write(18);
  // delay(200);
}

void turnSprinklerOn(){
  myServo.write(0);
  delay(250);
  myServo.write(60);
  delay(250);
}

void turnLEDPurple(){
  setColor(170, 0, 255);
}

bool isDrill(){
  if (digitalRead(DRILLBUTTON) == HIGH) return true;
  return false;
}

bool checkStop(){
  if (digitalRead(STOPBUTTON) == HIGH) return false;
  return true;
}

void turnLEDRed(){
  setColor(255, 0, 0);
}

void turnLEDOff(){
  setColor(0, 0, 0);
}

void randomColor(){
  long randRed = random() % 170;
  long randGre = random() % 255;
  long randBlue = random() % 255;
  setColor(randRed, randGre, randBlue);
}

void controlLed(){
  int ledb = analogRead(POT);
  ledb /= 4;
  if (ledb < 25){
    ledb = 0;
  }
  // Serial.println(ledb);
  analogWrite(WLED, ledb);
  // delay(50);
}

void updateLCD_over(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Drill over");
}

void updateLCD_stop(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alarm stopped");
}

void updateLCD_drill(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("THIS IS A DRILL!");
  lcd.setCursor(0, 1);
  lcd.print("REPEAT, DRILL!!!");
}

void updateLCD_fire(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("FIRE ALERT!!");
  lcd.setCursor(0, 1);
  lcd.print("THERE IS A FIRE");
}

void updateLCD_normal(int bright, int temp, int hum){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(String(temp));
  lcd.print("-F");
  lcd.setCursor(0, 1);
  lcd.print("Bri: ");
  lcd.print(String(bright));
  lcd.print(" Hum: ");
  lcd.print(String(hum));
}

bool possibleFire(int bright, int temp, int hum){
  if (bright > BRIGHT_THR && temp > TEMP_THR && hum > HUM_THR){
    return true;
  }
  return false;
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(REDL, redValue);
  analogWrite(GREENL, greenValue);
  analogWrite(BLUEL, blueValue);
}