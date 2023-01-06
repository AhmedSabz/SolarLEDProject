// C++ code
//
#include <Servo.h>
Servo myservo;
int pos=0;
//use <300 for on
//use >300 for off
void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);//left photoresistor
  pinMode(A2,INPUT);//right photoresistor

}

void loop()
{
 int val=analogRead(A0);
  int photo1=analogRead(A1);
  int photo3=analogRead(A2);
  myservo.write(pos);
  if(val<300){//represents nighttime
    digitalWrite(10,HIGH);
  }
  if(val>=300){//represents daytime
    digitalWrite(10,LOW);
  }
  if(photo1>photo3 && val>=300){//photo1 is on left. light will come from the left
                                //the servo motor will face the left
    myservo.write(15);
    delay(250);
  }
  if(photo3>photo1 && val>=300){//photo3 is on the right.
                                //the servo motor will face the right
    myservo.write(178);
    delay(250);
  }
}
