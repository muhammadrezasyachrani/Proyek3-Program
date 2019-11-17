#include <NewPing.h>
  
NewPing sonar1(6, 7, 11);
NewPing sonar2(4, 5, 17);
NewPing sonar3(2, 3, 17);

int jarakAtas = 10;
int jarakDepan = 17;
int jarakSamping = 17;

int tinggi, lebar, panjang, volume;
double berat_dimensi;
 
void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(2000);
  tinggi = jarakAtas - sonar1.ping_cm();
  Serial.print("Tinggi: ");
  Serial.print(tinggi);
  Serial.println(" cm");

  delay(2000);
  lebar = jarakSamping - sonar3.ping_cm();
  Serial.print("Lebar: ");
  Serial.print(lebar);
  Serial.println(" cm");

  delay(2000);
  panjang = jarakDepan - sonar2.ping_cm();
  Serial.print("Panjang: ");
  Serial.print(panjang);
  Serial.println(" cm");

  delay(2000);
  volume = panjang * lebar * tinggi;
  Serial.print("Volume: ");
  Serial.print(volume);
  Serial.println(" cm^3");

  delay(2000);
  berat_dimensi = volume / 4;
  Serial.print("Berat Dimensi: ");
  Serial.print(berat_dimensi);
  Serial.println(" gram");


 
 
}


  
