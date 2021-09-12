
CT_INTC.SICR = IRQ_XFR_PRU0_TO_PRU1;		//Clear IRQ
__R31 = IRQ_XFR_PRU1_TO_PRU0 + PRU_IRQ_out_strobe;	// signal sent to PRU0 to immediately receive

