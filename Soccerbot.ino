/* NRF SOCCERBOT CODE */
#include <Servo.h>
Servo myservo;
int pos = 0;
//declaring global variable 
char command = 'S';
char prevCommand = 'A'; //random command 
unsigned long timer0 = 2000;  //Stores the time (in millis since execution started) 
unsigned long timer1 = 0;  //Stores the time when the last command was received from the phone

#define mot1a 4
#define mot1b 5
#define mot2a 10
#define mot2b 11
#define mot3a 6
#define mot3b 7
#define mot4a 8
#define mot4b 9


void setup() 
{   
  pinMode(mot1a,OUTPUT);
  pinMode(mot1b,OUTPUT);
  pinMode(mot2a,OUTPUT);
  pinMode(mot2b,OUTPUT);
  pinMode(mot3a,OUTPUT);
  pinMode(mot3b,OUTPUT);
  pinMode(mot4a,OUTPUT);
  pinMode(mot4b,OUTPUT);   
  Serial.begin(9600);  //Set the baud rate to that of your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){      //if bluetooth signal is received
    timer1 = millis();   
    prevCommand = command;
    command = Serial.read(); 
    //Change pin mode only if new command is different from previous.   
    if(command!=prevCommand){
      Serial.println(command);
      switch(command){
      case 'F':  // Left 3 wheels will moveanticlockwise and right 3 will move clockwise and callibrate it for which condition( either a=1,b=0 or a=0,b=1 motor moves clockwise and anticlockwise

          digitalWrite(mot1a,1);
          digitalWrite(mot1b,0);
    
          digitalWrite(mot2a,1);
          digitalWrite(mot2b,0);
  
          digitalWrite(mot3a,1);
          digitalWrite(mot3b,0);

          digitalWrite(mot4a,0);
          digitalWrite(mot4b,1);

          break;
          
      case 'B':
          //just reverse condition of 'F' 
          digitalWrite(mot1a,0);
          digitalWrite(mot1b,1);

          digitalWrite(mot2a,0);
          digitalWrite(mot2b,1);

          digitalWrite(mot3a,0);
          digitalWrite(mot3b,1);

          digitalWrite(mot4a,1);
          digitalWrite(mot4b,0);
          break;
          
      case 'L':  
          //left 3 wheels will turn backward(clockwise) and right 3 wheels will turn forward(clockwise)
          digitalWrite(mot1a,0);
          digitalWrite(mot1b,1);

          digitalWrite(mot2a,1);
          digitalWrite(mot2b,0);

          digitalWrite(mot3a,0);
          digitalWrite(mot3b,1);

          digitalWrite(mot4a,0);
          digitalWrite(mot4b,1);

          break;
        
      case 'R':
          //right 3 wheels will move anticlockwise annd left 3 will move anticlockwise
          digitalWrite(mot1a,1);
          digitalWrite(mot1b,0);

          digitalWrite(mot2a,0);
          digitalWrite(mot2b,1);

          digitalWrite(mot3a,1);
          digitalWrite(mot3b,0);
          
          digitalWrite(mot4a,1);
          digitalWrite(mot4b,0);
          
          break;
        
      case 'S':  
          digitalWrite(mot1a,LOW);
          digitalWrite(mot1b,LOW);

          digitalWrite(mot2a,LOW);
          digitalWrite(mot2b,LOW);

          digitalWrite(mot3a,LOW);
          digitalWrite(mot3b,LOW);

          digitalWrite(mot4a,LOW);
          digitalWrite(mot4b,LOW);
              
          break; 
                 
      default:
        { 
        
        }
     }
   }
 } 
  else{
    timer0 = millis();  //Get the current time (millis since execution started).
    //Check if it has been 0.5s since we received last command.
    if((timer0 - timer1)>500){  
      //More tan 500ms have passed since last command received, car is out of range.
      //Therefore stop the carbwhich is must needed function for our soccerBot to take control over bot
          digitalWrite(mot1a,LOW);
          digitalWrite(mot1b,LOW);
         
          digitalWrite(mot2a,LOW);
          digitalWrite(mot2b,LOW);

          digitalWrite(mot3a,LOW);
          digitalWrite(mot3b,LOW);
         
          digitalWrite(mot4a,LOW);
          digitalWrite(mot4b,LOW);

    }
  }  
}
