payload  =  new uint8_t[RPMSG_MESSAGE_SIZE];
resource_table_wrapper = new Resource_Table_Wrapper();

// Clear the status of all interrupts
CT_INTC.SECR0 = 0xFFFFFFFF;
CT_INTC.SECR1 = 0xFFFFFFFF;
// Allow OCP master port access by the PRU so the PRU can read external memories
CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

// Make sure the Linux drivers are ready for RPMsg communication
status = & resource_table_wrapper -> to_resourceTable -> rpmsg_vdev.status;
