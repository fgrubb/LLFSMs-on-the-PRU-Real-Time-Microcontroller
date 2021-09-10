//Struct has been received, now it is turned into a string, and send via RPMsg

get_struct ((char *) payload, dynamic_Buffer);
five_beeps_a_second(PRU_1_BLUE_LED);
len = 24;//strlen((char*) payload);
