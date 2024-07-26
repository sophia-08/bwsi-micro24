#define thermo_pin A0
#define c1 1.009249522e-03
#define c2 2.378405444e-04
#define c3 2.019202697e-07

float res = 100000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int vo = analogRead(thermo_pin);
  float res2 = res * (1023.0 / vo - 1.0);
  float logr2 = log(res2);
  float t = (1.0 / (c1 + c2*logr2 + c3*logr2*logr2*logr2));
  t-=273.15;
  t = (t*9.0)/5.0 + 32.0;

  Serial.print("temp: ");
  Serial.print(t);
  Serial.println("°F");

  delay(500);
}
