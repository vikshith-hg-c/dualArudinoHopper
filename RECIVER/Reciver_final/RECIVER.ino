
#include <Wire.h>
int FH   = 0;
int BH   = 0;
int OnP  = 0;
int EP   = 0;
int FHFeed  = 0;
int BHFeed  = 0;
int Feed = 0;
int movement = 1;
int y = 1;
int FB = 0; 
int BB = 0; 
int FHO = 0;
int BHO = 0;
int OPS;
int EPS;



#define RL1   2
#define RL2   3
#define RL3   4
#define RL4   5
#define RL5   6
#define RL6   7
#define RL7   8
#define RL8   9
#define RL9  10
#define RL10 11
#define RL11 12
#define RL12 A1
#define BUZZAR A0

void setup() {
  Wire.begin(20);                
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);     
  pinMode(RL1,    OUTPUT);
  pinMode(RL2,    OUTPUT);
  pinMode(RL3,    OUTPUT);
  pinMode(RL4,    OUTPUT);
  pinMode(RL5,    OUTPUT);
  pinMode(RL6,    OUTPUT);
  pinMode(RL7,    OUTPUT);
  pinMode(RL8,    OUTPUT);
  pinMode(RL9,    OUTPUT);
  pinMode(RL10,   OUTPUT);
  pinMode(RL11,   OUTPUT);
  pinMode(RL12,   OUTPUT);
  pinMode(BUZZAR, OUTPUT);
  digitalWrite(RL1,LOW);
  digitalWrite(RL2,LOW);
  digitalWrite(RL3,LOW);
  digitalWrite(RL4,LOW);
  digitalWrite(RL5, HIGH);
  digitalWrite(RL6, HIGH);
  digitalWrite(RL7, HIGH);
  digitalWrite(RL8, HIGH);
  digitalWrite(RL9, HIGH);
  digitalWrite(RL10,HIGH);
  digitalWrite(RL11,HIGH);
  digitalWrite(RL12,HIGH);
  
  
  
 
}

void loop() {
              delay(5000);
              if( OnP < 15 ){OPS = 1; }
              if( EP < 15 ){EPS = 1; }
              if( OnP > 15 ){OPS = 0; }
              if( EP > 15 ){EPS = 0; }
              if( FHFeed > 30 ){FB = 0; }  //FEED Height Calibration
              if( FHFeed < 30){FB = 1; }
              if( BHFeed > 30 ){BB = 0; }
              if( BHFeed < 30 ){BB = 1; }
              if(Feed == 0){digitalWrite(BUZZAR , HIGH);}
              if(Feed == 1){digitalWrite(BUZZAR , LOW);}
                       
            
switch(movement)
    {
      case 0 : {digitalWrite(RL1, LOW);
                digitalWrite(RL2, LOW);
                delay(100);
                digitalWrite(RL3,HIGH);
                digitalWrite(RL4,HIGH);
                
        

                break;  }          
      case 1 : {
               digitalWrite(RL3, LOW);
               digitalWrite(RL4, LOW);
               delay(100);
               digitalWrite(RL1,HIGH);
               digitalWrite(RL2,HIGH);
                 /*if(FH < 15)
                  { if (FB == 1 && FHO == 0)
                         {HopperFront();}
                   if (FB == 0 && FHO == 1)
                         {HopperHalt();}
                   if (FB == 0 && FHO == 0)
                       {  delay(1000);
                          HopperHalt();
                          digitalWrite(RL7,HIGH);
                          digitalWrite(RL8,HIGH);
                          delay(20);
                          digitalWrite(RL5,LOW);
                          digitalWrite(RL6,LOW);
                          FHO = 1;
                          delay(650);                    //FRONT GATE OPEN DELAY
                          digitalWrite(RL5,HIGH);
                          digitalWrite(RL6,HIGH); 
                        }
                  if(FB == 1 && FHO == 1)
                        {  HopperHalt();
                           digitalWrite(RL5,HIGH);
                           digitalWrite(RL6,HIGH);
                           delay(20);
                           digitalWrite(RL7,LOW);
                           digitalWrite(RL8,LOW);
                           FHO = 0;
                           delay(900);                   // FRONT GATE CLOSE DELAY  
                           digitalWrite(RL7,HIGH);
                           digitalWrite(RL8,HIGH);
                           HopperFront();
                         }}*/
                if(BH < 15)
                  { if (BB == 1 && BHO == 0)
                         {HopperFront();}
                   if (BB == 0 && BHO == 1)
                         {HopperHalt();}
                   if (BB == 0 && BHO == 0)
                       {  HopperHalt();
                          digitalWrite(RL11,HIGH);
                          digitalWrite(RL12,HIGH);
                          delay(20);
                          digitalWrite(RL9,LOW);
                          digitalWrite(RL10,LOW);
                          BHO = 1;
                          delay(650);                   // BACK GATE OPEN DELAY
                          digitalWrite(RL9,HIGH);
                          digitalWrite(RL10,HIGH); 
                        }
                  if(BB == 1 && BHO == 1)
                        {  HopperHalt();
                           delay(100);
                           digitalWrite(RL9,HIGH);
                           digitalWrite(RL10,HIGH);
                           delay(20);
                           digitalWrite(RL11,LOW);
                           digitalWrite(RL12,LOW);
                           BHO = 0;
                           delay(900);                  // BACK GATE CLOSE DELAY   
                           digitalWrite(RL11,HIGH);
                           digitalWrite(RL12,HIGH);
                           HopperFront();
                           
                        }}}break;
            case 2 : {digitalWrite(RL1,LOW);
                      digitalWrite(RL2,LOW);
                      digitalWrite(RL3,LOW);
                      digitalWrite(RL4,LOW);
                      }break;  }
    
      


 if(FH > 15 && FHO == 1)
    { HopperHalt();
      digitalWrite(RL7,LOW);
      digitalWrite(RL8,LOW);
      FHO = 0;
      delay(900);                   // FRONT GATE CLOSE DELAY
      digitalWrite(RL7,HIGH);
      digitalWrite(RL8,HIGH); 
    }
 if(BH > 15 && BHO == 1)
    {
       HopperHalt();
       digitalWrite(RL11,LOW);
       digitalWrite(RL12,LOW);
       BHO = 0;
       delay(900);                // BACK GATE CLOSE DELAY
       digitalWrite(RL11,HIGH);
       digitalWrite(RL12,HIGH);
      
    }
}
       
                   
      
  
  

  

