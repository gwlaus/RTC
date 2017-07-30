#include <Wire.h>
#include <DS3231.h>

float temp;
int data;
DS3231 RTC;

void setup()
{
    Serial.begin(9600);

    RTC.begin();

    Serial.println();
    Serial.println();

    Serial.print("Lost Power : ");
    if (RTC.lostPower())
    {
        Serial.println("Yes");
            RTC.setDay(31);
            RTC.setMonth(12);
            RTC.setYear(2014);
            RTC.setHour(23);
            RTC.setMinute(59);
            RTC.setSecond(46);
            RTC.StartClock();
    }
    else
        Serial.println("No");


    temp = RTC.getTemp();
    Serial.print("RTC Temperature : ");
    Serial.println(temp);
}

void loop()
{
    Serial.print(RTC.getDay());
    Serial.print("-");
    Serial.print(RTC.getMonth());
    Serial.print("-");
    Serial.print(RTC.getYear());

    Serial.print(" ");

    Serial.print(RTC.getHour());
    Serial.print(":");
    Serial.print(RTC.getMinute());
    Serial.print(":");
    Serial.print(RTC.getSecond());

    Serial.println();    
    Serial.println();
    
    delay(1000);
}