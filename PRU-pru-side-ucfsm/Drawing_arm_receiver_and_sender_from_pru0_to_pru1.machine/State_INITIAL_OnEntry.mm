payload  =  new uint8_t[RPMSG_MESSAGE_SIZE];
resource_table_wrapper = new Resource_Table_Wrapper();

// Clear the status of all interrupts
CT_INTC.SECR0 = 0xFFFFFFFF;
CT_INTC.SECR1 = 0xFFFFFFFF;

// Allow OCP master port access by the PRU so the PRU can read external memories
CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

/* Clearing the ARM to PRU0 IRQ is redundant due to the above clearing of all IRQs
*  this is left here as an example of good practise for other situations.
*/

// Clear the status of the PRU-ICSS system event that the ARM will use to 'kick' us
//CT_INTC.SICR_bit.STATUS_CLR_INDEX = IRQ_ARM_TO_PRU0;

/* Make sure the Linux drivers are ready for RPMsg communication
*  by pointing to & reading the status variable in the resource_table
*/
status = & resource_table_wrapper -> to_resourceTable -> rpmsg_vdev.status;
