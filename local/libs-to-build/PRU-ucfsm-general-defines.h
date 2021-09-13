/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 *  
 * Part of PRU implementation library for ucFSM
 * 
 * Code to test different features of the PRU, containing general defines used in most basic programs.
 * 
 * File: PRU-ucfsm-general-defines.h
 * 
 * Todo: complete PRU board wiring to all LEDs, buttons etc & complete these definitions
 * 
 * These PRU IO hardware defintions relate to the
 * device tree file.
 * This file is compiled into a dev tree binary, uBoot runs
 * on startup.  Linux initialises these HW configs, MUX.
 * The PRU Cape has these connections by default.
 * One may make their own prototyping board
 */

//PRU2_0 stuff	(/sys/class -> remoteproc/6)

#define LED5    (1 << 0)       //pr2_pru0_go0 on P8.44
#define LED6    (1 << 1)       //pr2_pru0_gpo1 on P8.41
#define LED7    (1 << 2)       //pr2_pru0_gpo2 on P8.42

//#define Button1 (0 << 11)       //pr1_pru1_gpi11 on P9.27A

//PRU2_1 stuff	(/sys/class -> remoteproc/7)
#define LED1    (1 << 7)       //pr2_pru1_gpo7 on P9.31B, also pr2_pru1_gpo10 on P9.31A
#define LED2    (1 << 11)      //pr2_pru1_gpo11 on P9.29A
#define LED3    (1 << 12)      //pr2_pru1_gpo7 on P9.30
#define LED4    (1 << 13)      //pr2_pru1_gpo13 on P9.28

#define PRU_0_BLUE_LED  LED5
#define PRU_0_GREEN_LED  LED6
#define PRU_0_RED_LED  LED7
#define PRU_1_BLUE_LED  LED1
#define PRU_1_GREEN_LED  LED2
#define PRU_1_AMBER_LED  LED3
#define PRU_1_RED_LED  LED4
 
//Below are PRU delay times based on cycles @200MHz
#define Delay_0_5uS  100
#define Delay_1uS   200
#define Delay_2uS   400
#define Delay_37uS  7400
#define Delay_38uS  7600
#define Delay_40uS  8000
#define Delay_100uS  20000
#define Delay_1mS  200000
#define Delay_1_6mS  320000
#define Delay_4_1mS  820000
#define Delay_0_1S	20000000
#define Delay_0_2S	40000000
#define Delay_0_5S  100000000
#define Delay_1S    200000000
#define Delay_5S    1000000000
#define Delay_9S    1800000000
#define Delay_10S   2000000000

#define Delay_Half_A_Sec	Delay_0_5S
#define Delay_Quarter_A_Sec	50000000
#define Delay_Tenth_A_Sec	Delay_0_1S


/*Important register definitions, part of all code running on the PRU.
 * Almost all PRU code has to read or write to these registers.
 * Keep in mind that each core has these.
 * Used to set IO: LEDs, LCD
 * Send IRQ flags such as to another PRU, Linux on the ARM
 */
/*PRU_UCFSM is used as a compiler flag in the Makefile
* If this library is built for the PRU, then the below
* line is built in to the library, if on Linux, then not
*/
#ifdef PRU_UCFSM
volatile register uint32_t __R30, __R31;
#endif
