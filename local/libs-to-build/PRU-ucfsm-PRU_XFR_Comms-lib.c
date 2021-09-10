/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)  Tue 27th April 2021.
 * Code to test different features of the PRU, 
 * generally focusing on 20 x 4 char LCD & LEDs.
 * 
 * Generic: TODO: scratch pad, PRU-PRU XFR etc device constants.
 * 
 * This specific library manages comms between PRU & ARM
 * functions & uses structs facilitate transferring data 
 * between ARM & PRU, or PRU0 & PRU1.
 * Received characters may be displayed on the LCD,
 * or LED patterns flashed.
 * 
 * Usual usage: received by PRU0 from ARM, is sent to
 * PRU1 then back to the ARM as a demo or after data processed.
 */

#include <stdint.h>
#include "PRU-ucfsm-PRU_XFR_Comms-lib.h"
//#include "PRU-ucfsm-PRU_IRQ-lib.h"


/* This struct is used to pass data between PRU cores,
 * using intrinsic transfer instructions __xin() & __xout()
 * Besides initialising this inside main, it might be important 
 * to declare a variable of this struct above main so the 
 * compiler is guaranteed to put the 1st var in register 5, limit
 * maybe up to r13, though declaring in main, or before
 * may not make any difference
 * __xin() & __xout() are capable of up to 44 bytes transfered in a single
 * call, this should be around 11 registers, but likely using
 * assembly to have more control.
 * Using C/C++ is limited by how many registers the compiler allows for to allocate
 * consecutive registers when the struct is passed to a single function.
 * Max transfer hasn't been tested due to only using C&C++
 * without direct register control.
 * See: Sect 6.3 (P110), 5.11 (P93) SPRUHV7C PRU C/C++ compiler doc
 * Also: Sect 30.1.5.3 (P7386) up to 30.1.5.5 (P7391) of SPRUHZ6L AM572x Tech Ref Manual
 */
/* Below structs are in header file
typedef struct {
	uint32_t Data1;
	uint32_t Data2;
	uint32_t Data3;
	uint32_t Data4;
	uint32_t Data5;
	uint32_t Data6;
} ucFSM_PRU_XFR_6;

typedef struct {
	uint32_t Data1;
	uint32_t Data2;
	uint32_t Data3;
	uint32_t Data4;
	uint32_t Data5;
	uint32_t Data6;
    uint32_t Data7;
    uint32_t Data8;
    uint32_t Data9;
} ucFSM_PRU_XFR_9
*/
/* XFR based functions: transfer data between Scratchpad registers, PRU0 & PRU1 cores 
 * (within same PRUSS).
 * 
 * Constants in header:
#define XFR_DEV_SCRATCH_0 =     10;
#define XFR_DEV_SCRATCH_1 =     11;
#define XFR_DEV_SCRATCH_2 =     12;
#define XFR_DEV_PRU =           14;
*/

/*
 * Expects: PRU0 sends IRQ_XFR_PRU0_TO_PRU1 to PRU1
 * PRU1 does what it needs, then sends IRQ_XFR_PRU1_TO_PRU0
 * Then runs __xin(), will lock onto XFR bus for 1024 cycles
 * waiting for PRU0 to send struct.
 */
/*
void XFR_PRU_Rx_Struct6(ucFSM_PRU_XFR_6 *Struct){
	
	PRU_send_IRQ(IRQ_XFR_PRU1_TO_PRU0);
			__xin(14,5, 0, *Struct);
}
*/
void XFR_PRU_Tx_Struct6_len(char * Str_tx, unsigned int Str_len, unsigned int Str_index, ucFSM_PRU_XFR_6 * Struct){
	
	unsigned int Chars = 4;
	unsigned int Char_times = (Str_len - Str_index);
	if(Char_times >= 24){
		Char_times = 6;
	}else{
		Char_times /= 4;
	}
	
	
		union_Reg_4Char Union_4Char;

	/*	Definition in header file
		Union_4Char2,
		Union_4Char3,
		Union_4Char4,
		Union_4Char5,
		Union_4Char6;
		
		Union_4Char1.Char1 = 
	*/	
	
		if(Char_times == 0){
			Chars = Str_len - Str_index;
		}
			fill_char_union(Str_tx,Str_index, Chars, &Union_4Char);
			Struct->Data1 = Union_4Char.Reg_4Char;
			Str_index  += 4;
			Char_times --;
		if(Char_times == 0){
			Chars = Str_len - Str_index;
		}
			fill_char_union(Str_tx,Str_index, Chars, &Union_4Char);
			Struct->Data2 = Union_4Char.Reg_4Char;
			Str_index  += 4;
			Char_times --;
		if(Char_times == 0){
			Chars = Str_len - Str_index;
		}
			fill_char_union(Str_tx,Str_index, Chars, &Union_4Char);
			Struct->Data3 = Union_4Char.Reg_4Char;
			Str_index  += 4;
			Char_times --;
		if(Char_times == 0){
			Chars = Str_len - Str_index;
		}
			fill_char_union(Str_tx,Str_index, Chars, &Union_4Char);
			Struct->Data4 = Union_4Char.Reg_4Char;
			Str_index  += 4;
			Char_times --;
		if(Char_times == 0){
			Chars = Str_len - Str_index;
		}
			fill_char_union(Str_tx,Str_index, Chars, &Union_4Char);
			Struct->Data5 = Union_4Char.Reg_4Char;
			Str_index  += 4;
			Char_times --;
		if(Char_times == 0){
			Chars = Str_len - Str_index;
		}
			fill_char_union(Str_tx,Str_index, Chars, &Union_4Char);
			Struct->Data6 = Union_4Char.Reg_4Char;
}

void fill_char_union(char * Str_tx, unsigned int Char_index, unsigned int Chars, union_Reg_4Char * Union_4Char){
	if(Chars > 0){
		Union_4Char->Reg_4Char_byte.Char1 = Str_tx[Char_index];
		Chars --;
	}else{
		Union_4Char->Reg_4Char_byte.Char1 = '\0';
	}
	if(0 < Chars){
		Union_4Char->Reg_4Char_byte.Char2 = Str_tx[Char_index+1];
		Chars --;
	}else{
		Union_4Char->Reg_4Char_byte.Char2 = '\0';
	}
	if(0 < Chars){
		Union_4Char->Reg_4Char_byte.Char3 = Str_tx[Char_index+2];
		Chars --;
	}else{
		Union_4Char->Reg_4Char_byte.Char3 = '\0';
	}
	if(0 < Chars){
		Union_4Char->Reg_4Char_byte.Char4 = Str_tx[Char_index+3];
		Chars --;
	}else{
		Union_4Char->Reg_4Char_byte.Char4 = '\0';
	}
}

/*
void pru_xfr_tx(int xfr_dev, struct ucFSM_PRU_XFR){
    __xout(xfr_dev, 5, 0, ucFSM_PRU_XFR);
}

void pru_xfr_rx(int xfr_dev, struct ucFSM_PRU_XFR){
    __xin(xfr_dev, 5, 0, ucFSM_PRU_XFR);
}
*/

/* Check if PRU core XFR had a timeout IRQ
 * This is important to know if successful or not
 * 
 * This one sets it up.

void pru_pru_xfr_irq_init(){
    
}
 */
/* Maybe not needed
 * Check if XFR IRQ occurred (& clear it)
 * returns an int(1 is true for occurred,
 * 0 for false).

int pru_pru_xfr_irq_check(){
    
}
 */


