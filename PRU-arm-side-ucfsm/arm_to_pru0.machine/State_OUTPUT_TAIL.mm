//
//State_OUTPUT_TAIL.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_to_pru0_Includes.h"
#include "arm_to_pru0.h"

#include "State_OUTPUT_TAIL.h"
#include "State_OUTPUT_TAIL_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0;
using namespace State;

OUTPUT_TAIL::OUTPUT_TAIL(const char *name):CLState(name, *new OUTPUT_TAIL::OnEntry,*new OUTPUT_TAIL::OnExit, *new OUTPUT_TAIL::Internal)
{

}

OUTPUT_TAIL::~OUTPUT_TAIL()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void OUTPUT_TAIL::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "State_OUTPUT_TAIL_OnEntry.mm"
}

void OUTPUT_TAIL::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "State_OUTPUT_TAIL_OnExit.mm"
}

void OUTPUT_TAIL::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "State_OUTPUT_TAIL_Internal.mm"
}



