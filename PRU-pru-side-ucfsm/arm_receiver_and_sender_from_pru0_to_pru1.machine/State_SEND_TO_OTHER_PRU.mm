//
//State_SEND_TO_OTHER_PRU.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_receiver_and_sender_from_pru0_to_pru1_Includes.h"
#include "arm_receiver_and_sender_from_pru0_to_pru1.h"

#include "State_SEND_TO_OTHER_PRU.h"
#include "State_SEND_TO_OTHER_PRU_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_receiver_and_sender_from_pru0_to_pru1;
using namespace State;

SEND_TO_OTHER_PRU::SEND_TO_OTHER_PRU(const char *name):CLState(name, *new SEND_TO_OTHER_PRU::OnEntry,*new SEND_TO_OTHER_PRU::OnExit, *new SEND_TO_OTHER_PRU::Internal)
{
	_transitions[0] = new Transition_0();
}

SEND_TO_OTHER_PRU::~SEND_TO_OTHER_PRU()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void SEND_TO_OTHER_PRU::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_OnEntry.mm"
}

void SEND_TO_OTHER_PRU::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_OnExit.mm"
}

void SEND_TO_OTHER_PRU::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_Internal.mm"
}

bool SEND_TO_OTHER_PRU::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_receiver_and_sender_from_pru0_to_pru1_VarRefs.mm"
#	include "State_SEND_TO_OTHER_PRU_VarRefs.mm"

	return
	(
#			include "State_SEND_TO_OTHER_PRU_Transition_0.expr"
	);
}


