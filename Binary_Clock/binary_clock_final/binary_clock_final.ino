#include<Wire.h>

int i;
int sec=0, sec10=0, min=0 ,min10=0,hour = 0,hour10 =0;

void setup() {
    // put your setup code here, to run once:
    Wire.begin();
    Serial.begin(9600);

//    Wire.beginTransmission(B1101000); //start the device communication
//    Wire.write(0x00);//start from the first memory address
//    Wire.write(0x00);// write the seconds 00-59
//    Wire.write(0x24);//write the minutes 00-59
//    Wire.write(B00010101);// write hours-bit7=0,bit6=12/24, bit 5,4=h10 , bit3,2,1,0 =hour
//    Wire.endTransmission();

}

void loop() {
    getTime();
    displayTime(hour10,hour,min10,min,sec10,sec);

}

void getTime(){

    Wire.beginTransmission(B1101000); //start the device communication
    Wire.write(0x00);//start from first address
    Wire.endTransmission();
    Wire.requestFrom(B1101000,3);//request 3 bytes from this device

    sec = Wire.read();// reads first byte i,e seconds
    min = Wire.read();// reads second byte i,e minutes
    hour = Wire.read();// reads third byte i,e hours

    sec10 = sec>>4; //shist higher four bits to obtain the sec10 values
    for(i=0;i<4;i++)
        bitClear(sec,i+4);//clear higher four bits from sec so as to get only sec values

    min10= min>>4;
    for (i=0;i<4;i++)
        bitClear(min,i+4);//clear higher four bits from minute so as to get only minute values
    bitClear(hour, 5);
    bitClear(hour, 6);

    hour10 = hour >> 4;
    bitClear(hour, 4);



    Serial.print(sec10, DEC);
    Serial.print(sec, DEC);
    Serial.print(min10, DEC);
    Serial.print(min, DEC);
    Serial.print(hour10, DEC);
    Serial.println(hour, DEC);
}

void displayTime(int h10, int h, int m10, int m, int s10, int s){


    if(h10==1){// LED-1
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        reset();
    }
    if(h10==2){// LED-2
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(3, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        reset();
    }
    if(h==1){// LED-3
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        reset(); 
    }
    if(h==2){// LED-4
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        reset();  
    }
    if(h==3){// LED-3 and LED-4
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        reset();    
    }  
    if(h==4){// LED-5
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        reset();
    }
    if(h==5){// LED-5 and LED-3
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        reset();
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        reset();
    }
    if(h==6){// LED-5 and LED-4
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        reset();
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        reset();
    }
    if(h==7){// LED-5 and LED-4 and LED-3
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(5, HIGH);
        reset();
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        reset();  
    }
    if(h==8){// LED-6
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    } 
    if(h==9){// LED-6 and LED-3
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(5, LOW);
        reset(); 
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
        reset();
    }
    if(m10==1){// LED-7
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(2, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(6, HIGH);
        reset(); 
    }
    if(m10==2){// LED-8
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(2, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }
    if(m10==3){// LED-7 and LED-8
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(2, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(2, HIGH);
        digitalWrite(6, LOW);
        reset(); 
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(2, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(6, HIGH);
        reset();
    }
    if(m10==4){// LED-9
        pinMode(2, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        reset(); 
    }
    if(m10==5){// LED-9 and LED 7
        pinMode(2, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        reset();
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(2, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(2, LOW);
        digitalWrite(6, HIGH);
        reset();  
    }
    if(m==1){// LED-12
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(m==2){// LED-11
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        reset(); 
    }
    if(m==3){// LED-11 and LED-12
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        reset(); 
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(m==4){// LED-10
        pinMode(2, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        reset(); 
    }
    if(m==5){// LED-10 and LED-12
        pinMode(2, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(m==6){// LED-10 and LED-11
        pinMode(2, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        reset(); 
    }
    if(m==7){// LED-10 and LED-11 and LED-12
        pinMode(2, INPUT);
        pinMode(5, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(4, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(m==8){// LED-13
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(3, LOW);
        reset(); 
    }
    if(m==9){// LED-13 and LED-12
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(3, LOW);
        reset(); 
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(6, INPUT);
        pinMode(4, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(s10==1){// LED-14
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(s10==2){// LED-15
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(3, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        reset(); 
    }
    if(s10==3){// LED-14 and LED-15
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(3, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        reset();  
    }
    if(s10==4){// LED-16
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(3, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }  
    if(s10==5){// LED-16 and LED-14
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(5, INPUT);
        pinMode(3, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(4, INPUT);
        pinMode(6, INPUT);
        pinMode(3, OUTPUT);
        pinMode(5, OUTPUT);
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        reset();
    }   
    if(s==1){// LED-18
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }  
    if(s==2){// LED-17
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(s==3){// LED-17 and LED-18
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }
    if(s==4){// LED-20
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(4, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }
    if(s==5){// LED-20 and LED-18
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(4, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(6, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }
    if(s==6){// LED-20 and LED-17
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(4, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(6, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        reset(); 
    }
    if(s==7){// LED-20 and LED-17 and LED18
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(4, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(4, HIGH);
        digitalWrite(6, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(5, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }
    if(s==8){// LED-19
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(4, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(4, LOW);
        reset(); 
    }
    if(s==9){// LED-19 adn LED-18
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(5, INPUT);
        pinMode(4, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(6, HIGH);
        digitalWrite(4, LOW);
        reset();
        pinMode(2, INPUT);
        pinMode(3, INPUT);
        pinMode(4, INPUT);
        pinMode(5, OUTPUT);
        pinMode(6, OUTPUT);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        reset(); 
    }

}//write

// reset the LEDs and promotes a delay
void reset(){
    delay(2); // 2ms
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW); 
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
}//reset
