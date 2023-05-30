
#include <Wire.h>
int FH   = 0;
int BH   = 0;
int OnP  = 0;
int EP   = 0;
int FHFeed  = 0;
int BHFeed  = 0;
int Feed = 0;
int movement = 1;
int MovementVAR = 1;
int feedBox = 0;
int feedBoxVAR = 0;
int feedlevel = NULL;
int feedlevelVAR = NULL;
int FB = 0; 
int BB = 0; 
int FHG = 0;
int BHG = 0;
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
#define RL12 A2
#define BUZZAR A3

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
              delay(3000);
              if(Feed == 0){digitalWrite(BUZZAR , HIGH);}
              if(Feed == 1){digitalWrite(BUZZAR , LOW);}
                       
              if(FHG == 1)
                 {
                  digitalWrite(RL7,LOW);
                  digitalWrite(RL8,LOW);
                  FHG = 0;
                  delay(600);                   
                  digitalWrite(RL7,HIGH);
                  digitalWrite(RL8,HIGH);
                 } 
                        
              if(BHG == 1)
                 {
                  digitalWrite(RL11,LOW);
                  digitalWrite(RL12,LOW);
                  BHG = 0;
                  delay(600);                   
                  digitalWrite(RL11,HIGH);
                  digitalWrite(RL12,HIGH);
                 } 
                                 
            
              switch(movement)
                  {         
                    case 1 : { if(feedBoxVAR == 0)
                                   { digitalWrite(RL3,LOW);
                                    digitalWrite(RL4,LOW);delay(100);
                                    digitalWrite(RL1,HIGH);
                                    digitalWrite(RL2,HIGH);}
                                else if(feedBoxVAR != 0)
                                     {
                                       switch(feedBox)
                                       
                                          {    
                                          case 1 : {
                                                    switch(feedlevel)
                                                        {
                                                          case 1 : break;
                                                          case 2 : break;
                                                          case 3 : break;
                                                          case 4 : break;
                                                          case 5 : {  delay(2000);
                                                                        digitalWrite(RL1,LOW);
                                                                        digitalWrite(RL2,LOW);
                                                                        digitalWrite(RL3,LOW);
                                                                        digitalWrite(RL4,LOW);
                                                                     if(FHG == 0 && BHG == 0)
                                                                        digitalWrite(RL5,LOW);
                                                                        digitalWrite(RL6,LOW);
                                                                        digitalWrite(RL9,LOW);
                                                                        digitalWrite(RL10,LOW);
                                                                        FHG = 1;
                                                                        BHG = 1;
                                                                        delay(300);                   
                                                                        digitalWrite(RL5,HIGH);
                                                                        digitalWrite(RL6,HIGH);
                                                                        digitalWrite(RL9,HIGH);
                                                                        digitalWrite(RL10,HIGH);
                                                                   }break;
                                                          case 6 : {  
                                                                         if(FHG == 1 && BHG == 1)
                                                                         {digitalWrite(RL7,LOW);
                                                                          digitalWrite(RL8,LOW);
                                                                          digitalWrite(RL11,LOW);
                                                                          digitalWrite(RL12,LOW);
                                                                          FHG = 0;
                                                                          BHG = 0;
                                                                          delay(600);                   
                                                                          digitalWrite(RL7,HIGH);
                                                                          digitalWrite(RL8,HIGH);
                                                                          digitalWrite(RL11,HIGH);
                                                                          digitalWrite(RL12,HIGH);
                                                                          }
                                                                      else if(FHG == 1 && BHG == 0)
                                                                         {digitalWrite(RL7,LOW);
                                                                          digitalWrite(RL8,LOW);
                                                                          FHG = 0;
                                                                          delay(600);                   
                                                                          digitalWrite(RL7,HIGH);
                                                                          digitalWrite(RL8,HIGH);
                                                                          }
                                                                        else if(FHG == 0 && BHG == 1)
                                                                         {digitalWrite(RL11,LOW);
                                                                          digitalWrite(RL12,LOW);
                                                                          BHG = 0;
                                                                          delay(600);                   
                                                                          digitalWrite(RL11,HIGH);
                                                                          digitalWrite(RL12,HIGH);
                                                                       
                                                                        if(FHG == 0 && BHG == 0)
                                                                         { digitalWrite(RL1,HIGH);
                                                                            digitalWrite(RL2,HIGH);
                                                                            digitalWrite(RL3,LOW);
                                                                            digitalWrite(RL4,LOW);
                                                                          }}break;
                                                            case 7 : {  delay(2000);
                                                                        digitalWrite(RL1,LOW);
                                                                        digitalWrite(RL2,LOW);
                                                                        digitalWrite(RL3,LOW);
                                                                        digitalWrite(RL4,LOW);
                                                                         if(FHG == 1)
                                                                         {digitalWrite(RL7,LOW);
                                                                          digitalWrite(RL8,LOW);
                                                                          FHG = 0;
                                                                          delay(900);                   
                                                                          digitalWrite(RL7,HIGH);
                                                                          digitalWrite(RL8,HIGH); 
                                                                         }
                                                                        if(BHG == 0);
                                                                          digitalWrite(RL9,LOW);
                                                                          digitalWrite(RL10,LOW);
                                                                          BHG = 1;
                                                                          delay(300);                   
                                                                          digitalWrite(RL9,HIGH);
                                                                          digitalWrite(RL10,HIGH);
                                                                         }

                                                                      }break;
                                                            case 8 : {  delay(2000);
                                                                        digitalWrite(RL1,LOW);
                                                                        digitalWrite(RL2,LOW);
                                                                        digitalWrite(RL3,LOW);
                                                                        digitalWrite(RL4,LOW); 
                                                                         if(BHG == 1)
                                                                         {digitalWrite(RL11,LOW);
                                                                          digitalWrite(RL12,LOW);
                                                                          BHG = 0;
                                                                          delay(900);                   
                                                                          digitalWrite(RL11,HIGH);
                                                                          digitalWrite(RL12,HIGH); 
                                                                         }
                                                                         if ( FHG == 0)
                                                                         {
                                                                          digitalWrite(RL5,LOW);
                                                                          digitalWrite(RL6,LOW);
                                                                          FHG = 1;
                                                                          delay(600);                   
                                                                          digitalWrite(RL5,HIGH);
                                                                          digitalWrite(RL6,HIGH);
                                                                         }
                                                                         
                                                                      }break;
                                                            default :  break;}
                                                       }break;
                                             case  2 : { 
                                                         switch(feedlevel)
                                             
                                                            {
                                                              case 1 : {delay(3000);
                                                                        digitalWrite(RL1,LOW);
                                                                        digitalWrite(RL2,LOW);
                                                                        digitalWrite(RL3,LOW);
                                                                        digitalWrite(RL4,LOW);
                                                                        if(FHG == 0)
                                                                           {
                                                                            digitalWrite(RL5,LOW);
                                                                            digitalWrite(RL6,LOW);
                                                                            FHG = 1;
                                                                            delay(300);                   
                                                                            digitalWrite(RL5,HIGH);
                                                                            digitalWrite(RL6,HIGH);
                                                                           } 
                                                                         }break;
                                                              case 2 : {
                                                                         if(FHG == 1)
                                                                           {
                                                                            digitalWrite(RL7,LOW);
                                                                            digitalWrite(RL8,LOW);
                                                                            FHG = 0;
                                                                            delay(600);                   
                                                                            digitalWrite(RL7,HIGH);
                                                                            digitalWrite(RL8,HIGH);
                                                                           
                                                                           } 
                                                                          if(FHG == 0)
                                                                          {
                                                                            digitalWrite(RL1,HIGH);
                                                                            digitalWrite(RL2,HIGH);
                                                                            digitalWrite(RL3,LOW);
                                                                            digitalWrite(RL4,LOW);
                                                                          }
                                                                          }break;
                                                              case 3  : break;
                                                              case 4  : break;
                                                              case 5  : break;
                                                              case 6  : break;
                                                              case 7  : break;
                                                              case 8  : break;
                                                              default :  break;}
                                                      }break;
                                             case  3 : { 
                                                      switch(feedlevel)
                                                         {
                                                         case 1 : break;
                                                         case 2 : break;
                                                         case 3 : {delay(3000);
                                                                  digitalWrite(RL1,LOW);
                                                                  digitalWrite(RL2,LOW);
                                                                  digitalWrite(RL3,LOW);
                                                                  digitalWrite(RL4,LOW);
                                                                  if(BHG == 0)
                                                                     {
                                                                      digitalWrite(RL9,LOW);
                                                                      digitalWrite(RL10,LOW);
                                                                      BHG = 1;
                                                                      delay(300);                   
                                                                      digitalWrite(RL9,HIGH);
                                                                      digitalWrite(RL10,HIGH);
                                                                     } 
                                                                   }break;
                                                        case 4  :{
                                                                   if(BHG == 1)
                                                                     {
                                                                      digitalWrite(RL11,LOW);
                                                                      digitalWrite(RL12,LOW);
                                                                      BHG = 0;
                                                                      delay(600);                   
                                                                      digitalWrite(RL11,HIGH);
                                                                      digitalWrite(RL12,HIGH);
                                                                     
                                                                     } 
                                                                    if(BHG == 0)
                                                                    {
                                                                      
                                                                   
                                                                      digitalWrite(RL3,LOW);
                                                                      digitalWrite(RL4,LOW);
                                                                      delay(50);
                                                                      digitalWrite(RL5,HIGH);
                                                                      digitalWrite(RL6,HIGH);
                                                                    }
                                                                    }break;
                                                        case 5  : break;
                                                        case 6  : break;
                                                        case 7  : break;
                                                        case 8  : break;
                                                        default :  break;}
                                                 }break;  
                                             default :  break;}              
                             }}break; 
                    case 2 : {
                              digitalWrite(RL1,LOW);
                              digitalWrite(RL2,LOW);
                              delay(100);
                              digitalWrite(RL3,HIGH);
                              digitalWrite(RL4,HIGH);
                              }break;
                     case 3 : {
                              digitalWrite(RL1,LOW);
                              digitalWrite(RL2,LOW);
                              digitalWrite(RL3,LOW);
                              digitalWrite(RL4,LOW);
                              }break;
                      default : break;
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
    movement = MovementVAR;
    Serial.print(movement);
    Serial.println("\t\t\t << 1->FRONT >> << 2->BACK>>  <<3->HALT>>");  
    feedBoxCheck();
    feedBox = feedBoxVAR;
    feedlevelCheck();
    feedlevel = feedlevelVAR;
    if(feedBox != 0)
    {
    Serial.print(feedBox);
    switch(feedBox)
          {               case 1 : {Serial.println("\t\t\t << Front box and back box FOUND");
                       Serial.print(feedlevel);
                       switch(feedlevel) 
                         {case 1 : break;
                          case 2 : break;
                          case 3 : break;
                          case 4 : break;
                          case 5 :  {Serial.println("\t\t\t << Front box and Back box are EMPTY");break;}
                          case 6 :  {Serial.println("\t\t\t << Front box and Back box are FULL");break;} 
                          case 7 :  {Serial.println("\t\t\t << Front box -> FULL : Back box -> EMPTY");break;}
                          case 8 :  {Serial.println("\t\t\t << Front box -> EMPTY : Back box -> FULL");break;}
                          default : break;
                         }
                        break;}
              case 2 : {Serial.println("\t\t\t << Front box FOUND");
                        Serial.print(feedlevel);
                        switch(feedlevel) 
                         {case 1 : {Serial.println("\t\t\t << Front box is EMPTY");break;}
                          case 2 : {Serial.println("\t\t\t << Front box is FULL");break;}
                          case 3 :  break;
                          case 4 :  break;
                          case 5 :  break;
                          case 6 :  break; 
                          case 7 :  break;
                          case 8 :  break;
                          default : break;
                         }
                         break;}
              case 3 : {Serial.println("\t\t\t << Back box FOUND");
                        Serial.print(feedlevel);
                        switch(feedlevel) 
                         {case 1 : break; 
                          case 2 : break;
                          case 3 : {Serial.println("\t\t\t << Back box is EMPTY");break;}
                          case 4 : {Serial.println("\t\t\t << Back box is FULL");break;}
                          case 5 :  break;
                          case 6 :  break; 
                          case 7 :  break;
                          case 8 :  break;
                          default : break;
                         }
                         break;}
          
               
                                   
                       
          }  
  }
  else Serial.println("##################Hopper MOVING #####################");
    
  }    
}
int movementcheck()
{   
   
    if( OnP < 15 ){OPS = 1; }
    if( EP < 15 ){EPS = 1; }
    if( OnP > 15 ){OPS = 0; }
    if( EP > 15 ){EPS = 0; }

    if(OPS == 0)
  { 
    if(Feed == 1 && EPS == 1 || (Feed == 0))
      { MovementVAR = 2;}
  }
  
  if(OPS == 1 && EPS == 0 && Feed == 1)
      { MovementVAR = 1;}


  if (EPS == 0 && OPS == 1 && Feed ==0)
      { MovementVAR = 3;}
   }

