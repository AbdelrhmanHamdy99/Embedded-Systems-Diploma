/*
 * KeyPad.c
 *
 * Created: 1/30/2025 9:39:13 PM
 *  Author: AbdoHamdy
 */ 
#define F_CPU 1000000U

#include "KeyPad.h"
#include "GPIO.h"
#include "Utils.h"
#include <util/delay.h>

char KeyPad_Character_Matrix[4][4] = {
	'7','8','9','/',
	'4','5','6','x',
	'1','2','3','-',
	' ','0','=','+'
};
/*
char KeyPad_Character_Matrix[4][3] = {
	
	'1','2','3',
	'4','5','6',
	'7','8','9',
	'*','0','#'
};*/

void keyPad_Init(){
	/*define keypad pins directions*/
	/*Rows as output*/
	SET_BIT(KeyPad_Rows_Dire,KeyPad_Row0);
	SET_BIT(KeyPad_Rows_Dire,KeyPad_Row1);
	SET_BIT(KeyPad_Rows_Dire,KeyPad_Row2);
	SET_BIT(KeyPad_Rows_Dire,KeyPad_Row3);
	/*all Rows are high at initialization*/
	SET_BIT(KeyPad_Rows_Port,KeyPad_Row0);
	SET_BIT(KeyPad_Rows_Port,KeyPad_Row1);
	SET_BIT(KeyPad_Rows_Port,KeyPad_Row2);
	SET_BIT(KeyPad_Rows_Port,KeyPad_Row3);
	
	/*Columns as input*/
	RESET_BIT(KeyPad_Cols_Dire,KeyPad_Col0);
	RESET_BIT(KeyPad_Cols_Dire,KeyPad_Col1);
	RESET_BIT(KeyPad_Cols_Dire,KeyPad_Col2);
	RESET_BIT(KeyPad_Cols_Dire,KeyPad_Col3);
	/*activate pull-up resistor for Columns*/
	SET_BIT(KeyPad_Cols_PUR,KeyPad_Col0);
	SET_BIT(KeyPad_Cols_PUR,KeyPad_Col1);
	SET_BIT(KeyPad_Cols_PUR,KeyPad_Col2);
	SET_BIT(KeyPad_Cols_PUR,KeyPad_Col3);
}
char KeyPad_GetKeyPressed(void){
	unsigned char i,j;
	char KeyPad_cols[] = {KeyPad_Col0, KeyPad_Col1, KeyPad_Col2, KeyPad_Col3};
	char KeyPad_rows[] = {KeyPad_Row0, KeyPad_Row1, KeyPad_Row2, KeyPad_Row3};
	for(i = 0; i < n_Rows; i++){
		/*light up only one row at a time*/
		RESET_BIT(KeyPad_Rows_Port, KeyPad_rows[i]);
		
		for (j = 0; j < n_Cols; j++)
		{
			if(!READ_BIT(KeyPad_Cols_PinVal,KeyPad_cols[j])){
				/*avoid debouncing and long press*/
				_delay_ms(20);
				if(!READ_BIT(KeyPad_Cols_PinVal,KeyPad_cols[j])){
					while(!READ_BIT(KeyPad_Cols_PinVal,KeyPad_cols[j]));
					SET_BIT(KeyPad_Rows_Port, KeyPad_rows[i]);
					return KeyPad_Character_Matrix[i][j];
				}
			}
		}
		SET_BIT(KeyPad_Rows_Port, KeyPad_rows[i]);
	}
	return 0; /*null character*/
}