#include<Wire.h>
#include <ArduinoOTA.h>

#define SECRET_SSID "Omg_aka"
#define SECRET_PASS "hub@2025!OMG"

//#define PIN_1 (2)
//#define PIN_2 (3)
//#define PIN_3 (4)
//#define PIN_4 (5)
//#define PIN_5 (6)

#define PIN_1 (5)
#define PIN_2 (18)
#define PIN_3 (19)
#define PIN_4 (32)
#define PIN_5 (33)

int i;
int sec=0, sec10=0, mins=0 ,mins10=0,hour = 0,hour10 =0;

void setup() {
    // put your setup code here, to run once:
    Wire.begin();
    Serial.begin(9600);
    setupWiFi();
    setupOTA();
//    Wire.beginTransmission(B1101000); //start the device communication
//    Wire.write(0x00);//start from the first memory address
//    Wire.write(0x00);// write the seconds 00-59
//    Wire.write(0x24);//write the minsutes 00-59
//    Wire.write(B00010101);// write hours-bit7=0,bit6=12/24, bit 5,4=h10 , bit3,2,1,0 =hour
//    Wire.endTransmission();

}

void loop() {
    ArduinoOTA.handle();
    getTime();
    displayTime(hour10,hour,mins10,mins,sec10,sec);

}

void setupWiFi() {
  WiFi.begin(SECRET_SSID, SECRET_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setupOTA() {
  ArduinoOTA.setHostname("hardcore");
  ArduinoOTA.begin();
}

void getTime(){

    Wire.beginTransmission(B1101000); //start the device communication
    Wire.write(0x00);//start from first address
    Wire.endTransmission();
    Wire.requestFrom(B1101000,3);//request 3 bytes from this device

    sec = Wire.read();// reads first byte i,e seconds
    mins = Wire.read();// reads second byte i,e minsutes
    hour = Wire.read();// reads third byte i,e hours

    sec10 = sec>>4; //shist higher four bits to obtain the sec10 values
    for(i=0;i<4;i++)
        bitClear(sec,i+4);//clear higher four bits from sec so as to get only sec values

    mins10= mins>>4;
    for (i=0;i<4;i++)
        bitClear(mins,i+4);//clear higher four bits from minsute so as to get only minsute values
    bitClear(hour, 5);
    bitClear(hour, 6);

    hour10 = hour >> 4;
    bitClear(hour, 4);



    //Serial.print(sec10, DEC);
    //Serial.print(sec, DEC);
    //Serial.print(mins10, DEC);
    //Serial.print(mins, DEC);
    //Serial.print(hour10, DEC);
    //Serial.println(hour, DEC);
}

void displayTime(int h10, int h, int m10, int m, int s10, int s){


    if(h10==1){// LED-1
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_2, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_2, HIGH);
        reset();
    }
    if(h10==2){// LED-2
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_2, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_2, LOW);
        reset();
    }
    if(h==1){// LED-3
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_3, HIGH);
        reset(); 
    }
    if(h==2){// LED-4
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();  
    }
    if(h==3){// LED-3 and LED-4
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_3, HIGH);
        reset();    
    }  
    if(h==4){// LED-5
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_4, HIGH);
        reset();
    }
    if(h==5){// LED-5 and LED-3
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_4, HIGH);
        reset();
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_3, HIGH);
        reset();
    }
    if(h==6){// LED-5 and LED-4
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_4, HIGH);
        reset();
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
    }
    if(h==7){// LED-5 and LED-4 and LED-3
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_4, HIGH);
        reset();
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_3, HIGH);
        reset();  
    }
    if(h==8){// LED-6
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    } 
    if(h==9){// LED-6 and LED-3
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_3, HIGH);
        reset();
    }
    if(m10==1){// LED-7
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_5, HIGH);
        reset(); 
    }
    if(m10==2){// LED-8
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }
    if(m10==3){// LED-7 and LED-8
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_1, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_5, HIGH);
        reset();
    }
    if(m10==4){// LED-9
        pinMode(PIN_1, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_2, LOW);
        reset(); 
    }
    if(m10==5){// LED-9 and LED 7
        pinMode(PIN_1, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_2, LOW);
        reset();
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_1, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_1, LOW);
        digitalWrite(PIN_5, HIGH);
        reset();  
    }
    if(m==1){// LED-12
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(m==2){// LED-11
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_3, LOW);
        reset(); 
    }
    if(m==3){// LED-11 and LED-12
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_3, LOW);
        reset(); 
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(m==4){// LED-10
        pinMode(PIN_1, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_3, LOW);
        reset(); 
    }
    if(m==5){// LED-10 and LED-12
        pinMode(PIN_1, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(m==6){// LED-10 and LED-11
        pinMode(PIN_1, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_3, LOW);
        reset(); 
    }
    if(m==7){// LED-10 and LED-11 and LED-12
        pinMode(PIN_1, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_3, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(m==8){// LED-13
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_2, LOW);
        reset(); 
    }
    if(m==9){// LED-13 and LED-12
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_2, LOW);
        reset(); 
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(s10==1){// LED-14
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(s10==2){// LED-15
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_2, LOW);
        reset(); 
    }
    if(s10==3){// LED-14 and LED-15
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_2, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_4, LOW);
        reset();  
    }
    if(s10==4){// LED-16
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }  
    if(s10==5){// LED-16 and LED-14
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_5, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_5, INPUT);
        pinMode(PIN_2, OUTPUT);
        pinMode(PIN_4, OUTPUT);
        digitalWrite(PIN_2, HIGH);
        digitalWrite(PIN_4, LOW);
        reset();
    }   
    if(s==1){// LED-18
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }  
    if(s==2){// LED-17
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(s==3){// LED-17 and LED-18
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_4, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }
    if(s==4){// LED-20
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }
    if(s==5){// LED-20 and LED-18
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_5, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }
    if(s==6){// LED-20 and LED-17
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_5, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_4, LOW);
        reset(); 
    }
    if(s==7){// LED-20 and LED-17 and LED18
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_3, HIGH);
        digitalWrite(PIN_5, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_4, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }
    if(s==8){// LED-19
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_3, LOW);
        reset(); 
    }
    if(s==9){// LED-19 adn LED-18
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_4, INPUT);
        pinMode(PIN_3, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_5, HIGH);
        digitalWrite(PIN_3, LOW);
        reset();
        pinMode(PIN_1, INPUT);
        pinMode(PIN_2, INPUT);
        pinMode(PIN_3, INPUT);
        pinMode(PIN_4, OUTPUT);
        pinMode(PIN_5, OUTPUT);
        digitalWrite(PIN_4, HIGH);
        digitalWrite(PIN_5, LOW);
        reset(); 
    }

}//write

// reset the LEDs and promotes a delay
void reset(){
    delay(2); // 2ms
    digitalWrite(PIN_1, LOW);
    digitalWrite(PIN_2, LOW);
    digitalWrite(PIN_3, LOW);
    digitalWrite(PIN_4, LOW);
    digitalWrite(PIN_5, LOW); 
    pinMode(PIN_1, INPUT);
    pinMode(PIN_2, INPUT);
    pinMode(PIN_3, INPUT);
    pinMode(PIN_4, INPUT);
    pinMode(PIN_5, INPUT);
}//reset
