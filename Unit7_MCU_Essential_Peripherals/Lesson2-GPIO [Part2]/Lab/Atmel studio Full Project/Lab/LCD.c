/*
 * LCD.c
 *
 * Created: 1/20/2025 9:57:50 PM
 *  Author: AbdoHamdy
 */ 

#define LCD_4_Bit
#define F_CPU 1000000U
#include "LCD.h"
#include "Utils.h"
#include <util/delay.h>

static unsigned char counter = 0;


void LCD_Init(void){
	/*initialize directions for LCD pins*/
	/*Control pins as output*/
	SET_BIT(LCD_Control_Direction,RS);
	SET_BIT(LCD_Control_Direction,RW);
	SET_BIT(LCD_Control_Direction,E);
	
	/*disable LCD*/
	RESET_BIT(LCD_Control_Port,E);
	_delay_ms(20); /*waiting until automatic initialization finishes*/
	
	#if defined(LCD_8_Bit)
	Function_Set = eight_bit_2line_5x8;
	#elif defined(LCD_4_Bit)
	Function_Set = four_bit_2line_5x8;
	
	/*Sets the LCD to 4-bit operation*/
	/* only this instruction completes with one write.*/
	WRITE_NIBBLE(LCD_Data_Port,((Function_Set>>4) & 0xF),nibble_start_position);
	_delay_us(0.05); /*TAS = 50ns (min= 40ns)*/
	SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
	_delay_us(0.3); /*TCYCE / 2 = 300ns (min = 250ns)*/
	RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
	_delay_us(0.3); /*TCYCE/2 = 300ns (min = 250ns)*/
	
	#else
	#define LCD_8_Bit
	Function_Set = eight_bit_2line_5x8;
	# warning "LCD System not defined"
	#endif
	
	Display_Control = Display_on | Cursor_on | Blinking;
	entryMode = Increment_No_Shift;/*increment the address by one and shift the cursor to the right 
	                                at the time of write to the DD/CGRAM.*/
	
	LCD_Write_Command(Function_Set);
	LCD_Write_Command(entryMode); 
	LCD_Write_Command(Display_Control); 
	LCD_Write_Command(LCD_Clear);
	LCD_Write_Command(LCD_Return_Home);
}

