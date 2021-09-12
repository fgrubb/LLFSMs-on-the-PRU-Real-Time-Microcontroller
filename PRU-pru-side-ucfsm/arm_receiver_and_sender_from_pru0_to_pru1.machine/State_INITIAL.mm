//
//State_INITIAL.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_receiver_and_sender_from_pru0_to_pru1_Includes.h"
#include "arm_receiver_and_sender_from_pru0_to_pru1.h"

#include "State_INITIAL.h"
#include "State_INITIAL_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_receiver_and_sender_from_pru0_to_pru1;
using namespace State;

INITIAL::INITIAL(const char *name):CLState(name, *new INITIAL::OnEntry,*new INITIAL::OnExit, *new INITIAL::Internal)
{
	_transitions[0] = new Transition_0();
}

INITIAL::~INITIAL()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void INITIAL::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "State_INITIAL_OnEntry.mm"
}

void INITIAL::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "State_INITIAL_OnExit.mm"
}

void INITIAL::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "State_INITIAL_Internal.mm"
}

bool INITIAL::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"

	return
	(
#			include "State_INITIAL_Transition_0.expr"
	);
}


