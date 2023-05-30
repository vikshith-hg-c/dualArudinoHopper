#include <Wire.h>


int FH = 0;
int BH = 0;
int OnP = 0;
int EP = 0;
int FHFeed = 0;
int BHFeed = 0;
int Feed = 0;


#define FeedSensor      A0
#define FrontHopperTrig 2
#define FrontHopperEcho 3
#define BackHopperTrig  4
#define BackHopperEcho  5
#define OnPointTrig     6
#define OnpointEcho     7
#define EndPointTrig    8
#define EndPointEcho    9
#define FeedFrontTrig   10
#define FeedFrontEcho   11
#define FeedBackTrig    12
#define FeedBackEcho    13


long duration,distance;

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(FeedSensor     , INPUT);
  pinMode(FrontHopperEcho, INPUT);
  pinMode(BackHopperEcho , INPUT);
  pinMode(OnpointEcho    , INPUT);
  pinMode(EndPointEcho   , INPUT);
  pinMode(FeedFrontEcho  , INPUT);
  pinMode(FeedBackEcho   , INPUT);
  
  pinMode(FrontHopperTrig, OUTPUT);
  pinMode(BackHopperTrig , OUTPUT);
  pinMode(OnPointTrig    , OUTPUT);
  pinMode(EndPointTrig   , OUTPUT);
  pinMode(FeedFrontTrig  , OUTPUT);
  pinMode(FeedBackTrig   , OUTPUT);
 }


void loop() 
{
  Feed = !digitalRead(FeedSensor);
  
  UTRSensor(FrontHopperTrig, FrontHopperEcho);
  FH = distance;
  UTRSensor(FeedFrontTrig, FeedFrontEcho);
  FHFeed = distance;
  
  UTRSensor(BackHopperTrig  ,BackHopperEcho );
  BH = distance;
  UTRSensor(FeedBackTrig, FeedBackEcho);
  BHFeed = distance;
  
  UTRSensor(OnPointTrig , OnpointEcho);
  OnP = distance;
  
  UTRSensor(EndPointTrig , EndPointEcho);
  EP = distance;
  
  Serial.print("Feed:\t\t");
  Serial.println(Feed);
  
  Serial.print("Front Hopper UTR:\t");
  Serial.print(FH);
  Serial.println("\tcm");
  Serial.print("Front Hopper Feed UTR:\t");
  Serial.print(FHFeed);
  Serial.println("\tcm");
  
  Serial.print("Back Hopper UTR:\t");
  Serial.print(BH);
  Serial.println("\tcm");
  Serial.print("Back Hopper Feed UTR:\t");
  Serial.print(BHFeed);
  Serial.println("\tcm");
  
  Serial.print("On Point UTR:\t\t");
  Serial.print(OnP);
  Serial.println("\tcm");
  
  Serial.print("End Point UTR:\t\t");
  Serial.print(EP);
  Serial.println("\tcm");
  
  
  Wire.beginTransmission(20);
  Wire.write(FH);
  Wire.write(BH);
  Wire.write(OnP);
  Wire.write(EP);
  Wire.write(FHFeed);
  Wire.write(BHFeed);
  Wire.write(Feed);
  Wire.endTransmission();
  delay(100);
}
float UTRSensor(int trigpin,int echoPin)
{ 
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay(10);
}

          

