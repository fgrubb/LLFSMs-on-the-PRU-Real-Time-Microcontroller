// Initialize the RPMsg transport structure
pru_rpmsg_init(&transport, 
   &resource_table_wrapper -> to_resourceTable -> rpmsg_vring0,
   &resource_table_wrapper -> to_resourceTable -> rpmsg_vring1, 
   IRQ_PRU0_TO_ARM, 
    IRQ_ARM_TO_PRU0);
two_beeps_a_second(PRU_0_BLUE_LED);
