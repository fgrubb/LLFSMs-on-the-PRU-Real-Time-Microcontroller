//
//State_SEND_TO_ARM.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "Drawing_pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "Drawing_pru1_receiver_from_pru0_back_to_arm.h"

#include "State_SEND_TO_ARM.h"
#include "State_SEND_TO_ARM_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMDrawing_pru1_receiver_from_pru0_back_to_arm;
using namespace State;

SEND_TO_ARM::SEND_TO_ARM(const char *name):CLState(name, *new SEND_TO_ARM::OnEntry,*new SEND_TO_ARM::OnExit, *new SEND_TO_ARM::Internal)
{
	_transitions[0] = new Transition_0();
}

SEND_TO_ARM::~SEND_TO_ARM()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void SEND_TO_ARM::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_SEND_TO_ARM_VarRefs.mm"
#	include "State_SEND_TO_ARM_OnEntry.mm"
}

void SEND_TO_ARM::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_SEND_TO_ARM_VarRefs.mm"
#	include "State_SEND_TO_ARM_OnExit.mm"
}

void SEND_TO_ARM::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_SEND_TO_ARM_VarRefs.mm"
#	include "State_SEND_TO_ARM_Internal.mm"
}

bool SEND_TO_ARM::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_SEND_TO_ARM_VarRefs.mm"

	return
	(
#			include "State_SEND_TO_ARM_Transition_0.expr"
	);
}


