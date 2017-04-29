#define trig 5
#define echo 6

int LDRPin = A0;
int LDRValue= 0;
void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
void loop()
{
  int ledPin = 9;
  float maximumRange = 50.00;
  float minimumRange = 1.0;
  int fadeValue = 0;
  int x = 0;
  float duration;
  float distance;
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  Serial.print("distance in cm");
  Serial.println(distance);
  LDRValue = analogRead(LDRPin);
  Serial.println(LDRValue);
  if (LDRValue<=1000)
  {
    
  if(distance >= minimumRange && distance <= maximumRange )
  {
    fadeValue=(int)((maximumRange-distance)*255)/maximumRange;
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
  else
  {
    analogWrite(ledPin, 0);
    delay(30);
  }
}
}




