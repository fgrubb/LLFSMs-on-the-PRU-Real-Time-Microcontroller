//
//State_RECEIVED_FROM_PRU1.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "pru1_receiver_from_pru0_back_to_arm.h"

#include "State_RECEIVED_FROM_PRU1.h"
#include "State_RECEIVED_FROM_PRU1_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_receiver_from_pru0_back_to_arm;
using namespace State;

RECEIVED_FROM_PRU1::RECEIVED_FROM_PRU1(const char *name):CLState(name, *new RECEIVED_FROM_PRU1::OnEntry,*new RECEIVED_FROM_PRU1::OnExit, *new RECEIVED_FROM_PRU1::Internal)
{
	_transitions[0] = new Transition_0();
}

RECEIVED_FROM_PRU1::~RECEIVED_FROM_PRU1()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void RECEIVED_FROM_PRU1::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_OnEntry.mm"
}

void RECEIVED_FROM_PRU1::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_OnExit.mm"
}

void RECEIVED_FROM_PRU1::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_Internal.mm"
}

bool RECEIVED_FROM_PRU1::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_RECEIVED_FROM_PRU1_VarRefs.mm"

	return
	(
#			include "State_RECEIVED_FROM_PRU1_Transition_0.expr"
	);
}


