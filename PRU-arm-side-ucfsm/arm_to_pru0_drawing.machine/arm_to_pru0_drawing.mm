//
// arm_to_pru0_drawing.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"

#include "State_InitialPseudoState.h"
#include "State_INITIAL.h"
#include "State_FILES_OPEN.h"
#include "State_FAILED_TO_OPEN.h"
#include "State_COPY_CHAR.h"
#include "State_OUTPUT_BLOCK.h"
#include "State_OUTPUT_TAIL.h"
#include "State_INCREMENT.h"

using namespace FSM;
using namespace CLM;

extern "C"
{
	arm_to_pru0_drawing *CLM_Create_arm_to_pru0_drawing(int mid, const char *name)
	{
		return new arm_to_pru0_drawing(mid, name);
	}
}

arm_to_pru0_drawing::arm_to_pru0_drawing(int mid, const char *name): CLMachine(mid, name)
{
	_states[0] = new FSMarm_to_pru0_drawing::State::InitialPseudoState;
	_states[1] = new FSMarm_to_pru0_drawing::State::INITIAL;
	_states[2] = new FSMarm_to_pru0_drawing::State::FILES_OPEN;
	_states[3] = new FSMarm_to_pru0_drawing::State::FAILED_TO_OPEN;
	_states[4] = new FSMarm_to_pru0_drawing::State::COPY_CHAR;
	_states[5] = new FSMarm_to_pru0_drawing::State::OUTPUT_BLOCK;
	_states[6] = new FSMarm_to_pru0_drawing::State::OUTPUT_TAIL;
	_states[7] = new FSMarm_to_pru0_drawing::State::INCREMENT;

	setInitialState(_states[0]);            // set initial state
}

arm_to_pru0_drawing::~arm_to_pru0_drawing()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
	delete _states[4];
	delete _states[5];
	delete _states[6];
	delete _states[7];
}
