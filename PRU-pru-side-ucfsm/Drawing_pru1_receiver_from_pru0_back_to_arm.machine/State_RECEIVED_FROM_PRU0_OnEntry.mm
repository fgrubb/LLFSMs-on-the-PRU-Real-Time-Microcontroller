//This state receives structs, then goes to "SEND_TO_ARM" state for RPMSG send back to Linux.
//Should arrive here due to receiving IRQ: IRQ_XFR_PRU0_TO_PRU1

Comms_PRU_ucFSM local_Buffer;
//Clear IRQ
CT_INTC.SICR = IRQ_XFR_PRU0_TO_PRU1;

__xin(14, 5, 0, local_Buffer);
	
//dynamic_Buffer is accessed through a pointer and causes issues with the C++ PRU compiler, so local struct is used and copied to dynamic
dynamic_Buffer = local_Buffer;
