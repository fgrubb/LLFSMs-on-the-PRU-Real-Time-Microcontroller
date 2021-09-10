/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 * 
 * Part of PRU implementation library for ucFSM
 * 
 * Code to test different features of the PRU, focusing on IEP timer to measure & keep track of time, especially for the scheduler.
 * 
 * File: PRU-ucfsm-timer.h
 */

//Check which header includes needed
#include <pru_cfg.h>

#include <pru_intc.h>
#include <pru_iep.h>


	/**
	* Initilialise the timer. Called only once per program
	*/

void IEP_timer_init(unsigned int timer_CMP0L, unsigned int timer_prescalar);
	/**
	* testing function of reading after a certain amount of time
	*/
void check_timer_loop(void);



	/**
	* PRU-renewed implementation of a funciton that resturns the number of micro-seconds
	* since the call to IEP_timer_init
	*/
unsigned long micros(void);
