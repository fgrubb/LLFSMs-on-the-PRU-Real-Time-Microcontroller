/* Arrived at this state after ARM to PRU0 IRQ, and RPMsg receiving function run.
*  There will be a string of 24 or less chars in buffer.
*/

//String received, now put all 24 chars into a struct.
	fill_struct_LEDS_unsigned(payload,  &dynamic_Buffer);

//Send IRQ to PRU1 so it gets ready to receive struct
__R31 = IRQ_XFR_PRU0_TO_PRU1 + PRU_IRQ_out_strobe;
