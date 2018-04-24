/*
 * volumeControl.c
 *
 * Created: 04-Apr-18 4:12:10 PM
 *  Author: Alsayed
 */ 

/*----------------------------------------------------------------
--------------------- File Inclusions ----------------------------
----------------------------------------------------------------*/
#include "volumeControl.h"
#include "adc.h"
#include "timer2.h"

/*----------------------------------------------------------------
--------------------- Private Constants --------------------------
----------------------------------------------------------------*/
#define		SLIDER		ADC_CHANNEL_0


/*----------------------------------------------------------------
--------------------- Public Function Definitions ----------------
----------------------------------------------------------------*/
void volume_control_update(void)
{
	static uint16_t prev_val=-1;
	uint16_t adc_reading = adc_read_channel(SLIDER);
	if(adc_reading!=prev_val)
	{
		prev_val=adc_reading;
	uint8_t duty_cycle_percentage = ( ((uint32_t)adc_reading * 100) / 1023 );
	
	timer2_pwm_duty_cycle_set(duty_cycle_percentage);
	}
}

/*----------------------------------------------------------------
--------------------- End of File --------------------------------
----------------------------------------------------------------*/
