//
//State_BLOCK_READ.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_to_arm_Includes.h"
#include "pru1_to_arm.h"

#include "State_BLOCK_READ.h"
#include "State_BLOCK_READ_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_to_arm;
using namespace State;

BLOCK_READ::BLOCK_READ(const char *name):CLState(name, *new BLOCK_READ::OnEntry,*new BLOCK_READ::OnExit, *new BLOCK_READ::Internal)
{
	_transitions[0] = new Transition_0();	_transitions[1] = new Transition_1();
}

BLOCK_READ::~BLOCK_READ()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void BLOCK_READ::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_BLOCK_READ_VarRefs.mm"
#	include "State_BLOCK_READ_OnEntry.mm"
}

void BLOCK_READ::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_BLOCK_READ_VarRefs.mm"
#	include "State_BLOCK_READ_OnExit.mm"
}

void BLOCK_READ::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_BLOCK_READ_VarRefs.mm"
#	include "State_BLOCK_READ_Internal.mm"
}

bool BLOCK_READ::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_BLOCK_READ_VarRefs.mm"

	return
	(
#			include "State_BLOCK_READ_Transition_0.expr"
	);
}
bool BLOCK_READ::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_BLOCK_READ_VarRefs.mm"

	return
	(
#			include "State_BLOCK_READ_Transition_1.expr"
	);
}


