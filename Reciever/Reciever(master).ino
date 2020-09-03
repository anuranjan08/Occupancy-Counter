#include <SoftwareSerial.h>
SoftwareSerial mySerial(8,9);

int var;
int count;
int buzzer= 11;
int threshold=520;
int limit=50;
int val;
void setup() {
  pinMode(buzzer,OUTPUT);   
  Serial.begin(9600);
  mySerial.begin(9600);
  
}

void loop() {
        if (mySerial.available()) {
    char c = mySerial.peek(); // just look at the next character on the serial buffer
    if (c == '\r' || c == '\n') // ignore the carriage return and newline characters
      mySerial.read(); // remove the character from serial buffer by reading it
    else {
      var= mySerial.parseInt(); // read and parse the string representing the integer value
      Serial.println(var);
      val=var-threshold;
      if(val>limit){
       count=val/limit;
       Serial.println(count);
       if(count==4){
         tone(buzzer,1000,2000);
         count=0;
        }
       
        
}
else{
  Serial.println("room is empty");
}
      
      }
    }
  }
