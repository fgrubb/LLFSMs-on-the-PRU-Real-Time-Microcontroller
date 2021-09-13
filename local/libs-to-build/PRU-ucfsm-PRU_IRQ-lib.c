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
 */

#include <stdint.h>
#include <pru_intc.h>
#include "PRU-ucfsm-general-defines.h"
#include "PRU-ucfsm-PRU_IRQ-lib.h"

/* IRQ nums should be defined at the top of program.
 * IRQs should have already been configured,
 *likely by  resource_table header, or manually
 */
void PRU_send_IRQ(int IRQ_index){
	//Generate IRQ to other PRU or device
	__R31 = IRQ_index + PRU_IRQ_out_strobe;
}

/* Likely expects receiving host was checked:
 * __R31 & HOST0_IRQ_bit,  or HOST1_IRQ_bit
 */
int PRU_check_IRQ(int IRQ_index){
		if(CT_INTC.SECR0_bit.ENA_STATUS_31_0 & (1 << IRQ_index)){
			CT_INTC.SICR_bit.STATUS_CLR_INDEX = IRQ_index;
			return 1;
		}
	else{
		return 0;
	}
} 

