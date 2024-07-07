/*
 * sensor.c
 *
 *  Created on: Jul 07, 2024
 *      Author: electronics
 */

#include "sensor.h"


SENSOR::SENSOR(const uint8_t trigger, const uint8_t echo)
{
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
}

int SENSOR::ClculateDstance(int trigger,int echo){
  long duration;
  int distance;
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration= pulseIn(echo, HIGH,10);
  distance= duration * 0.034 /2 ;
  return distance;
}

int SENSOR::get_cm(uint8_t trrigger,uint8_t echo){
  int CM;
  CM = ClculateDstance(trrigger,echo);
  return CM;
}

int SENSOR::get_inch(uint8_t trrigger,uint8_t echo){
  int INCH;
  INCH = get_cm(trrigger,echo)/2.54;
  return INCH;
}

int SENSOR::get_distance(uint8_t trrigger,uint8_t echo,unsigned char unit){
  if(unit == Inch)
    return get_inch(trrigger,echo);
  else if(unit == Cm)
    return get_cm(trrigger,echo);
}

bool SENSOR::Check_distance(uint8_t trrigger,uint8_t echo,float distance, unsigned char unit){
  if(get_distance(trrigger,echo,unit) <= distance)
    return true;
  else 
    return false;
}

int SENSOR::avrage_distance(uint8_t trrigger,uint8_t echo,unsigned char time,unsigned char unit){
  if(millis() - time > 99){
    if(unit == Inch)
      return get_inch(trrigger,echo);
    else if(unit == Cm)
      return get_cm(trrigger,echo);
    
    time = millis();
  }
}
