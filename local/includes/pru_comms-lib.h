/*******************************************************************************

(c) 2021 Vlad Estivill-Castro

Function library to fill a struct with string characters for
sending over the XFR bus.
Used a form of bit shifting to hold 4 bytes per 32 bit register.
This is extrapolated from TI's "direct connect" example.
*******************************************************************************/



typedef struct {
	uint32_t Data1;
	uint32_t Data2;
	uint32_t Data3;
	uint32_t Data4;
	uint32_t Data5;
	uint32_t Data6;
} ucFSM_PRU_XFR_6;

typedef struct {
        uint32_t LEDs0;
        uint32_t LEDs1;
        uint32_t LEDs2;
        uint32_t LEDs3;
        uint32_t LEDs4;
        uint32_t LEDs5;
} Comms_PRU_ucFSM;

void fill_field(char first, char second, char third, char fourth,  uint32_t *field);

void fill_struct_data(char* in,  ucFSM_PRU_XFR_6 *theStruct);
void fill_struct_with_pattern_data(int start,   ucFSM_PRU_XFR_6 *theStruct);
void fill_struct_with_pattern_LEDS(int start,   Comms_PRU_ucFSM *theStruct);
void fill_struct_LEDS(char* in,  Comms_PRU_ucFSM *theStruct);
void fill_struct_LEDS_unsigned(uint8_t* in,  Comms_PRU_ucFSM *theStruct);


void get_field (char *out, uint32_t aPosition);

void get_struct (char *out, Comms_PRU_ucFSM aStruct);

int led_pattern ( uint32_t first_led, uint32_t secod_led, uint32_t third_led, uint32_t forth_led, int as_value) ;
