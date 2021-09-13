//
//State_OUTPUT_DATA.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_to_arm_Includes.h"
#include "pru1_to_arm.h"

#include "State_OUTPUT_DATA.h"
#include "State_OUTPUT_DATA_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_to_arm;
using namespace State;

OUTPUT_DATA::OUTPUT_DATA(const char *name):CLState(name, *new OUTPUT_DATA::OnEntry,*new OUTPUT_DATA::OnExit, *new OUTPUT_DATA::Internal)
{
	_transitions[0] = new Transition_0();	_transitions[1] = new Transition_1();
}

OUTPUT_DATA::~OUTPUT_DATA()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void OUTPUT_DATA::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_OUTPUT_DATA_VarRefs.mm"
#	include "State_OUTPUT_DATA_OnEntry.mm"
}

void OUTPUT_DATA::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_OUTPUT_DATA_VarRefs.mm"
#	include "State_OUTPUT_DATA_OnExit.mm"
}

void OUTPUT_DATA::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_OUTPUT_DATA_VarRefs.mm"
#	include "State_OUTPUT_DATA_Internal.mm"
}

bool OUTPUT_DATA::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_OUTPUT_DATA_VarRefs.mm"

	return
	(
#			include "State_OUTPUT_DATA_Transition_0.expr"
	);
}
bool OUTPUT_DATA::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_OUTPUT_DATA_VarRefs.mm"

	return
	(
#			include "State_OUTPUT_DATA_Transition_1.expr"
	);
}


