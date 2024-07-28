#include <LiquidCrystal.h>// include the library code
/**********************************************************/
char array1[]=" motion >:0               ";  //the string to print on the LCD
// char array2[]="hello, world!             ";  //the string to print on the LCD
int tim = 150;  //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/

#define pir_pin A0
#define led_pin 2

void setup()
{
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  pinMode(pir_pin, INPUT);
}
/*********************************************************/
void loop() 
{
  int val = analogRead(pir_pin);
  if (val > 512){
    digitalWrite(led_pin, HIGH);
    delay(800);
    digitalWrite(led_pin, LOW);
    lcd.setCursor(15,0);  // set the cursor to column 15, line 0
    for ( int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
    {
      lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
      lcd.print(array1[positionCounter1]);  // Print a message to the LCD.
      delay(tim);  //wait for 250 ms
    }
    lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.
    delay(100);

    // if (state == LOW){
    //   Serial.println("motion detected");
    //   state = HIGH;
    // }
  }
  else{
    digitalWrite(led_pin, LOW);
    delay(200);
    // if (state == HIGH){
    //   Serial.println("motion stopped");
    //   state = LOW;
    // }
  }
  delay(500);
    // lcd.setCursor(15,1);  // set the cursor to column 15, line 1
    // for (int positionCounter2 = 0; positionCounter2 < 26; positionCounter2++)
    // {
    //   lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
    //   lcd.print(array2[positionCounter2]);  // Print a message to the LCD.
    //   delay(tim);  //wait for 250 ms
    // }
    // lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.
}