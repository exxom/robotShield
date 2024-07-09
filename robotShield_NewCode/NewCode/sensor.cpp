#include <stdint.h>
/*
 * sensor.c
 *
 *  Created on: Jul 07, 2024
 *      Author: electronics
 */

#include "sensor.h"

uint8_t   LDR::_numSensor=0;
uint16_t  LDR::_totalSensor=0;

LDR::LDR(const uint8_t pin):_pin(pin){
  _numSensor++;
}

uint16_t LDR::Brightness(void){
  uint16_t light;
  light = analogRead(_pin);
  _totalSensor += light;
  return light;
}

bool LDR::DayNight(uint8_t when ,uint16_t border){
  switch(when){
    case Day:
      if(Brightness()>border){
        return true;
      }else{
        return false;
      }
    break;
    case Night:
      if(Brightness()<border){
        return true;
      }else{
        return false;
      }
    break;
    default :
      return false;
  }
}

uint16_t LDR::NoisyLight(void){
  static unsigned long Time;
  static uint16_t lastVlue;
  uint16_t newVlue;
  if(millis() - Time > 499){
    Time=millis();
    newVlue =Brightness();
    if(newVlue-lastVlue>0){
      if(newVlue - lastVlue>10){
        lastVlue = newVlue;
        return newVlue;
      }else{
        return lastVlue;
      }
    }else{
      if(lastVlue - newVlue>10){
        lastVlue = newVlue;
        return newVlue;
      }else{
        return lastVlue;
      }
    }
  }
}

uint16_t LDR::Avrage(void){
  uint16_t avr;
  if(_numSensor==0){
    return 0;
  }else{
    avr= _totalSensor/_numSensor;
    _totalSensor=0;
    return avr;
    
  }
}

