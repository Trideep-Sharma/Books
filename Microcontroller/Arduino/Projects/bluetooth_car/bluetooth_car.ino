#include<SoftwareSerial.h>
int var=0;
int e1=0;
int l1=2;
int l2=3;
int e2=1;
int r1=4;
int r2=5;
SoftwareSerial myserial(10,11);
void battery()
{
  int volt=(analogRead(A0)/1024)*10;
  myserial.println(volt);
}
void brake()
{
digitalWrite(e1, LOW);
digitalWrite(e2, LOW);
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(r1, LOW);
digitalWrite(r2, LOW);
digitalWrite(e1, HIGH);
digitalWrite(e2, HIGH);
battery();
}
void forward ()
{
digitalWrite(e1, LOW);
digitalWrite(e2, LOW);
digitalWrite(l1, HIGH);
digitalWrite(l2, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, LOW);
digitalWrite(e1, HIGH);
digitalWrite(e2, HIGH);
battery();
}
void left()
{
digitalWrite(e1, LOW);
digitalWrite(e2, LOW);
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, LOW);
digitalWrite(e1, HIGH);
digitalWrite(e2, HIGH);
battery();
}
void right()
{
digitalWrite(e1, LOW);
digitalWrite(e2, LOW);
digitalWrite(l1, HIGH);
digitalWrite(l2, LOW);
digitalWrite(r1, LOW);
digitalWrite(r2, LOW);
digitalWrite(e1, HIGH);
digitalWrite(e2, HIGH);  
battery();
}
void setup()
{
 myserial.begin(9600);
 pinMode(e1,OUTPUT);
 pinMode(e2,OUTPUT);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(A0,INPUT);
 brake();
}
void loop()
{
  battery();
  while( !myserial.available() ); 
  battery();      
  var = myserial.read()-'0';        
  if(var==1)
  {forward();}
  if(var==2)
  {brake();}
  if(var==4)
  {right();}
  if(var==3)
  {left();}
  myserial.flush();
  }

