#include "sensor.h"
#include <LiquidCrystal.h>

const uint8_t Trriger = 8;
const uint8_t Echo = 9;

SENSOR snr(Trriger,Echo);

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

unsigned long avrageTime;
char str[17];

void setup() {
  lcd.begin(16,2);
  lcd.print("   Distance    ");
  delay(1000);
  lcd.clear();

}

void loop() {
  lcd.setCursor(0, 0);
  sprintf(str,"Distance: %d",snr.get_cm(Trriger,Echo));
  lcd.print(str);

}