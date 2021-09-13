/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 *  
 * Part of PRU implementation library for ucFSM
 * 
 * Code to test different features of the PRU, focusing on 20 x 4 char LCD.
 * Includes lines to to mask/patch only LCD pins.
 * This leaves the LEDs untouched so they stay on
 * regardles of when LCD functions are called.
 * 
 * File: PRU-ucfsm-LCD.c
 */

/*
Potential future modifications/additions:
====================================
Functions:
Reconfigure LCD with commands etc
Shift, clear data bits, such as 4 bit shift & clearing LCD pins.
Shift text around, format to update parts as variables.
Essentially create options to format a menu interface.

//void sendData_LCD
//void sendCommand_LCD

__R30 |= LCD_D7 | ((LCD_line_1_Addr_Const >> 4 )  << LCD_D4);
__R30 |= (LCD_line_1_Addr_Const << LCD_D4);

__R30 |= LCD_D7 | (LCD_line_2_Addr_Const & 0xF0) << (LCD_bit_shift_Const - 4);
__R30 |= (LCD_line_2_Addr_Const & 0x0F) << (LCD_bit_shift_Const);


*/


//LCD
#define LCD_RS  (1 << 9)    //pr2_pru0_gpo9
#define LCD_E  (1 << 10)    //pr2_pru0_gpo10
#define LCD_D4  (1 << 11)    //pr2_pru0_gpo11
#define LCD_D5  (1 << 12)    //pr2_pru0_gpo12
#define LCD_D6  (1 << 13)    //pr2_pru0_gpo13
#define LCD_D7  (1 << 14)    //pr2_pru0_gpo14

#define LCD_bit_shift_Const   11  //How many bits to shift the value up to the LCD pins 

// all 1s for LCD pins 0x7E00
// all 0s for LCD pins 0x1FF
//#define LCD_0s !(LCD_D7|LCD_D6|LCD_D5|LCD_D4|LCD_E|LCD_RS)
#define LCD_0s 0xFFFF81FF
#define LCD_0s_data 0xFFFF87FF
#define not_LCD_0s_data 0x7800

//#define LCD_0s 0x000001FF

#define LCD_line_char_addr_max   39
#define LCD_line_char_addr_offset   25

//Below are addresses for beginnings of LCD lines for DDRAM.
#define LCD_line_1_Addr_Const  0
#define LCD_line_2_Addr_Const  0x40
#define LCD_line_3_Addr_Const  0x14
#define LCD_line_4_Addr_Const  0x54


#define LCD_init        (!LCD_RS | !LCD_D7 | !LCD_D6 | LCD_D5 | LCD_D4)
#define LCD_funct_4bit  (!LCD_RS | !LCD_D7 | !LCD_D6 | LCD_D5 | !LCD_D4)
#define LCD_funct_LF    (!LCD_RS | LCD_D7 | !LCD_D6 | LCD_D5 | !LCD_D4)
#define LCD_comm_1      (!LCD_RS | !LCD_D7 | !LCD_D6 | !LCD_D5 | !LCD_D4)
#define LCD_comm_off    (!LCD_RS | LCD_D7 | !LCD_D6 | LCD_D5 | LCD_D4)
#define LCD_comm_clr    (!LCD_RS | !LCD_D7 | !LCD_D6 | !LCD_D5 | LCD_D4)
#define LCD_comm_RnoShift   (!LCD_RS | !LCD_D7 | LCD_D6 | LCD_D5 | !LCD_D4)
#define LCD_comm_DonConBon  (!LCD_RS | LCD_D7 | LCD_D6 | LCD_D5 | LCD_D4)

#include <stdint.h>
#include <string.h>
#include "PRU-ucfsm-general-defines.h"
#include "PRU-ucfsm-LCD-lib.h"

