/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)  Tue 27th April 2021.
 * Code to test different features of the PRU, 
 * generally focusing on 20 x 4 char LCD & LEDs.
 * 
 * This specific library manages comms between PRU & ARM
 * functions & uses structs facilitate transferring data 
 * between ARM & PRU, or PRU0 & PRU1.
 * Received characters may be displayed on the LCD.
 * 
 * Usual usage: received by PRU0 from ARM, is sent to
 * PRU1 then back to the ARM as a demo or after data processed.
 *

* Prerequisites:
 * #define TimeOut_Limit (may be 400, likely less than 1024)
 * done in main code, used to break out of while loops if
 * the other side doesn't send or receive.


* This struct is used to pass data between PRU cores,
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
#ifndef _PRU_UCFSM_XFR_LIB_H_
#define _PRU_UCFSM_XFR_LIB_H_
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
} ucFSM_PRU_XFR_9;

/* For splitting data in structs into bytes
 * used in both transimitting and receiving ends
 */

typedef union {
	volatile uint32_t Reg_4Char;
	
	volatile struct {
		uint32_t Char1 : 8;
		uint32_t Char2 : 8;
		uint32_t Char3 : 8;
		uint32_t Char4 : 8;
	}Reg_4Char_byte;
}union_Reg_4Char;



#define XFR_DEV_SCRATCH_0 =     10;
#define XFR_DEV_SCRATCH_1 =     11;
#define XFR_DEV_SCRATCH_2 =     12;
#define XFR_DEV_PRU =           14;

//#define TimeOut_Limit			400


#define IRQ_XFR_TIMEOUT			3	//Check for XFR bus timeout
#define IRQ_XFR_PRU0_TO_PRU1	20	//Check/set PRU0 to PRU1 IRQ for XFR
#define IRQ_XFR_PRU1_TO_PRU0	21	//Check/set PRU1 to PRU0 IRQ for XFR

//void XFR_PRU_Rx_Struct6(ucFSM_PRU_XFR_6 *Struct);

//void XFR_PRU_Tx_Struct6(ucFSM_PRU_XFR_6 *Struct, unsigned int TimeOut_Limit);

void XFR_PRU_Tx_Struct6_len(char * Str_tx, unsigned int Str_len, unsigned int Str_index, ucFSM_PRU_XFR_6 * Struct);
void fill_char_union(char * Str_tx, unsigned int Char_index, unsigned int Chars, union_Reg_4Char * Union_4Char);

/* Functions
 */
/*
void pru_pru_tx();

void pru_pru_xfr_irq_init();

int pru_pru_xfr_irq_check();
*/

#endif //_PRU_UCFSM_XFR_LIB_H_