int receiveEvent(int a,int b,int c,int d) 
{
  while (1 < Wire.available()) 
  { 
    FH = Wire.read(); 
    BH= Wire.read();
    OnP = Wire.read();
    EP = Wire.read();
    FHFeed = Wire.read();
    BHFeed = Wire.read();
    Feed = Wire.read();
    Serial.print("Feed\t\t\t");
    Serial.println(Feed);
    Serial.print("Front Hopper:\t\t");
    Serial.print(FH);
    Serial.println("\tcm");
    Serial.print("Front Hopper Feed UTR :\t");
    Serial.print(FHFeed);
    Serial.println("\tcm");
    Serial.print("Back Hopper:\t\t");
    Serial.print(BH);
    Serial.println("\tcm");   
    Serial.print("Back Hopper Feed UTR :\t");
    Serial.print(BHFeed);
    Serial.println("\tcm");
    Serial.print("On Point:\t\t");
    Serial.print(OnP);
    Serial.println("\tcm");
    Serial.print("End Point:\t\t");
    Serial.print(EP);
    Serial.println("\tcm");
    movementcheck();
    movement = y; 
    Serial.println(movement);
    
    
  }
      
    
}
int movementcheck()
  {
    if(OPS == 0)
  {
    if(Feed == 1 && EPS == 1 || (Feed == 0))
      { y = 0;}
  }
  
  if(OPS == 1 && EPS == 0 && Feed == 1)
    { y = 1;}


  if (EPS == 0 && OPS == 1 && Feed ==0)
    {y = 2;}
   }
  
int HopperFront()
{ 
  digitalWrite(RL1,HIGH);
  digitalWrite(RL2,HIGH);
     
}

void HopperBack()
{ 
  digitalWrite(RL3,HIGH);
  digitalWrite(RL4,HIGH);
}


void HopperHalt()
{
  digitalWrite(RL1,LOW);
  digitalWrite(RL2,LOW);
  digitalWrite(RL3,LOW);
  digitalWrite(RL4,LOW);
       
}





