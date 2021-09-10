/* Arrived in this state due to the status variable being set indicating the Linux driver is ready.
*  A single struct is initialised with:
*  2 x pre-allocated Vring buffers as set in the resource_table header.
*  the 2 IRQ addresses uses when something is written to these (from both PRU & ARM sides)
*/

// Initialize the RPMsg transport structure
pru_rpmsg_init(&transport, 
   &resource_table_wrapper -> to_resourceTable -> rpmsg_vring0,
   &resource_table_wrapper -> to_resourceTable -> rpmsg_vring1, 
   IRQ_PRU0_TO_ARM, 
    IRQ_ARM_TO_PRU0);
