/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 *  
 * Part of PRU implementation library for ucFSM
 * 
 * Code to test different features of the PRU, focusing on 20 x 4 char LCD.
 * 
 * File: PRU-ucfsm-LCD.c
 */


#include <stdint.h>
#include "PRU-ucfsm-general-defines.h"
#include "PRU-LEDS.h"

void one_beep_a_second(int aLed) {
            __R30 = aLed;
            __delay_cycles(Delay_Half_A_Sec);

            __R30 = 0;
            __delay_cycles(Delay_Half_A_Sec);
}

void two_beeps_a_second(int aLed) {
	int i;
	for(i=0; i<2; i++) {
            __R30 = aLed;
            __delay_cycles(Delay_Quarter_A_Sec);

            __R30 = 0;
            __delay_cycles(Delay_Quarter_A_Sec);
	}
}

void five_beeps_a_second(int aLed) {
	int i;
	for(i=0; i<5; i++) {
            __R30 = aLed;
            __delay_cycles(Delay_Tenth_A_Sec);

            __R30 = 0;
            __delay_cycles(Delay_Tenth_A_Sec);
	}
}

