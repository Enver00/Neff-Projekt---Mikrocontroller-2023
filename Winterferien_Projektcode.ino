#include<analogWrite.h>

int led = 0;
int buttonStatus = 0;
int buttonStatus1 = 0; 
int helligkeit = 0; 
const int ledPinR = 33;
const int ledPinG = 15;
const int ledPinB = 27;
const int  buttonT1= 32;
const int  buttonT2= 2;
const int  buttonT3= 5;
const int  buttonT4= 14;
int zahl = 1;
int x = 0;

void setup() {

  pinMode(33,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(32,INPUT);
  pinMode(2,INPUT);
  pinMode(5,INPUT);
  pinMode(14,INPUT);
  pinMode(led, OUTPUT);
}

void loop() {


  //Status von dem Button
  buttonStatus = digitalRead(buttonT4);

  //Wenn man button T4 drückt wird die helligkeit um 5 erhöht
  if (buttonStatus == HIGH) {
    
    helligkeit = helligkeit + 5;
  }

    //Status von dem Button
    buttonStatus1 = digitalRead(buttonT3);

    //Wenn man button T4 drückt wird die helligkeit um 5 reduziert
    if (buttonStatus1 == HIGH) {
    
    helligkeit = helligkeit - 5;
    //Limit für die Led
    if (helligkeit > 255) {
      helligkeit = 255;
    }

    if (helligkeit < 0) {
      helligkeit = 0;
    }

  }
  //Helligkeit der led bestimmen
  analogWrite(led, helligkeit);
  delay(50);

  if(digitalRead(buttonT2) == HIGH)
  {
    zahl=zahl+1;

    delay(1000);

    x=0;
  }

  if(digitalRead(buttonT1) == HIGH)
  {
    zahl=zahl-1;

    delay(1000);

    x=0;
  }

  if(zahl >= 4)
  {

    zahl=4;

  }

    if(zahl <= 0)
  {

    zahl=0;

  }

  switch(zahl)
  {
    case 1:

      //Vorherige Led 0 setzen

      analogWrite(ledPinB, 0);
      analogWrite(ledPinG, 0);
      delay(20);

      //Led wird Rot

      digitalWrite(ledPinR, HIGH);
      led = 33;
      delay(20);

    break;

    case 2:

      //Vorherige Led 0 setzen

      analogWrite(ledPinR, 0);
      analogWrite(ledPinB, 0);
      delay(20);

      //Led wird Grün    

      digitalWrite(ledPinG, HIGH);
      led = 15;
      delay(20);

    break;

    case 3:

      //Vorherige Led 0 setzen

      analogWrite(ledPinG, 0);  
      analogWrite(ledPinR, 0);    
      delay(20);

      //Led wird Blue

      digitalWrite(ledPinB, HIGH);
      led = 27;
      delay(20);

    break; 
  }
}