//
//pru1_to_arm.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_to_arm_Includes.h"
#include "pru1_to_arm.h"

#include "State_InitialPseudoState.h"
#include "State_INITIAL.h"
#include "State_FILES_OPEN.h"
#include "State_FAILED_TO_OPEN.h"
#include "State_BLOCK_READ.h"
#include "State_OUTPUT_DATA.h"
#include "State_CLOSE_FILES.h"

using namespace FSM;
using namespace CLM;
extern "C"
{
	pru1_to_arm *CLM_Create_pru1_to_arm(int mid, const char *name)
	{
		return new pru1_to_arm(mid, name);
	}
}

pru1_to_arm::pru1_to_arm(int mid, const char *name): CLMachine(mid, name)
{
	_states[0]  = new FSMpru1_to_arm::State:: InitialPseudoState;
	_states[1]  = new FSMpru1_to_arm::State:: INITIAL;
	_states[2]  = new FSMpru1_to_arm::State:: FILES_OPEN;
	_states[3]  = new FSMpru1_to_arm::State:: FAILED_TO_OPEN;
	_states[4]  = new FSMpru1_to_arm::State:: BLOCK_READ;
	_states[5]  = new FSMpru1_to_arm::State:: OUTPUT_DATA;
	_states[6]  = new FSMpru1_to_arm::State:: CLOSE_FILES;

	setInitialState(_states[0]);            // set initial state
}

pru1_to_arm::~pru1_to_arm()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
}
