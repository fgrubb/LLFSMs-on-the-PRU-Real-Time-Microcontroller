/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 *  
 * Part of PRU implementation library for ucFSM
 * 
 * Code to test different features of the PRU, focusing on 20 x 4 char LCD.
 * 
 * File: PRU-ucfsm-LCD.h
 * 
 */


	/**
	* Initialize the LCD. Called only once, not recommended to run again
	* without unplugging the LCD.
	*/
void init_LCD(void);

	/**
	*/
void strobe_LCD(void);
void clr_LCD(void);

void strycpy_printStr_LCD(const char *src);
void printStr_LCD( char *Print_Str);
void int_to_string(char *aBuffer, int length, unsigned long data);
void setLine_LCD(int LineNo);
void printRegBin_LCD(uint32_t Reg);

//More intelligent functions which use above simple ones.
/*void printLine_LCD(int lineNo, char *Print_Str);
void SetMode_LCD();
*/
