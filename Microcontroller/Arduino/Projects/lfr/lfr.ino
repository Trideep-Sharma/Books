int lir=8;
int cir=9;
int rir=10;
int EN1=2;
int EN2=3;
int MC11=4;
int MC12=5;
int MC21=6;
int MC22=7;
void left(){
digitalWrite(EN1, LOW);
digitalWrite(MC11, HIGH);
digitalWrite(MC12, LOW);
analogWrite(EN1, HIGH);
digitalWrite(EN2, LOW);
digitalWrite(MC21, LOW);
digitalWrite(MC22, LOW);
digitalWrite(EN2, HIGH);
}
void right(){
digitalWrite(EN1, LOW);
digitalWrite(MC11, LOW);
digitalWrite(MC12, LOW);
digitalWrite(EN1, HIGH); 
digitalWrite(EN2, LOW);
digitalWrite(MC21, HIGH);
digitalWrite(MC22, LOW);
analogWrite(EN2, HIGH);
}
void straight(){
digitalWrite(EN1, LOW);
digitalWrite(MC11, HIGH);
digitalWrite(MC12, LOW);
analogWrite(EN1, HIGH);
digitalWrite(EN2, LOW);
digitalWrite(MC21, HIGH);
digitalWrite(MC22, LOW);
analogWrite(EN2, HIGH);
}
void brek(){
digitalWrite(EN1, LOW);
digitalWrite(MC11, LOW);
digitalWrite(MC12, LOW);
digitalWrite(EN1, HIGH);
digitalWrite(EN2, LOW);
digitalWrite(MC21, LOW);
digitalWrite(MC22, LOW);
digitalWrite(EN2, HIGH);
}
void setup(){
  pinMode(lir,INPUT);
  pinMode(cir,INPUT);
  pinMode(rir,INPUT);
  pinMode(EN1,OUTPUT);
  pinMode(EN2,OUTPUT);
  pinMode(MC11,OUTPUT);
  pinMode(MC12,OUTPUT);
  pinMode(MC21,OUTPUT);
  pinMode(MC22,OUTPUT);
  
}
void loop(){
 boolean ls = digitalRead(lir);
 boolean cs = digitalRead(cir);
 boolean rs = digitalRead(rir);
 if ((ls==0)&&(cs==1)&&(rs==0))
 {
  straight();
 }
 if((ls==0)&&(cs==0)&&(rs==1)){
  left();
 }
 if((ls==1)&&(cs==0)&&(rs==0)){
  right();
 }
 if((ls==0)&&(cs==0)&&(rs==0)){
  brek();
 }
 if((ls==1)&&(cs==1)&&(rs==1)){
  brek();
 }
}

