/*
 * ADC_Interface.h
 *
 *  Created on: Dec 9, 2022
 *      Author: Abanoub
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_vidInit (void);

u16 ADC_u16GetADCRead (u8 ChId);

void ADC_EnableINT(void);

void ADC_DisableINT(void);

void ADC_StartConversion(u8 ChId);

u16 ADC_u16GetConvertedDig(void);

void ADC_SetISR(void (*p)(void));


#endif /* ADC_INTERFACE_H_ */
