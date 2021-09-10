five_beeps_a_second(PRU_0_GREEN_LED);

if(CT_INTC.SECR0_bit.ENA_STATUS_31_0 & (1 << IRQ_XFR_TIMEOUT)){
	CT_INTC.SICR = IRQ_XFR_TIMEOUT;		//Clear IRQ
	five_beeps_a_second(PRU_0_BLUE_LED);
	five_beeps_a_second(PRU_0_GREEN_LED);
	five_beeps_a_second(PRU_0_RED_LED);
}

