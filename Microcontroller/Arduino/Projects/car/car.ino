#include<LiquidCrystal.h>
#include<SD.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
byte p[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B10000,
};
byte d[8] = {
B00001,
B00001,
B00001,
B00001,
B00001,
B00101,
B00011,
B10001,
};
byte u[8] = {
B10000,
B11000,
B10100,
B10000,
B10000,
B10000,
B10000,
B10000,
};
int CS_PIN = 10;
int EN1;
int EN2;
int MC11;
int MC12;
int MC21;
int MC22;
class car
{
  private: 
  int choice;
  int direct();
  String filename;
  //char filename[20];
  void straight();
  void reverse();
  void left();
  void right();
  void brake();
  void menu(); 
  public:
  void sdcard();
  void bluetooth();
}c;
void car::straight()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(MC11,HIGH);
  digitalWrite(MC12,LOW);
  digitalWrite(MC21,HIGH);
  digitalWrite(MC22,LOW);
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
}
void car::reverse()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(MC11,LOW);
  digitalWrite(MC12,HIGH);
  digitalWrite(MC21,LOW);
  digitalWrite(MC22,HIGH);
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
}
void car::left()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(MC11,HIGH);
  digitalWrite(MC12,LOW);
  digitalWrite(MC21,LOW);
  digitalWrite(MC22,LOW);
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
}
void car::right()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(MC11,LOW);
  digitalWrite(MC12,LOW);
  digitalWrite(MC21,HIGH);
  digitalWrite(MC22,LOW);
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
}
void car::brake()
{
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(MC11,LOW);
  digitalWrite(MC12,LOW);
  digitalWrite(MC21,LOW);
  digitalWrite(MC22,LOW);
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
}
void car::menu()
{
  lcd.setCursor(7,0);
  lcd.print("MENU");
  while(!Serial.available())
  {lcd.setCursor(0,1);
  lcd.print("1.NEW");
  lcd.setCursor(14,1);
  lcd.write(1);
  lcd.write(2);
  delay(1000);
  lcd.clear();
  lcd.print("2.LOAD");
  lcd.setCursor(0,1);
  lcd.print("3.DELETE");
  lcd.setCursor(14,1);
  lcd.write(1);
  lcd.write(2);}
  choice=Serial.read();
  Serial.flush();
  if(choice==1)
  {
    lcd.clear();
    lcd.print("ENTER THE NAME FOR THE NEW DRIVE");
    Serial.print("ENTER THE NAME FOR THE NEW DRIVE");
    while(!Serial.available());
    filename=Serial.readString();
    //strcpy(filename,Serial.readString());
    File dataFile = SD.open(filename, FILE_WRITE);
    lcd.clear():
    lcd.print("TEACH IT WITH MOBILE");
    Serial.print("TEACH");
    
  }
}
void setup(){
  Serial.begin(9600);
  lcd.createChar(0, p);
  lcd.createChar(1, d);
  lcd.createChar(2, u);
  pinMode(CS_PIN, OUTPUT);
  pinMode(POW_PIN, OUTPUT);
  digitalWrite(POW_PIN, HIGH);
  SD.begin(CS_PIN);
  lcd.begin();
  c.menu();
  
}
void loop(){
 
}

