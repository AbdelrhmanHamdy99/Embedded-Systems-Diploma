/*
 * KeyPad.c
 *
 * Created: 1/30/2025 9:39:13 PM
 *  Author: AbdoHamdy
 */

#include "KeyPad.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "Utils.h"

const char KeyPad_Character_Matrix[4][4] = {
		{'7','8','9','/'},
		{'4','5','6','x'},
		{'1','2','3','-'},
		{' ','0','=','+'}
};

static char KeyPad_Rows[] = {KeyPad_RowA, KeyPad_RowB, KeyPad_RowC, KeyPad_RowD};
static char KeyPad_Cols[] = {KeyPad_Col1, KeyPad_Col2, KeyPad_Col3, KeyPad_Col4};
static void _delay_ms( uint16_t time);
/****************************************************************************************************
 * @Fn			- keyPad_Init
 * @brief		- Initialize the KeyPad to be ready to use
 * @returnValue	- None
 * @notes		- None
 */
void keyPad_Init(void){
	uint8_t i;
	/*define keypad pins directions*/
	/*Rows as output*/
	GPIO_PinConfig_t pinConfig;
	pinConfig.pinMode     = GPIO_PIN_MODE_Out_PushPull;
	pinConfig.pinOutSpeed = GPIO_PIN_OUT_SPEED_10MHZ;
	for(i = 0; i < n_Rows; i++){
		pinConfig.pinNumber   = KeyPad_Rows[i];
		MCAL_GPIO_Init(KeyPad_Rows_Port, &pinConfig);
	}
	/*all Rows are high at initialization*/
	for(i = 0; i < n_Rows; i++){
		MCAL_GPIO_WritePin(KeyPad_Rows_Port, KeyPad_Rows[i], GPIO_PIN_Value_Low);
	}

	/*Columns as input*/
	pinConfig.pinMode = GPIO_PIN_MODE_IN_PullDown;
	for(i = 0; i < n_Cols; i++){
		pinConfig.pinNumber   = KeyPad_Cols[i];
		MCAL_GPIO_Init(KeyPad_Cols_Port, &pinConfig);
	}
}
/****************************************************************************************************
 * @Fn			- KeyPad_GetKeyPressed
 * @brief		- read the pressed button value
 * @returnValue	- the value of the pressed key
 * 				  Null if no key is pressed
 */
char KeyPad_GetKeyPressed(void){
	uint8_t i,j;
	for(i = 0; i < n_Rows; i++){
		/*light up only one row at a time*/
		MCAL_GPIO_WritePin(KeyPad_Rows_Port, KeyPad_Rows[i], GPIO_PIN_Value_High);

		for (j = 0; j < n_Cols; j++)
		{
			if(MCAL_GPIO_ReadPin(KeyPad_Cols_Port, KeyPad_Cols[j]) == GPIO_PIN_Value_High){
				_delay_ms(20); /*avoid debouncing*/
				if(MCAL_GPIO_ReadPin(KeyPad_Cols_Port, KeyPad_Cols[j]) == GPIO_PIN_Value_High){
					/*avoid long press*/
					while(MCAL_GPIO_ReadPin(KeyPad_Cols_Port, KeyPad_Cols[j]) == GPIO_PIN_Value_High);
					MCAL_GPIO_WritePin(KeyPad_Rows_Port, KeyPad_Rows[i], GPIO_PIN_Value_Low); /*Turn off the row*/
					return KeyPad_Character_Matrix[i][j]; /*return the pressed key*/
				}
			}
		}
		MCAL_GPIO_WritePin(KeyPad_Rows_Port, KeyPad_Rows[i], GPIO_PIN_Value_Low); /*Turn off that row*/
	}
	return NULL; /*no character is pressed */
}
/****************************************************************************************************
 * @Fn			- _delay_ms
 * @brief		- Force software Delay
 * @param [in]	- time : Simulate numer of milliseconds you want to hang up
 * @returnValue	- None
 * @Notes		- This Function Simulates waiting for (time)ms.
 */
static void _delay_ms(uint16_t time){
	while(time--){
//		uint32_t i ;
//		for(i = 0 ; i < 255; i++);
	}
}

