/*
 *  Written by Fisher Grubb for MPhil under
 * Vladimir Estivill-Castro & Rene Hexel
 * (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 * June 2021.
 * 
 * 
 * Library to handle PRU interrupts.
 * basics are to generate and check.
 * Linux RemoteProc kernel module can set up IRQs
 * if correctly defined as arrays in .resource_table header.
 * Should have included register header files,
 * such as ctrl & intc for general control, and interrupts.
 */

#ifndef _PRU_UCFSM_IRQ_LIB_H_
#define _PRU_UCFSM_IRQ_LIB_H_

/*To be added to any IRQ value that the PRU will generate to "strobe" it.
 * Check the TRM for the section of PRU core
 * functionality of generating IRQs,
 * you'll see the "strobe output"
 */
#define PRU_IRQ_out_strobe			16

void PRU_send_IRQ(int IRQ_index);
int PRU_check_IRQ(int IRQ_index);

#endif //_PRU_UCFSM_IRQ_LIB_H_
