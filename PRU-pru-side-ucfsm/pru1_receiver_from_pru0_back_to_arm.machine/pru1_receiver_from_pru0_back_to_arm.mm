//
//pru1_receiver_from_pru0_back_to_arm.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "pru1_receiver_from_pru0_back_to_arm.h"

#include "State_INITIAL.h"
#include "State_COMMS_READY.h"
#include "State_CHANNEL_CREATED.h"
#include "State_CHECK_IRQ_FROM_PRU0.h"
#include "State_SEND_TO_ARM.h"
#include "State_ARM_KICKED_US.h"
#include "State_RECEIVED_FROM_PRU0.h"

using namespace FSM;
using namespace CLM;
extern "C"
{
	pru1_receiver_from_pru0_back_to_arm *CLM_Create_pru1_receiver_from_pru0_back_to_arm(int mid, const char *name)
	{
		return new pru1_receiver_from_pru0_back_to_arm(mid, name);
	}
}

pru1_receiver_from_pru0_back_to_arm::pru1_receiver_from_pru0_back_to_arm(int mid, const char *name): CLMachine(mid, name)
{
	_states[0]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: INITIAL;
	_states[1]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: COMMS_READY;
	_states[2]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: CHANNEL_CREATED;
	_states[3]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: CHECK_IRQ_FROM_PRU0;
	_states[4]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: SEND_TO_ARM;
	_states[5]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: ARM_KICKED_US;
	_states[6]  = new FSMpru1_receiver_from_pru0_back_to_arm::State:: RECEIVED_FROM_PRU0;

	setInitialState(_states[0]);            // set initial state
}

pru1_receiver_from_pru0_back_to_arm::~pru1_receiver_from_pru0_back_to_arm()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
}