void init_LCD(void)
{
    __R30 &= LCD_0s;
//     __R30 &= LCD_init|LCD_0s;           //LCD wake up command
     __R30 |= LCD_init;           //LCD wake up command
     strobe_LCD();
     __delay_cycles(Delay_4_1mS);     //Delay 4.1ms after sending "wake up" command
   
     strobe_LCD();
     __delay_cycles(Delay_38uS);     //Delay 38uS after sending "wake up" command
    
     strobe_LCD();
     __delay_cycles(Delay_38uS);     //Delay 38uS
    
     __R30 &= LCD_0s;
     __R30 |= LCD_funct_4bit;
    strobe_LCD();
    __delay_cycles(Delay_38uS);     //Delay 38uS

    strobe_LCD();
    __delay_cycles(Delay_100uS);     //Delay 100uS
    
    __R30 &= LCD_0s;
    __R30 |= LCD_funct_LF;        //Send 2 lines, 5x8 font size
    strobe_LCD();
    __delay_cycles(Delay_38uS);     //Delay 37uS
    
    __R30 &= LCD_0s;
    __R30 |= LCD_comm_1;
    strobe_LCD();
    __delay_cycles(Delay_1uS);     //Delay 1uS
    __R30 &= LCD_0s;
    __R30 |= LCD_comm_off;
    strobe_LCD();
    __delay_cycles(Delay_38uS);     //Delay 37uS

    __R30 &= LCD_0s;
    __R30 |= LCD_comm_1;
    strobe_LCD();
    __delay_cycles(Delay_1uS);     //Delay 1uS
    __R30 &= LCD_0s;
    __R30 |= LCD_comm_DonConBon;
    strobe_LCD();
    __delay_cycles(Delay_38uS);     //Delay 37uS

    __R30 &= LCD_0s;
    __R30 |= LCD_comm_1;
    strobe_LCD();
    __delay_cycles(Delay_1uS);     //Delay 1uS
    __R30 &= LCD_0s;
    __R30 |= LCD_comm_RnoShift;
    strobe_LCD();
    __delay_cycles(Delay_38uS);     //Delay 37uS
    __delay_cycles(Delay_1uS);     //Delay 1uS, may be needed
        
    __R30 &= LCD_0s;                //Clear the bus
}

void strobe_LCD(){
    __R30 |= LCD_E;      //Strobe the LCD Enable pin
    __delay_cycles(Delay_1uS);     //Delay 1us for strobe
    __R30 ^= LCD_E;     //Turn off LCD Enable
    __delay_cycles(Delay_1uS);     //Delay 1us for data to be latched in.
}

void clr_LCD(void){
    __R30 |= LCD_comm_1;
    strobe_LCD();
    __delay_cycles(Delay_1uS);     //Delay 1uS
    __R30 |= LCD_comm_clr;
    strobe_LCD(); 


    __delay_cycles(Delay_1_6mS);     //Delay 1.6ms
    
	//Only patch over LCD pins to preserve all others, such as LEDs
    __R30 &= LCD_0s;
}

//Check if needed, or better way to make part of normal flow
void strycpy_printStr_LCD(const char *src) {
    static char  theBuffer[10];
    strcpy(theBuffer,src);
    printStr_LCD(&theBuffer);
}

void printStr_LCD(char *Print_Str){
    char c = *Print_Str;
    __R30 &= LCD_0s;        //Only patch over LCD pins to preserve all others, such as LEDs
    while(c){
        __R30 |= (c << (LCD_bit_shift_Const - 4));  //Send the high 4 bits
        __R30 |= (LCD_RS);      //Turn LCD_RS on to tell display ram to print chars from CGRAM
        __delay_cycles(Delay_0_5uS);     //Delay 0.5uS
        strobe_LCD();
        __delay_cycles(Delay_1uS);     //Delay 1uS

        __R30 &= LCD_0s;
        
        __R30 |= (c << (LCD_bit_shift_Const));      //Send the low 4 bits.
        __R30 |= (LCD_RS);      //Turn LCD_RS on to tell display ram to print chars from CGRAM
        __delay_cycles(Delay_0_5uS);     //Delay 0.5uS
        strobe_LCD();
        __delay_cycles(Delay_38uS);     //Delay 38uS

        __R30 &= LCD_0s;
        
        Print_Str++;
        c = *Print_Str;
    }
    
}



