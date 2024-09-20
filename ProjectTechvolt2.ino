#include<Servo.h>
Servo myservo;
bool isRaining=false;
void setup() {
  pinMode(8,INPUT);
  Serial.begin(9600);
  myservo.attach(3);
  myservo.write(0);
}
void loop() {
  int i=digitalRead(8);
  if(i==LOW&&!isRaining){
    Serial.print("YES");
    myservo.write(180);
    Serial.println("Forward");
    isRaining=true;
    delay(1000);
  }
  else if((i==HIGH&&isRaining)){
    Serial.print("NO");
    myservo.write(0);
    Serial.println("Backward");
    isRaining=false;
    delay(1000);
  }
}
