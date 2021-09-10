//
//arm_receiver_and_sender_from_pru0_to_pru1.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "arm_receiver_and_sender_from_pru0_to_pru1_Includes.h"
#include "arm_receiver_and_sender_from_pru0_to_pru1.h"

#include "State_InitialPseudoState.h"
#include "State_INITIAL.h"
#include "State_COMMS_READY.h"
#include "State_CHANNEL_CREATED.h"
#include "State_ARM_KICKED_US.h"
#include "State_PAYLOAD_RECEIVED.h"
#include "State_SEND_TO_OTHER_PRU.h"

using namespace FSM;
using namespace CLM;
extern "C"
{
	arm_receiver_and_sender_from_pru0_to_pru1 *CLM_Create_arm_receiver_and_sender_from_pru0_to_pru1(int mid, const char *name)
	{
		return new arm_receiver_and_sender_from_pru0_to_pru1(mid, name);
	}
}

arm_receiver_and_sender_from_pru0_to_pru1::arm_receiver_and_sender_from_pru0_to_pru1(int mid, const char *name): CLMachine(mid, name)
{
	_states[0]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: InitialPseudoState;
	_states[1]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: INITIAL;
	_states[2]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: COMMS_READY;
	_states[3]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: CHANNEL_CREATED;
	_states[4]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: ARM_KICKED_US;
	_states[5]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: PAYLOAD_RECEIVED;
	_states[6]  = new FSMarm_receiver_and_sender_from_pru0_to_pru1::State:: SEND_TO_OTHER_PRU;

	setInitialState(_states[0]);            // set initial state
}

arm_receiver_and_sender_from_pru0_to_pru1::~arm_receiver_and_sender_from_pru0_to_pru1()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
}
