#include <Keypad.h>

const int red_led = 2;
const int yel_led = 3;
const int green_led = 4;

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {5, 6, 7, 8}; 
byte colPins[COLS] = {9, 10, 11, 12}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

char password [4] = {};
bool locked = true;

void setup(){
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(yel_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (locked){
    digitalWrite(red_led, HIGH);
    digitalWrite(yel_led, LOW);
    digitalWrite(green_led, LOW);
    if (customKey){
      if (customKey == '*'){
        Serial.println(customKey);
        digitalWrite(red_led, LOW);
        digitalWrite(yel_led, HIGH);
        int i = 0;
        while (i<5){
          customKey = customKeypad.getKey();
          if (customKey){
            password[i] = customKey;
            Serial.println(password[i]);
            i++;
          }
          delay(100);
        }
      }
      else{
        
      }
    }
  }
  else{
    digitalWrite(red_led, LOW);
    digitalWrite(yel_led, LOW);
    digitalWrite(green_led, HIGH);
    i = 0;
    while (i<5){
        customKey = customKeypad.getKey();
        if (customKey){
          password[i] = customKey;
          Serial.println(password[i]);
          i++;
        }
        delay(100);
      }
      locked = false;
    }
  }
  delay(100);

  // if (customKey.compareTo("")){
  //   Serial.println(customKey);
  // }
}