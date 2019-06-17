/* Minimum_Source*/
#include <RC100.h>
#include <OLLO.h>
#define ID_1 1
#define ID_2 2
#define ID_3 3
#define ID_4 4
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04

Dynamixel Dxl(DXL_BUS_SERIAL1);

int a=512;
int b=512;
int c=512;
int d=512;
char ch;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  // put your setup code here, to run once:
  Serial2.begin(9600);
  Dxl.begin(3);
  Dxl.jointMode(ID_1); //jointMode() is to use position mode
  Dxl.jointMode(ID_2); //jointMode() is to use position mode
  Dxl.jointMode(ID_3); //jointMode() is to use position mode 
  Dxl.jointMode(ID_4); //jointMode() is to use position mode  
 
}
void loop()
 {  
  
  if(Serial2.available()){
     ch = Serial2.read();
   }
     switch(ch)
     {
       case('a'):  a+=20*3.143;         break;
       case('b'):  a-=20*3.143;         break;
       case('c'):  a+=20*3.143;          break;
       case('d'):  a-=20*3.143;          break;
       case('e'):  b+=20*3.143;         break;
       case('f'):  b-=20*3.143;         break;
       case('g'):  b+=20*3.143;          break;
       case('h'):  b-=20*3.143;          break;
       case('i'):
                   c+=20*3.143;
                   d+=20*3.143;                     
                   break;
       case('j'):  
                   c-=20*3.143;
                   d-=20*3.143;                     
                   break;
       case('k'):  
                   c+=20*3.143;
                   d+=20*3.143;                     
                   break;
       case('l'):  
                   c-=20*3.143;
                   d-=20*3.143;                     
                   break;   
       case('o'):  digitalWrite(0, HIGH);
                   digitalWrite(1, LOW);      
                   digitalWrite(2, HIGH);   
                                         break; 
       case('0'):  digitalWrite(0, LOW);
                                        break;    
       default:                         break;
     }

  if(a>1024)
  a=1024;
  if(b>1024)
  b=1024;
  if(c>1024)
  c=1024;
  if(d>1024)
  d=1024;
  if(a<0)
  a=0;
  if(b<0)
  b=0;
  if(c<0)
  c=0;
  if(d<0)
  d=0;
  
  Dxl.setPosition(ID_1, a, 50);
  Dxl.setPosition(ID_2, b, 50);
  Dxl.setPosition(ID_3, c, 50);
  Dxl.setPosition(ID_4, d, 50);
//delay(100);
 }
