//
//State_OUTPUT_BLOCK.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_to_pru0_Includes.h"
#include "arm_to_pru0.h"

#include "State_OUTPUT_BLOCK.h"
#include "State_OUTPUT_BLOCK_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0;
using namespace State;

OUTPUT_BLOCK::OUTPUT_BLOCK(const char *name):CLState(name, *new OUTPUT_BLOCK::OnEntry,*new OUTPUT_BLOCK::OnExit, *new OUTPUT_BLOCK::Internal)
{
	_transitions[0] = new Transition_0();
}

OUTPUT_BLOCK::~OUTPUT_BLOCK()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void OUTPUT_BLOCK::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_OnEntry.mm"
}

void OUTPUT_BLOCK::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_OnExit.mm"
}

void OUTPUT_BLOCK::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_Internal.mm"
}

bool OUTPUT_BLOCK::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"

	return
	(
#			include "State_OUTPUT_BLOCK_Transition_0.expr"
	);
}


