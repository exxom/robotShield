#pragma once

#include "Arduino.h"

#define Inch 0
#define Cm   1

class SENSOR
{
public:
  explicit SENSOR(const uint8_t trigger, const uint8_t echo);
  
	int ClculateDstance(int trigger,int echo);
	int get_cm(uint8_t trrigger,uint8_t echo);
	int get_inch(uint8_t trrigger,uint8_t echo);
	int get_distance(uint8_t trrigger,uint8_t echo,unsigned char unit=Cm);
	bool Check_distance(uint8_t trrigger,uint8_t echo,float distance, unsigned char unit=Cm);
	int avrage_distance(uint8_t trrigger,uint8_t echo,unsigned char time,unsigned char unit=Cm);
  
  
};

//  -- END OF FILE --


