//
//State_PAYLOAD_RECEIVED.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "arm_receiver_and_sender_from_pru0_to_pru1_Includes.h"
#include "arm_receiver_and_sender_from_pru0_to_pru1.h"

#include "State_PAYLOAD_RECEIVED.h"
#include "State_PAYLOAD_RECEIVED_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_receiver_and_sender_from_pru0_to_pru1;
using namespace State;

PAYLOAD_RECEIVED::PAYLOAD_RECEIVED(const char *name):CLState(name, *new PAYLOAD_RECEIVED::OnEntry,*new PAYLOAD_RECEIVED::OnExit, *new PAYLOAD_RECEIVED::Internal)
{
	_transitions[0] = new Transition_0();
}

PAYLOAD_RECEIVED::~PAYLOAD_RECEIVED()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void PAYLOAD_RECEIVED::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_OnEntry.mm"
}

void PAYLOAD_RECEIVED::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_OnExit.mm"
}

void PAYLOAD_RECEIVED::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_Internal.mm"
}

bool PAYLOAD_RECEIVED::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_PAYLOAD_RECEIVED_VarRefs.mm"

	return
	(
#			include "State_PAYLOAD_RECEIVED_Transition_0.expr"
	);
}


