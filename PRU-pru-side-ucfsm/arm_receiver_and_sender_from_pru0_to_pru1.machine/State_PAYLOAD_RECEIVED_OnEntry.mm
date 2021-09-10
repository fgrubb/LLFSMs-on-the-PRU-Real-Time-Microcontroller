//for (uint16_t i=0; i<len; i++) { // convert to Leds pattern and show for one second
	fill_struct_LEDS_unsigned(payload,  &dynamic_Buffer);
//}//for

//Send IRQ to PRU1 so it gets ready to receive struct
__R31 = IRQ_XFR_PRU0_TO_PRU1 + PRU_IRQ_out_strobe;
