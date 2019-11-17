#include "HX711.h" //memasukan library HX711

#define DOUT  A1 //mendefinisikan pin arduino yang terhubung dengan pin DT module HX711
#define CLK  A0 //mendefinisikan pin arduino yang terhubung dengan pin SCK module HX711

HX711 scale(DOUT, CLK);

float calibration_factor = -393; //nilai kalibrasi awal
int GRAM;

void setup() {
  Serial.begin(9600);
  scale.set_scale();
  scale.tare();
}

void loop() {
  delay(4000);
  scale.set_scale(calibration_factor);
  GRAM = scale.get_units(), 4;
  Serial.print(GRAM);
  Serial.println(" gram");
}
