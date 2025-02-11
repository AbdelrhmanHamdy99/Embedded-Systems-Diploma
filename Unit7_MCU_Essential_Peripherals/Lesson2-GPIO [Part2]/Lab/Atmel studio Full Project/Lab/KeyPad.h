/*
 * KeyPad.h
 *
 * Created: 1/30/2025 9:39:32 PM
 *  Author: AbdoHamdy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KeyPad_Rows_Port   PORTC
#define KeyPad_Rows_Dire   DDRC
#define KeyPad_Cols_PUR    PORTC
#define KeyPad_Cols_PinVal PINC
#define KeyPad_Cols_Dire   DDRC

#define n_Rows           4
#define n_Cols           4
#define KeyPad_Row0      PC0
#define KeyPad_Row1      PC1
#define KeyPad_Row2      PC2
#define KeyPad_Row3      PC3

#define KeyPad_Col0      PC4
#define KeyPad_Col1      PC5
#define KeyPad_Col2      PC6
#define KeyPad_Col3      PC7

void keyPad_Init();
char KeyPad_GetKeyPressed(void);


#endif /* KEYPAD_H_ */