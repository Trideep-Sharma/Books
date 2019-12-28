#include <LiquidCrystal.h>
float v=0;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
pinMode(11,OUTPUT);
pinMode(A0,INPUT);
analogWrite(11,100); 
lcd.begin(16, 2);
lcd.print("    VOLTMETER");
}
void loop()
{
v=analogRead(A0);
v=(v+1)/1024.00;
v=v*5.00;
v=v*11.00;
lcd.setCursor(6,1);
lcd.print(v); 
lcd.print(" V");
delay(1000);
}
