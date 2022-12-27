/*
 * main.c
 *
 *  Created on: Nov 18, 2022
 *      Author: Abanoub
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "ADC_Interface.h"
#include <util/delay.h>

void main (void)
{
	u8 SW_State=0;

	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
	DIO_vidSetPinVal(DIO_PORTA,DIO_PIN7,DIO_LOW);

	//Switch internal pull up
	DIO_vidSetPinDir(DIO_PORTB,DIO_PIN6,DIO_INPUT);
	DIO_vidSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);

	//Relay pin
	DIO_vidSetPinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);



	/*LCD PORT Data and Control Directions */
	DIO_vidSetPortDir(LCD_DATA_PORT,0xFF); //PORT Data Direction
	DIO_vidSetPinDir(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_OUTPUT); //PORT Control Direction For RS
	DIO_vidSetPinDir(LCD_CONTROL_PORT,LCD_E_PIN,DIO_OUTPUT); //PORT Control Direction For E

	/*ADC Channel 0 as input*/
	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_INPUT);

	/*LCD Init*/
	HLCD_voidInit();

	/*ADC Init*/
	ADC_vidInit();



	u16 Volt=0;
	u16 Digital;

	 while(1)
	 {
		 SW_State=DIO_u8GetPinVal(DIO_PORTB,DIO_PIN6);

		 if (SW_State==1)
		 {
				DIO_vidSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);
			Digital= ADC_u16GetADCRead(0);
			Volt = ((u32)Digital*5000)/1024;
			HLCD_voidSendCommand(LCD_CLEAR);
			HLCD_voidSendString(" 5 Volt Mode:");
			HLCD_voidGotoxy(0,1);
			LCD_Send_Num(Volt);
			_delay_ms(1000);
		 }
		 else
		 {
			DIO_vidSetPinVal(DIO_PORTB,DIO_PIN7,DIO_HIGH);

			Digital= ADC_u16GetADCRead(0);
			Volt = ((u32)Digital*5000)/512;
			HLCD_voidSendCommand(LCD_CLEAR);
			HLCD_voidSendString(" 10 Volt Mode:");
			HLCD_voidGotoxy(0,1);
			LCD_Send_Num(Volt);

			_delay_ms(1000);
		 }


	 }
}

