//
//State_COMMS_READY.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "pru1_receiver_from_pru0_back_to_arm.h"

#include "State_COMMS_READY.h"
#include "State_COMMS_READY_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_receiver_from_pru0_back_to_arm;
using namespace State;

COMMS_READY::COMMS_READY(const char *name):CLState(name, *new COMMS_READY::OnEntry,*new COMMS_READY::OnExit, *new COMMS_READY::Internal)
{
	_transitions[0] = new Transition_0();
}

COMMS_READY::~COMMS_READY()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void COMMS_READY::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_COMMS_READY_VarRefs.mm"
#	include "State_COMMS_READY_OnEntry.mm"
}

void COMMS_READY::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_COMMS_READY_VarRefs.mm"
#	include "State_COMMS_READY_OnExit.mm"
}

void COMMS_READY::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_COMMS_READY_VarRefs.mm"
#	include "State_COMMS_READY_Internal.mm"
}

bool COMMS_READY::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_COMMS_READY_VarRefs.mm"

	return
	(
#			include "State_COMMS_READY_Transition_0.expr"
	);
}


