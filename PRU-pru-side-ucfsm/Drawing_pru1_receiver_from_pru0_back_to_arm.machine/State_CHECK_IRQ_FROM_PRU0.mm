//
//State_CHECK_IRQ_FROM_PRU0.mm
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#include "Drawing_pru1_receiver_from_pru0_back_to_arm_Includes.h"
#include "Drawing_pru1_receiver_from_pru0_back_to_arm.h"

#include "State_CHECK_IRQ_FROM_PRU0.h"
#include "State_CHECK_IRQ_FROM_PRU0_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMDrawing_pru1_receiver_from_pru0_back_to_arm;
using namespace State;

CHECK_IRQ_FROM_PRU0::CHECK_IRQ_FROM_PRU0(const char *name):CLState(name, *new CHECK_IRQ_FROM_PRU0::OnEntry,*new CHECK_IRQ_FROM_PRU0::OnExit, *new CHECK_IRQ_FROM_PRU0::Internal)
{
	_transitions[0] = new Transition_0();
}

CHECK_IRQ_FROM_PRU0::~CHECK_IRQ_FROM_PRU0()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void CHECK_IRQ_FROM_PRU0::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_OnEntry.mm"
}

void CHECK_IRQ_FROM_PRU0::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_OnExit.mm"
}

void CHECK_IRQ_FROM_PRU0::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_Internal.mm"
}

bool CHECK_IRQ_FROM_PRU0::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "Drawing_pru1_receiver_from_pru0_back_to_arm_VarRefs.mm"
#	include "State_CHECK_IRQ_FROM_PRU0_VarRefs.mm"

	return
	(
#			include "State_CHECK_IRQ_FROM_PRU0_Transition_0.expr"
	);
}


