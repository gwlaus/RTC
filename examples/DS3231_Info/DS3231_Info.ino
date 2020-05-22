#include <Wire.h>
#include <RTC.h>

static DS3231 RTC;
//float temp;

void setup()
{
  Serial.begin(9600);
  RTC.begin();

  Serial.println();
  Serial.println("*** RTC 3231 ***");
  Serial.print("Is Clock Running : ");
  if (RTC.isRunning())
    Serial.println("Yes");
  else
    Serial.println("No. Time may be Inaccurate");
  Serial.print("Hour Mode :");
  if (RTC.getHourMode() == CLOCK_H12)
    Serial.println("12 Hours");
  else
    Serial.println("24 Hours");
    
  Serial.print("RTC Temperature : ");
  //temp = ;
 
  Serial.println(RTC.getTemp());
}

void loop()
{

  switch (RTC.getWeek())
  {
    case 1:
      Serial.print("SUN");
      break;
    case 2:
      Serial.print("MON");
      break;
    case 3:
      Serial.print("TUE");
      break;
    case 4:
      Serial.print("WED");
      break;
    case 5:
      Serial.print("THU");
      break;
    case 6:
      Serial.print("FRI");
      break;
    case 7:
      Serial.print("SAT");
      break;
  }
  Serial.print(" ");
  Serial.print(RTC.getDay());
  Serial.print("-");
  Serial.print(RTC.getMonth());
  Serial.print("-");
  Serial.print(RTC.getYear());

  Serial.print(" ");

  Serial.print(RTC.getHours());
  Serial.print(":");
  Serial.print(RTC.getMinutes());
  Serial.print(":");
  Serial.print(RTC.getSeconds());
  if (RTC.getHourMode() == CLOCK_H12)
  {
    switch (RTC.getMeridiem())
    {
      case HOUR_AM :
        Serial.print(" AM");
        break;
      case HOUR_PM :
        Serial.print(" PM");
        break;
    }
  }
  Serial.println();
  delay(1000);
}
