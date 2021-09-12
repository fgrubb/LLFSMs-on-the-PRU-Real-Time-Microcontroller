//
//arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
arm_receiver_and_sender_from_pru0_to_pru1 *_m = static_cast<arm_receiver_and_sender_from_pru0_to_pru1 *>(_machine);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wshadow"

uint8_t*	&payload= _m->payload;	///<
pru_rpmsg_transport	&transport= _m->transport;	///<
uint16_t	&src= _m->src;	///<
uint16_t	&dst= _m->dst;	///<
uint16_t	&len= _m->len;	///<
volatile uint8_t*	&status= _m->status;	///<
Resource_Table_Wrapper*	&resource_table_wrapper= _m->resource_table_wrapper;	///<
Comms_PRU_ucFSM	&dynamic_Buffer= _m->dynamic_Buffer;	///<

#pragma clang diagnostic pop
