/*******************************************************************************

(c) 2021 Vlad Estivill-Castro

Function library to fill a struct with string characters for
sending over the XFR bus.
Used a form of bit shifting to hold 4 bytes per 32 bit register.
This is extrapolated from TI's "direct connect" example.
*******************************************************************************/

#include <stdint.h>
#include "pru_comms-lib.h"

void fill_field(char first, char second, char third, char fourth,  uint32_t *field)
 {
        uint32_t first_field = first;
        uint32_t second_field = second << 8;
        uint32_t third_field = third << 16;
        uint32_t fourth_field = fourth << 24;
        *field = first_field | second_field  | third_field | fourth_field;
}

void fill_struct_data(char* in,  ucFSM_PRU_XFR_6 *theStruct)
{
	int p=0;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->Data1);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->Data2);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->Data3);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->Data4);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->Data5);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->Data6);
}

void fill_struct_with_pattern_data(int start, ucFSM_PRU_XFR_6 *theStruct){
        int aPattern;
        int index;
        char data[24];

        for (index =0; index < 24; index++)
          {  aPattern=(index+start)%16;
             data [index] =0;

             char the_led1 = ((aPattern % 2) == 1) ? 0x01 : 0;
             char the_led2 =  (((aPattern >>1) % 2) == 1) ? 0x02 : 0;
             char the_led3 =  (((aPattern >>2) % 2) == 1) ? 0x04 : 0;
             char the_led4 =  (((aPattern >>3) % 2) == 1) ? 0x08 : 0;

             data [index] = the_led1 | the_led2 | the_led3 | the_led4;
           }
	fill_struct_data(data,  theStruct);
}

void fill_struct_LEDS_unsigned(uint8_t* in,  Comms_PRU_ucFSM *theStruct)
{
	int p=0;
	fill_field( in[p+0], in[p+1],in[p+2],in[p+3], & theStruct->LEDs0);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs1);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs2);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs3);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs4);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs5);
}

void fill_struct_LEDS(char* in,  Comms_PRU_ucFSM *theStruct)
{
	int p=0;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs0);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs1);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs2);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs3);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs4);
	p=p+4;
	fill_field(in[p+0],in[p+1],in[p+2],in[p+3], & theStruct->LEDs5);
}

void fill_struct_with_pattern_LEDS(int start, Comms_PRU_ucFSM *theStruct){
        int aPattern;
        int index;
        char data[24];

        for (index =0; index < 24; index++)
          {  aPattern=(index+start)%16;
             data [index] =0;

             char the_led1 = ((aPattern % 2) == 1) ? 0x01 : 0;
             char the_led2 =  (((aPattern >>1) % 2) == 1) ? 0x02 : 0;
             char the_led3 =  (((aPattern >>2) % 2) == 1) ? 0x04 : 0;
             char the_led4 =  (((aPattern >>3) % 2) == 1) ? 0x08 : 0;

             data [index] = the_led1 | the_led2 | the_led3 | the_led4;
           }
	fill_struct_LEDS(data,  theStruct);
}

void get_field (char *out, uint32_t aField)
{
	out[0] = aField & 0x000000FF;
	out[1] = (aField & 0x0000FF00)>>8;
	out[2] = (aField & 0x00FF0000)>>16;
	out[3] = (aField & 0xFF000000)>>24;
}

void get_struct (char *out, Comms_PRU_ucFSM aStruct)
{
	// pointer arithmetic, better receive the right space
	get_field (out, aStruct.LEDs0);
	get_field (out+4, aStruct.LEDs1);
	get_field (out+8, aStruct.LEDs2);
	get_field (out+12, aStruct.LEDs3);
	get_field (out+16, aStruct.LEDs4);
	get_field (out+20, aStruct.LEDs5);

}

int led_pattern ( uint32_t first_led, uint32_t secod_led, uint32_t third_led, uint32_t forth_led, int as_value) {
	int the_leds =0;
	
	if ((as_value %2) ==1 ) the_leds = the_leds | first_led;
        if (( (as_value>>1) %2) ==1 ) the_leds = the_leds | secod_led;
	if (( (as_value>>2) %2) ==1 ) the_leds = the_leds | third_led;
	if (( (as_value>>3) %2) ==1 ) the_leds = the_leds | forth_led;

	return the_leds;
}
