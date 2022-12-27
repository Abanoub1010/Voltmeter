/*
 * ADC_Prog.c
 *
 *  Created on: Dec 9, 2022
 *      Author: Abanoub
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <avr/interrupt.h>

#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Priv.h"


static 	void (*ADC_ISR_PTR) (void);


void ADC_vidInit (void)
{
	ADMUX_REG = (ADC_VREF << REFS0) | (ADC_RES_ADJUST <<ADLAR);

	ADCSRA_REG = (1<<ADEN) | (1 <<ADPS2) | (1 << ADPS1) | (1 << ADPS0);

#if (ADC_MOD == ADC_INT)
	ADCSRA_REG|=(1<<ADC_INT);
#endif
}


void ADC_EnableINT(void)
{
	ADCSRA_REG|=(1<<ADC_INT);
}

void ADC_DisableINT(void)
{
	ADCSRA_REG&=~(1<<ADC_INT);
}

u16 ADC_u16GetADCRead (u8 ChId)
{
	ChId = ChId & 0b00000111;
	ADMUX_REG = (ADMUX_REG & 0xf8) | ChId ;
	ADCSRA_REG |= (1<<ADSC);
	while (!(ADCSRA_REG & (1<<ADIF)));
	return ADCRES_REG;
}


#if (ADC_MOD == ADC_INT)
void ADC_StartConversion(u8 ChId)
{
	ChId = ChId & 0b00000111;
	ADMUX_REG = (ADMUX_REG & 0xf8) | ChId ;
	ADCSRA_REG |= (1<<ADSC);
}

u16 ADC_u16GetConvertedDig(void)
{
	return ADCRES_REG;
}

void ADC_SetISR(void (*p)(void))
{
	ADC_ISR_PTR= p;
}


ISR(ADC_vect)
{
	ADC_ISR_PTR();
}
#endif
