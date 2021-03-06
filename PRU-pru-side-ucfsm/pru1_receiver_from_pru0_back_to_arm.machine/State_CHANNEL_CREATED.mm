//
//State_CHANNEL_CREATED.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "pru1_receiver_from_pru0_back_to_arm.h"

#include "State_CHANNEL_CREATED.h"
#include "State_CHANNEL_CREATED_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_receiver_from_pru0_back_to_arm;
using namespace State;

CHANNEL_CREATED::CHANNEL_CREATED(const char *name):CLState(name, *new CHANNEL_CREATED::OnEntry,*new CHANNEL_CREATED::OnExit, *new CHANNEL_CREATED::Internal)
{
	_transitions[0] = new Transition_0();
}

CHANNEL_CREATED::~CHANNEL_CREATED()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void CHANNEL_CREATED::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHANNEL_CREATED_VarRefs.mm"
#	include "State_CHANNEL_CREATED_OnEntry.mm"
}

void CHANNEL_CREATED::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHANNEL_CREATED_VarRefs.mm"
#	include "State_CHANNEL_CREATED_OnExit.mm"
}

void CHANNEL_CREATED::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHANNEL_CREATED_VarRefs.mm"
#	include "State_CHANNEL_CREATED_Internal.mm"
}

bool CHANNEL_CREATED::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHANNEL_CREATED_VarRefs.mm"

	return
	(
#			include "State_CHANNEL_CREATED_Transition_0.expr"
	);
}


