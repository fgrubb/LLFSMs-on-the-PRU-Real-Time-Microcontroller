//
//State_ARM_KICKED_US.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "pru1_receiver_from_pru0_back_to_arm.h"

#include "State_ARM_KICKED_US.h"
#include "State_ARM_KICKED_US_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_receiver_from_pru0_back_to_arm;
using namespace State;

ARM_KICKED_US::ARM_KICKED_US(const char *name):CLState(name, *new ARM_KICKED_US::OnEntry,*new ARM_KICKED_US::OnExit, *new ARM_KICKED_US::Internal)
{
	_transitions[0] = new Transition_0();
}

ARM_KICKED_US::~ARM_KICKED_US()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void ARM_KICKED_US::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_ARM_KICKED_US_VarRefs.mm"
#	include "State_ARM_KICKED_US_OnEntry.mm"
}

void ARM_KICKED_US::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_ARM_KICKED_US_VarRefs.mm"
#	include "State_ARM_KICKED_US_OnExit.mm"
}

void ARM_KICKED_US::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_ARM_KICKED_US_VarRefs.mm"
#	include "State_ARM_KICKED_US_Internal.mm"
}

bool ARM_KICKED_US::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_ARM_KICKED_US_VarRefs.mm"

	return
	(
#			include "State_ARM_KICKED_US_Transition_0.expr"
	);
}


