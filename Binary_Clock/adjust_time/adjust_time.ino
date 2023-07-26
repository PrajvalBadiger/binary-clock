#include<Wire.h>


void setup() {
    // put your setup code here, to run once:
    Wire.begin();
    Serial.begin(9600);


    Wire.beginTransmission(B1101000); //start the device communication
    Wire.write(0x00);//start from the first memory address
    Wire.write(0x00);// write the seconds 00-59
    Wire.write(0x46);//write the minutes 00-59
    Wire.write(B00000001);// write hours-bit7=0,bit6=12/24, bit 5,4=h10 , bit3,2,1,0 =hour
    Wire.endTransmission();
}


void loop {

}
