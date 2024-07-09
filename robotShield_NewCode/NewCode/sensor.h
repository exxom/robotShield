#pragma once

#include "Arduino.h"

#define Day   1
#define Night 0

class LDR
{
public:
    LDR(const uint8_t pin);
    static uint16_t Avrage(void);
    uint16_t Brightness(void);
    uint16_t NoisyLight(void);
    bool DayNight(uint8_t when ,uint16_t border);

    static uint8_t  _numSensor;
    static uint16_t _totalSensor;

private:
    uint8_t         _pin;
    
};
//  -- END OF FILE --


