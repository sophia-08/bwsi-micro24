
#define RGB_BUILTIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (int i = 0; i < 20; i++) {
    Serial.println(" ");
  }
}

void loop() {
  String color;
  Serial.println("what color? ");
  while (Serial.available() == 0) {}
  color = Serial.readString();
  Serial.println(color);

  if (color.equals("red")) {
    neopixelWrite(RGB_BUILTIN, 255, 0, 0);  // Red
    delay(1000);
  } else if (color.equals("orange")) {
    neopixelWrite(RGB_BUILTIN, 255, 165, 0);  // Orange (sort of)
    delay(1000);
  } else if (color.equals("yellow")) {
    neopixelWrite(RGB_BUILTIN, 255, 255, 0);  // Yellow (also sort of)
    delay(1000);
  } else if (color.equals("green")) {
    neopixelWrite(RGB_BUILTIN, 0, 255, 0);  // Green
    delay(1000);
  } else if (color.equals("blue")) {
    neopixelWrite(RGB_BUILTIN, 0, 0, 255);  // Blue
    delay(1000);
  } else if (color.equals("purple") || color.equals("violet")) {
    neopixelWrite(RGB_BUILTIN, 138, 43, 226);  // Purple
    delay(1000);
  } else if (color.equals("pink")) {
    neopixelWrite(RGB_BUILTIN, 227, 28, 121);  // Pink
    delay(1000);
  } else if (color.equals("white")) {
    neopixelWrite(RGB_BUILTIN, 255, 255, 255);  // White
    delay(1000);
  } else {
    Serial.println("i dont recognize that color");
    digitalWrite(RGB_BUILTIN, LOW);  // NA
    delay(1000);
  }
}