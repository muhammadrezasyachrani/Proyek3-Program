int trigPin1 = 6;
int echoPin1 = 7;
int trigPin2 = 4;
int echoPin2 = 5;
int trigPin3 = 2;
int echoPin3 = 3;
double jarakAtas = 30.00;
double jarakSamping = 30.00;
double jarakDepan = 30.00;

long duration1, duration2, duration3;
double jarak1, jarak2, jarak3, tinggi, lebar, panjang, volume;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

duration1 = pulseIn(echoPin1, HIGH);
jarak1 = duration1*0.034/2;
tinggi = jarakAtas - jarak1;
delay (1000);

Serial.print("Tinggi: ");
Serial.println(tinggi);

digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

duration2 = pulseIn(echoPin2, HIGH);
jarak2 = duration2*0.034/2;
lebar = jarakSamping - jarak2;
delay (1000);

Serial.print("Lebar: ");
Serial.println(lebar);

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);

duration3 = pulseIn(echoPin3, HIGH);
jarak3 = duration3*0.034/2;
panjang = jarakDepan - jarak3;
delay (1000);

Serial.print("Panjang: ");
Serial.println(panjang);

volume = panjang * lebar * tinggi;
Serial.print("Volume: ");
Serial.println(volume);


}
