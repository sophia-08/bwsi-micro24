//libraries
#include "DHT.h"
#include <LiquidCrystal.h>

//pins
#define dc_forward 3
#define dc_backward 4
#define photores A0
#define thermo A1
#define dht_pin 2
#define led 9
#define potent A3
#define rs 5
#define en 6
#define d4 10
#define d5 11
#define d6 12
#define d7 13
#define button 7

//const
#define themo_res 100000
#define c1 1.009249522e-03
#define c2 2.378405444e-04
#define c3 2.019202697e-07
#define bright_thresh 200
#define temp_thresh 60
#define hum_thresh 60


#define DHTTYPE DHT11
DHT dht(dht_pin, DHTTYPE);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool buttonStop = false;
int update_pause = 0;

void setup() {
  Serial.begin(9600);
  pinMode(dc_forward, OUTPUT);
  pinMode(dc_backward, OUTPUT);
  pinMode(photores, INPUT);
  pinMode(thermo, INPUT);
  // pinMode(dht_pin, INPUT);
  dht.begin();
  pinMode(led, OUTPUT);
  lcd.begin(16, 2);
  pinMode(button, INPUT);
}

void loop() {
  int ledb = analogRead(potent);
  ledb /= 4;
  analogWrite(led, ledb);
  delay(10);

  int brightness = analogRead(photores);
  // Serial.println(brightness);
  //brightness usually 167-173

  int t = analogRead(thermo);
  float res2 = themo_res * (1023.0 / t - 1.0);
  res2 = log(res2);
  float temp1 = (1.0 / (c1 + c2*res2 + c3*res2*res2*res2));
  temp1 -= 273.15;
  temp1 = (temp1*9.0)/5.0 + 32.0;
  int temp = int(temp1);
  // Serial.println(temp);
  //temp usually 72-75

  int hum = dht.readHumidity();
  // Serial.println(hum);
  //humidity usually 69-73
  temp1 = dht.readTemperature();
  temp1 = (temp1*9.0)/5.0 + 32.0;
  temp = int(temp1);

  if (update_pause % 4 == 0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(String(temp));
    lcd.print("-F");
    lcd.setCursor(0, 1);
    lcd.print("Bri: ");
    lcd.print(String(brightness));
    lcd.print("  Hum: ");
    lcd.print(String(hum));
  }
  update_pause++;

  Serial.println(digitalRead(button));

  if (digitalRead(button) == HIGH){
    buttonStop = !buttonStop;
  }

  if (brightness > bright_thresh && temp > temp_thresh && hum > hum_thresh && !buttonStop){
    // Serial.println("high");
    digitalWrite(dc_forward, HIGH);

  }
  else{
    // Serial.println("low");
    digitalWrite(dc_forward, LOW);
  }

  delay(150);
}
