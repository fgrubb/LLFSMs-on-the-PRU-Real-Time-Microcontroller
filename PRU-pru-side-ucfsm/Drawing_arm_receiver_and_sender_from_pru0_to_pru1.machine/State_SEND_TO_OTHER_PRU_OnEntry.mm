/*Arrived in this state due to PRU1 sending reply IRQ to show ready to receive.
*  Local struct has to be created as global can't be used due to pointer issue with the compiler
*  The final IRQ handshake just before __xout() is called should prefent any timout issues.
*/

//Create local temp struct buffer
Comms_PRU_ucFSM local_Buffer = dynamic_Buffer;

///Clear final IRQ flag, send last IRQ, then send struct to other PRU
CT_INTC.SICR = IRQ_XFR_PRU1_TO_PRU0;
__R31 = IRQ_XFR_PRU0_TO_PRU1 + PRU_IRQ_out_strobe;
__xout(14, 5, 0, local_Buffer);


/* __xin() and __xout() are intrinsic, essentially assembly instructions.
*  They expect data in a specific register, the compiler always starts with reg5 in functions
*/