int feedBoxCheck()
   {
    if ((FH > 15 && BH > 15))
        {feedBoxVAR = 0;}
    if (FH < 15 && BH < 15)
       {feedBoxVAR = 1;}
    if( FH < 15 && BH > 15)
       {feedBoxVAR = 2;}
    if( BH < 15 && FH >15)
       {feedBoxVAR = 3;} 
    
   }
int feedlevelCheck()
   {
    if(feedBoxVAR != 0)
        {
        if( FHFeed > 30 && FHFeed < 37 && FH < 15  && BH > 15)
            {  feedlevelVAR = 1;}                               
        if( FHFeed < 30 && FH < 15  && BH > 15)
            {  feedlevelVAR = 2;}
        if( BHFeed > 30 && BHFeed < 37  && BH < 15 && FH > 15)
            {  feedlevelVAR = 3;}
        if( BHFeed < 30 && BH < 15 && FH > 15)
            {  feedlevelVAR = 4;}
        if( FHFeed > 30 && FHFeed < 37 && FH < 15 && BH < 15 && BHFeed > 30 && BHFeed < 37 )
            {  feedlevelVAR = 5;}
        if( FHFeed < 30 && FH < 15 && BH < 15 && BHFeed < 30)
            {  feedlevelVAR = 6;}
        if( FHFeed < 30 && FH < 15 && BH < 15 && BHFeed > 30 && BHFeed < 37 )
            {  feedlevelVAR = 7;}
        if( FHFeed > 30 && FHFeed < 37 && FH < 15 && BH < 15 && BHFeed < 30)
            {  feedlevelVAR = 8;}
   }}
    
    
    





