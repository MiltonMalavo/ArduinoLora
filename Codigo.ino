#include <SoftwareSerial.h>
SoftwareSerial Lora(8,9); //RX,TX
unsigned long Tempo = 0;
unsigned long Tempo1 = 0;

int Estado1 = 0;
int Estado2 = 0;
int Estado3 = 0;
int Estado4 = 0;

#define BT1 7
#define BT2 7
#define BT3 7
#define BT4 7

void setup() {
  Serial.begin(9600);
  Lora.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(BT1,INPUT_PULLUP);
  pinMode(BT2,INPUT_PULLUP);
  pinMode(BT3,INPUT_PULLUP);
  pinMode(BT4,INPUT_PULLUP);
}

void loop() {
    if(digitalRead(BT1) == 0){Estado1 = 1;}
    if(digitalRead(BT1) == 1 && Estado1 == 1){digitalWrite(10,!digitalRead(10)); Estado1 = 0;}

    if(digitalRead(BT2) == 0){Estado2 = 1;}
    if(digitalRead(BT2) == 1 && Estado2 == 1){digitalWrite(11,!digitalRead(11)); Estado2 = 0;}

    if(digitalRead(BT3) == 0){Estado3 = 1;}
    if(digitalRead(BT3) == 1 && Estado3 == 1){digitalWrite(12,!digitalRead(12)); Estado3 = 0;}

    if(digitalRead(BT4) == 0){Estado4 = 1;}
    if(digitalRead(BT4) == 1 && Estado4 == 1){digitalWrite(13,!digitalRead(13)); Estado4 = 0;}
    
    if(Serial.available()>0)
    {
      char Dados = Serial.read();
      //Ligar Leds
      if(Dados =='A'){digitalWrite(10,1);}
      if(Dados =='B'){digitalWrite(11,1);}
      if(Dados =='C'){digitalWrite(12,1);} 
      if(Dados =='D'){digitalWrite(13,1);}

      //Desligar Leds
      if(Dados =='a'){digitalWrite(10,0);}
      if(Dados =='b'){digitalWrite(11,0);}  
      if(Dados =='c'){digitalWrite(12,0);}
      if(Dados =='d'){digitalWrite(13,0);}   
    }
   if(millis()-Tempo1 >=1500)
    {
      Tempo1 = millis();
      if(digitalRead(10) == 1){Serial.print("1*");}
      else{Serial.print("0*");}
      if(digitalRead(11) == 1){Serial.print("1*");}
      else{Serial.print("0*");}
      if(digitalRead(12) == 1){Serial.print("1*");}
      else{Serial.print("0*");}
      if(digitalRead(13) == 1){Serial.print("1*");}
      else{Serial.print("0*");}
      Serial.println();
    }
   


     if(Lora.available()>0)
    {
      char Dados = Lora.read();
      //Ligar Leds
      if(Dados =='A'){digitalWrite(10,1);}
      if(Dados =='B'){digitalWrite(11,1);}
      if(Dados =='C'){digitalWrite(12,1);} 
      if(Dados =='D'){digitalWrite(13,1);}

      //Desligar Leds
      if(Dados =='a'){digitalWrite(10,0);}
      if(Dados =='b'){digitalWrite(11,0);}  
      if(Dados =='c'){digitalWrite(12,0);}
      if(Dados =='d'){digitalWrite(13,0);}   
    }

    if(millis()-Tempo >=1500)
    {
      Tempo = millis();
       if(digitalRead(10) == 1){Lora.print("1*");}
      else{Lora.print("0*");}
      if(digitalRead(11) == 1){Lora.print("1*");}
      else{Lora.print("0*");}
      if(digitalRead(12) == 1){Lora.print("1*");}
      else{Lora.print("0*");}
      if(digitalRead(13) == 1){Lora.print("1*");}
      else{Lora.print("0*");}
      Lora.println();
    }
  

}
