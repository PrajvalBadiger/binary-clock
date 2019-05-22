# binary-clock
its displays time in binary format using leds and arduino

components used:
1. arduino
2. 5mm leds - 20
3. RTC module(i2c)

connection and working:
1. The 20 leds are connected in an charlieplexed manner.
2. Then the 5 pins of the led circuit are connected to the digital pins of the arduino
   as specified in the code.
3. The RTC module is interface and time information is collected from it.
4. With the appropriate combination of leds the differnt conditons are obtained to display time.
5. The combinations are then mapped to the time information of RTC modul.


thank you.
