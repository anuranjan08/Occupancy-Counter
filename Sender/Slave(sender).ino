 #include <SoftwareSerial.h>
SoftwareSerial mySerial(8,9);

int smokeA0 = A5;
int smokeA1 = A4;




void setup() {
  pinMode(smokeA0, INPUT);
  pinMode(smokeA1,INPUT);
  mySerial.begin(9600);
  delay(9000);
}

void loop() {
  int analogSensor0 = analogRead(smokeA0);
  int analogSensor1 = analogRead(smokeA1);
  int total= analogSensor0+analogSensor1;
  mySerial.println(total);
  delay(4000);
 
}
