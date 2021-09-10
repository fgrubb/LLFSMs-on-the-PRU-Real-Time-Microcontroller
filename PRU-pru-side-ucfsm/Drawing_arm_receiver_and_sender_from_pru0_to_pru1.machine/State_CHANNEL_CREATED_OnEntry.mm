/*  Arrived in this state due to the pru_rpmsg_channel() funct confirming success.
*   Structs with pointers to 2 x Vring buffers set correctly.
*   Linux Kernel Module on the ARM should have created an rpmsg_pru file in /dev/.
*   Now communication is ready, the rest of the machine loops back here.
*  The XFR_Timeout IRQ clearing below shouldn't occur, if so, very occasionally, such as PRU cores out of sync.
*/

//Clear the XFR Timeout IRQ or IRQs can lock up
if(CT_INTC.SECR0_bit.ENA_STATUS_31_0 & (1 << IRQ_XFR_TIMEOUT)){
	CT_INTC.SICR = IRQ_XFR_TIMEOUT;		//Clear IRQ
	five_beeps_a_second(PRU_0_BLUE_LED);
	five_beeps_a_second(PRU_0_GREEN_LED);
	five_beeps_a_second(PRU_0_RED_LED);
}

