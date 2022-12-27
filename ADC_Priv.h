/*
 * ADC_Priv.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Abanoub
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


#define ADC_INT        1
#define ADC_POLL       0
/*ADC reference voltage*/
#define ADC_VCC 		  	1
#define ADC_INTERNAL_VREF   0
#define ADC_EXT_VREF		3

/*ADC result adjust macros*/
#define ADC_RIGHT 			0
#define ADC_LEFT 			1

/*Registers definitions*/
#define ADCSRA_REG 		*((volatile u8*)(0x26))
#define ADCRES_REG		*((volatile u16*)(0x24))
#define	ADMUX_REG		*((volatile u8*)(0x27))

/*Register ADMUX bits*/
#define REFS1		7
#define REFS0		6
#define	ADLAR		5
#define	MUX4		4
#define MUX3		3
#define MUX2		2
#define	MUX1		1
#define	MUX0		0

/*Register ADCSRA bits*/
#define ADEN		7
#define	ADSC		6
#define ADATE		5
#define	ADIF		4
#define ADIE		3
#define	ADPS2		2
#define ADPS1		1
#define ADPS0		0
#endif /* ADC_PRIV_H_ */
