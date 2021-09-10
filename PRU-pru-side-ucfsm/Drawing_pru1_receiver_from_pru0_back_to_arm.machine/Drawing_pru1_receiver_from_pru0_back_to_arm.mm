//
//Drawing_pru1_receiver_from_pru0_back_to_arm.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "Drawing_pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "Drawing_pru1_receiver_from_pru0_back_to_arm.h"

#include "State_INITIAL.h"
#include "State_COMMS_READY.h"
#include "State_CHANNEL_CREATED.h"
#include "State_CHECK_IRQ_FROM_PRU0.h"
#include "State_RECEIVED_FROM_PRU0.h"
#include "State_SEND_TO_ARM.h"

using namespace FSM;
using namespace CLM;
extern "C"
{
	Drawing_pru1_receiver_from_pru0_back_to_arm *CLM_Create_Drawing_pru1_receiver_from_pru0_back_to_arm(int mid, const char *name)
	{
		return new Drawing_pru1_receiver_from_pru0_back_to_arm(mid, name);
	}
}

Drawing_pru1_receiver_from_pru0_back_to_arm::Drawing_pru1_receiver_from_pru0_back_to_arm(int mid, const char *name): CLMachine(mid, name)
{
	_states[0]  = new FSMDrawing_pru1_receiver_from_pru0_back_to_arm::State:: INITIAL;
	_states[1]  = new FSMDrawing_pru1_receiver_from_pru0_back_to_arm::State:: COMMS_READY;
	_states[2]  = new FSMDrawing_pru1_receiver_from_pru0_back_to_arm::State:: CHANNEL_CREATED;
	_states[3]  = new FSMDrawing_pru1_receiver_from_pru0_back_to_arm::State:: CHECK_IRQ_FROM_PRU0;
	_states[4]  = new FSMDrawing_pru1_receiver_from_pru0_back_to_arm::State:: RECEIVED_FROM_PRU0;
	_states[5]  = new FSMDrawing_pru1_receiver_from_pru0_back_to_arm::State:: SEND_TO_ARM;

	setInitialState(_states[0]);            // set initial state
}

Drawing_pru1_receiver_from_pru0_back_to_arm::~Drawing_pru1_receiver_from_pru0_back_to_arm()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
}