//Send int of 1 to 4 for begining address of them
void setLine_LCD(int LineNo){
    
    __R30 &= LCD_0s;        //Clear the LCD pins, preserve other bits etc for LEDs same
    switch (LineNo){
        
        
        case 1:                     //Line 1 address is 0x0
            __R30 |= LCD_D7;        //Bit 7 of LCD must be high with high nibble.
            
            strobe_LCD();
            __delay_cycles(Delay_0_5uS);     //Delay 1uS
            
            __R30 &= LCD_0s;

            strobe_LCD();
            __delay_cycles(Delay_40uS);     //Delay 38uS
            
            //Zero out the LCD pins & preserve everything else
            __R30 &= LCD_0s;
            break;
            
            
        case 2:                     //Line 2 address is 0x40
            __R30 |= (LCD_D7 | (not_LCD_0s_data & (LCD_line_2_Addr_Const << (LCD_bit_shift_Const - 4))));

            strobe_LCD();
            __delay_cycles(Delay_0_5uS);     //Delay 0.5uS

            __R30 &= LCD_0s;
            
            __R30 |= (not_LCD_0s_data & (LCD_line_2_Addr_Const << LCD_bit_shift_Const));

            strobe_LCD();
            __delay_cycles(Delay_40uS);     //Delay 40uS
            __R30 &= LCD_0s;	//Only patch over LCD pins to preserve all others, such as LEDs
            break;
            
            //Line 3 address is 0x14
        case 3:
//            __R30 = 0x00004800;
            __R30 |= (LCD_D7 | (not_LCD_0s_data & (LCD_line_3_Addr_Const << (LCD_bit_shift_Const - 4))));

            strobe_LCD();
            __delay_cycles(Delay_0_5uS);     //Delay 0.5uS
            
            __R30 &= LCD_0s;
            __R30 |= (not_LCD_0s_data & (LCD_line_3_Addr_Const << LCD_bit_shift_Const));

            strobe_LCD();
            __delay_cycles(Delay_40uS);     //Delay 38uS
            
            ////Only patch over LCD pins to preserve all others, such as LEDs
            __R30 &= LCD_0s;
            break;
            
            //Line 4 address is 0x54
        case 4:
            __R30 |= (LCD_D7 | (not_LCD_0s_data & (LCD_line_4_Addr_Const << (LCD_bit_shift_Const - 4))));

            strobe_LCD();
            __delay_cycles(Delay_0_5uS);     //Delay 0.5uS
            
            __R30 &= LCD_0s;
            __R30 |= (not_LCD_0s_data & (LCD_line_4_Addr_Const << LCD_bit_shift_Const));

            strobe_LCD();
            __delay_cycles(Delay_40uS);     //Delay 40uS
            
            //Only patch over LCD pins to preserve all others, such as LEDs
            __R30 &= LCD_0s;
            break;

            
        default:
            break;
    }
}

void printRegBin_LCD(uint32_t Reg){

    
    int i;
    char c = 'B';
    
    
    char *cPtr = &c;

    printStr_LCD(cPtr);
    
    for(i=31;i>=0;i--){
        if((Reg & (0x0001 << i))){
            c = '1';
        }
        else{
            c = '0';

        }
        printStr_LCD(cPtr);
    }

    c = '>';
    printStr_LCD(cPtr);
}
    


    


// Vlad's version with my addition to add a leading zero
void int_to_string(char *aBuffer, int length, unsigned long data){
    int index;
//    strcpy(aBuffer,"                    ");
    aBuffer[length-1]='\0';
    for (index=length-2; index >= 0; index--)
    {   if (data > 0 )
        {        char digit = data % 10;
                  aBuffer[index] = digit + '0';
                   data = data / 10;
        }
        else{
            aBuffer[index] = '0';
            index--;
            while(index >= 0){
                aBuffer[index] = ' ';
                index--;
            }
        }
    }
    
}


//Fisher's version
/*
void int_to_string(char *aBuffer, int length, unsigned long data){
    int index;
    char digit = '\0';
//    aBuffer[length-1]='\0';
    for (index = 0; index > length; index++)
    {   if (data > 0 )
        {        digit = data % 10;
                  aBuffer[index] = digit + '0';
                   data = data / 10;
        }
        else 
        aBuffer[index] = '0';
        
        
    }
    
}
*/

//More intelligent functions which use above simple ones.
/*void printLine_LCD(int lineNo, char *Print_Str)
void SetMode_LCD()
*/


    


