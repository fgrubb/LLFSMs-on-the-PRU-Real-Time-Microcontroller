//
//State_RECEIVED_FROM_PRU0.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "pru1_receiver_from_pru0_back_to_arm.h"

#include "State_RECEIVED_FROM_PRU0.h"
#include "State_RECEIVED_FROM_PRU0_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_receiver_from_pru0_back_to_arm;
using namespace State;

RECEIVED_FROM_PRU0::RECEIVED_FROM_PRU0(const char *name):CLState(name, *new RECEIVED_FROM_PRU0::OnEntry,*new RECEIVED_FROM_PRU0::OnExit, *new RECEIVED_FROM_PRU0::Internal)
{
	_transitions[0] = new Transition_0();
}

RECEIVED_FROM_PRU0::~RECEIVED_FROM_PRU0()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void RECEIVED_FROM_PRU0::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_OnEntry.mm"
}

void RECEIVED_FROM_PRU0::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_OnExit.mm"
}

void RECEIVED_FROM_PRU0::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_Internal.mm"
}

bool RECEIVED_FROM_PRU0::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU0_VarRefs.mm"

	return
	(
#			include "State_RECEIVED_FROM_PRU0_Transition_0.expr"
	);
}


