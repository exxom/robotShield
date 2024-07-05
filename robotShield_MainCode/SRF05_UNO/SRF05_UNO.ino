#include <LiquidCrystal.h>
#include "SRF05.h"

#define Inch 0
#define Cm   1 

const int trigger = 8;
const int echo    = 9;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

unsigned long Time;
char str[17];

SRF05 SRF(trigger, echo);

float get_distance(unsigned char unit = Cm){
  if(unit == Inch)
    return SRF.getInch();
  else if(unit == Cm)
    return SRF.getCentimeter();
}

bool Check_distance(float distance, unsigned char unit = Cm){
  if(get_distance(unit) <= distance)
    return true;
  else 
    return false;
}

float avrage_distance(unsigned char unit = Cm){
  if(millis() - Time > 99){
    if(unit == Inch)
      return SRF.getInch();
    else if(unit == Cm)
      return SRF.getCentimeter();
    
    Time = millis();
  }
}

void setup() {
  lcd.begin(2,16);
  lcd.print("   Distance    ");
  delay(1000);
  lcd.clear();
  
  SRF.setCorrectionFactor(1.035);

}

void loop() {
  lcd.setCursor(0, 0);
  sprintf(str,"Distance : %0.f",get_distance(Cm));
  lcd.print(str);

}
