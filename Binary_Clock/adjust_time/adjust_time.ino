#include<Wire.h>

int i;
int sec=0, sec10=0, min=0 ,min10=0,hour = 0,hour10 =0;


void setup() {
  // put your setup code here, to run once:
Wire.begin();
Serial.begin(9600);


Wire.beginTransmission(B1101000); //start the device communication
Wire.write(0x00);//start from the first memory address
Wire.write(0x00);// write the seconds 00-59
Wire.write(0x21);//write the minutes 00-59
Wire.write(B01010101);// write hours-bit7=0,bit6=12/24, bit 5,4=h10 , bit3,2,1,0 =hour
Wire.endTransmission();
}
