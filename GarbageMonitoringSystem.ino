/*Garbage Monitoring System by Hizon Pastorpili
if you're using this code please consider subscribing*/

int Limit = 27; //height limit of your garbage bin in cm
const int trigPin = 3;
const int echoPin = 2;
long duration, percentage, range;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  percentage = (duration / 2) / 29.1 / Limit * 100;
  range = 100 - percentage;

if ((range >= 0) && (range <= 100))
  {
    if (range > 70)
      {
        Serial.print("F ");
      }
    if ((range >= 30) && (range <= 70))
      {
        Serial.print("M ");
      }
    if (range <= 30)
      {
        Serial.print("E ");
      }
    
     Serial.print(range);
     Serial.println();
     delay(500);
  }
  
else
 {
  Serial.print("F 100");
  Serial.println();
  delay(500);
 }

}