void LCD_Write_Data(char* input){
	while(*input){
		LCD_SendCharacter(*(input++));
	}
}
void LCD_Write_Command(char command){
	while(LCD_Busy()); /*wait until LCD finishes internal operation*/
	/*Change direction of data bins to be output*/
	#ifdef LCD_8_Bit
		SET_BIT(LCD_Data_Direction, DB0);
		SET_BIT(LCD_Data_Direction, DB1);
		SET_BIT(LCD_Data_Direction, DB2);
		SET_BIT(LCD_Data_Direction, DB3);
	#endif
	SET_BIT(LCD_Data_Direction, DB4);
	SET_BIT(LCD_Data_Direction, DB5);
	SET_BIT(LCD_Data_Direction, DB6);
	SET_BIT(LCD_Data_Direction, DB7);
	
	RESET_BIT(LCD_Control_Port,RS); /*Instruction*/
	RESET_BIT(LCD_Control_Port,RW); /*Write*/
	/*Write Data*/
	#if defined(LCD_8_Bit)		
		LCD_Data_Port = command;
	#endif
	#ifdef LCD_4_Bit
	    /*send higher order nibble first*/
		WRITE_NIBBLE(LCD_Data_Port,((command>>4) & 0xF),nibble_start_position);
		_delay_us(0.05); /*TAS = 50ns (min = 40ns)*/
		SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
		_delay_us(0.3); /*TCYCE / 2 = 300ns (min = 250ns)*/
		RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
		_delay_us(0.02); /*TH = 20ns (min = 10ns)*/
		/*send lower nibble*/
		WRITE_NIBBLE(LCD_Data_Port,(command & 0xF),nibble_start_position);
		_delay_us(0.3); /*TCYCE/2 = 300ns (min = 250ns)*/
	#endif
	_delay_us(0.05); /*TAS = 50ns (min = 40ns)*/
	SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
	_delay_us(0.3); /*TCYCE / 2 = 300ns (min) = 250ns*/
	RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
	_delay_us(0.3); /*TCYCE/2 = 300ns (min = 250ns)*/
	_delay_ms(2); /*wait 2ms before performing any other command*/
	
	/*update the counter if the command was change cursor position*/
	if(command >= F00){
		if(command < S00){
			counter = command - 0xF00;
		}else{
			counter = 17 + (command - S00);
		}
	}else if(command == LCD_Return_Home){
		counter = 0;
	}
}
void LCD_SendCharacter(char c){
	while(LCD_Busy()); /*wait until LCD finishes internal operation*/
	
	if(counter++ == LCD_Line_Length){ /*end of 1st line*/
		DDRAM_Address = S00;
		LCD_Write_Command(DDRAM_Address);
	}else if(counter > LCD_Line_Length * 2){ /*end of 2nd line*/
		/*Clear Screen*/
		LCD_Write_Command(LCD_Clear);
		LCD_Write_Command(LCD_Return_Home);
		counter =0;
	}
	/*Change direction of data bins to be output*/
	#ifdef LCD_8_Bit
		LCD_Data_Direction = 0Xff;
	#else
		WRITE_NIBBLE(LCD_Data_Direction,0Xf,nibble_start_position);
	#endif
	
	SET_BIT(LCD_Control_Port,RS); /*data*/
	RESET_BIT(PORTB,RW); /*Write*/
	
	#ifdef LCD_8_Bit
		LCD_Data_Port = c;
	#else
	    /*send the higher nibble*/
		WRITE_NIBBLE(LCD_Data_Port,((c>>4) & 0xF),nibble_start_position);
		_delay_us(0.05); /*TAS = 50ns (min = 40ns)*/
		SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
		_delay_us(0.3); /*TCYCE / 2 = 300ns (min = 250ns)*/
		RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
		_delay_us(0.3); /*TCYCE/2 = 300ns (min = 250ns)*/
		/*send the lower nibble*/
		WRITE_NIBBLE(LCD_Data_Port,(c & 0xF),nibble_start_position);
	#endif
	_delay_us(0.05); /*TAS = 50ns (min = 40ns)*/
	SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
	_delay_us(0.3); /*TCYCE / 2 = 300ns (min = 250ns)*/
	RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
	_delay_us(0.3); /*TCYCE/2 = 300ns (min = 250ns)*/
}
boolean LCD_Busy(void){
	boolean busy = false;
	/*Change direction of data bins to be input*/
	#if defined(LCD_8_Bit)
		LCD_Data_Direction = 0; /*input*/
		LCD_Data_Port = 0; /*floating (Tri-Z)*/
	#else
		WRITE_NIBBLE(LCD_Data_Direction,0,nibble_start_position); /*input*/
		WRITE_NIBBLE(LCD_Data_Port,0,nibble_start_position); /*floating*/
	#endif
	
	RESET_BIT(LCD_Control_Port,RS); /*Instruction*/
	SET_BIT(LCD_Control_Port,RW); /*read*/
	
	_delay_us(0.05); /*TAS = 50ns (min = 40ns)*/
	SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
	_delay_us(0.2); /*tDDR (wait until data is ready) = 200ns (min = 160ns)*/
	busy = READ_BIT(LCD_Data_PinVal, DB7); /*read busy flag*/
	_delay_us(0.2); /*TCYCE / 2 = 200 + 200 = 400ns (min = 250ns)*/
	RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
	_delay_us(0.4); /*TCYCE/2 = 400ns (min = 250ns)*/
	#if defined(LCD_4_Bit)	
	/*read the lower nibble of the address*/
	SET_BIT(LCD_Control_Port,E); /*Enable the LCD*/
	_delay_us(0.2); /*tDDR (wait until data is ready) = 200ns (min = 160ns)*/
	/*****read lower nibble here*****/
	_delay_us(0.2); /*TCYCE / 2 = 200 + 200 = 400ns (min = 250ns)*/
	RESET_BIT(LCD_Control_Port,E); /*Disable the LCD*/
	_delay_us(0.4); /*TCYCE/2 = 400ns (min = 250ns)*/
	#endif
	
	return busy;
}