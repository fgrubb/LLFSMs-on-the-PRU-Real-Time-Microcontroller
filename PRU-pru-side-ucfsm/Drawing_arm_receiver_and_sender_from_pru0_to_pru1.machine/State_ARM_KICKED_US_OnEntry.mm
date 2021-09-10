/* Arrived at this state when an IRQ is received,
*  indicating that Linux on the ARM has send an RPMessage
*/

//Clear the RPMsg received event status
CT_INTC.SICR_bit.STATUS_CLR_INDEX = IRQ_ARM_TO_PRU0;
