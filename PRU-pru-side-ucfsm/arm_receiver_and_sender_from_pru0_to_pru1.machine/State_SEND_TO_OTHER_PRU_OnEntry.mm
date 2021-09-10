Comms_PRU_ucFSM local_Buffer = dynamic_Buffer;

CT_INTC.SICR = IRQ_XFR_PRU1_TO_PRU0;		//Clear IRQ
__R31 = IRQ_XFR_PRU0_TO_PRU1 + PRU_IRQ_out_strobe;	// signal sent to PRU1 to immediately receive this
__xout(14, 5, 0, local_Buffer);

five_beeps_a_second(PRU_0_RED_LED);
