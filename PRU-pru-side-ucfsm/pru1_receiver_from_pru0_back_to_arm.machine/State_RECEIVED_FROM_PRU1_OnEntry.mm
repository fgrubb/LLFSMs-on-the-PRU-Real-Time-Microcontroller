//This state receives structs, then goes to "SEND_TO_ARM" state for RPMSG send back to Linux.
//Should arrive here due to receiving IRQ: IRQ_XFR_PRU0_TO_PRU1

//From check IRQ state:
CT_INTC.SICR = IRQ_XFR_PRU0_TO_PRU1;		//Clear IRQ
__R31 = IRQ_XFR_PRU1_TO_PRU0 + PRU_IRQ_out_strobe;	// signal sent to PRU0 to immediately receive
//end IRQ state

while (!(CT_INTC.SECR0_bit.ENA_STATUS_31_0 & (1 << IRQ_XFR_PRU0_TO_PRU1)));

Comms_PRU_ucFSM local_Buffer;
CT_INTC.SICR = IRQ_XFR_PRU0_TO_PRU1;		//Clear IRQ

//	if ( CT_INTC.SECR0_bit.ENA_STATUS_31_0 & (1 << IRQ_XFR_PRU0_TO_PRU1)) {
	__xin(14, 5, 0, local_Buffer);
	five_beeps_a_second(PRU_1_RED_LED);
	
//dynamic_Buffer is accessed through a pointer and causes issues with the C++ PRU compiler, so local struct is used and copied to dynamic
dynamic_Buffer = local_Buffer;

/*
__R30 = local_Buffer.LEDs0;
    __delay_cycles(Delay_0_2S);
    __R30 = 0;
    __delay_cycles(Delay_0_2S);
	
__R30 = local_Buffer.LEDs1;
    __delay_cycles(Delay_0_2S);
    __R30 = 0;
    __delay_cycles(Delay_0_2S);
	
__R30 = local_Buffer.LEDs2;
    __delay_cycles(Delay_0_2S);
    __R30 = 0;
    __delay_cycles(Delay_0_2S);
	
__R30 = local_Buffer.LEDs3;
    __delay_cycles(Delay_0_2S);
    __R30 = 0;
    __delay_cycles(Delay_0_2S);
	
__R30 = local_Buffer.LEDs4;
    __delay_cycles(Delay_0_2S);
    __R30 = 0;
    __delay_cycles(Delay_0_2S);
	
__R30 = local_Buffer.LEDs5;
    __delay_cycles(Delay_0_2S);
    __R30 = 0;
    __delay_cycles(Delay_0_2S);
*/
