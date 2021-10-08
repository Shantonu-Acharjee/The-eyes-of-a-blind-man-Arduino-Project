int trigPinA =8;//l
int echoPinA =A1;

int trigPinB =A2;//m 
int echoPinB =A3;

int trigPinC =A4;
int echoPinC =A5;

long durationA;//L
int distanceA;

long durationB;//M
int distanceB;

long durationC;//R
int distanceC;


int buzzer = 13;
int LDR = A0;
int LDRState=0;


void setup() 
{
 pinMode(trigPinA,OUTPUT);//L
 pinMode(echoPinA,INPUT);

 pinMode(trigPinB,OUTPUT);//M
 pinMode(echoPinB,INPUT);

 pinMode(trigPinC,OUTPUT);//R
 pinMode(echoPinC,INPUT);
 pinMode(LDR,INPUT);
 Serial.begin(9600);
  
}



void loop() {
//L
digitalWrite(trigPinA,LOW);
delayMicroseconds(2);
digitalWrite(trigPinA,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinA,LOW);
durationA=pulseIn(echoPinA,HIGH);
distanceA = durationA*0.034/2;
//(distanceA >= 50)?digitalWrite(buzzer,HIGH):digitalWrite(buzzer,LOW);
//L

//M
digitalWrite(trigPinB,LOW);
delayMicroseconds(2);
digitalWrite(trigPinB,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinB,LOW);
durationB=pulseIn(echoPinB,HIGH);
distanceB = durationB*0.034/2;
//(distanceB >= 50)?digitalWrite(buzzer,HIGH):digitalWrite(buzzer,LOW);
//M

//R
digitalWrite(trigPinC,LOW);
delayMicroseconds(2);
digitalWrite(trigPinC,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinC,LOW);
durationC=pulseIn(echoPinC,HIGH);
distanceC = durationC*0.034/2;

//R

(distanceA >= 50 || distanceB >= 50 || distanceC >= 50)?digitalWrite(buzzer,HIGH):digitalWrite(buzzer,LOW);

//LDR
LDRState=analogRead(LDR);
if(LDRState >= 50){
digitalWrite(buzzer,HIGH);
delay(20);
digitalWrite(buzzer,LOW);
delay(20);
}
else{
digitalWrite(buzzer,LOW);
//LDR

Serial.println(distanceA);
}
}
