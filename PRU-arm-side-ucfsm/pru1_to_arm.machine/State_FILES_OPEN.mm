//
//State_FILES_OPEN.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_to_arm_Includes.h"
#include "pru1_to_arm.h"

#include "State_FILES_OPEN.h"
#include "State_FILES_OPEN_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_to_arm;
using namespace State;

FILES_OPEN::FILES_OPEN(const char *name):CLState(name, *new FILES_OPEN::OnEntry,*new FILES_OPEN::OnExit, *new FILES_OPEN::Internal)
{
	_transitions[0] = new Transition_0();	_transitions[1] = new Transition_1();
}

FILES_OPEN::~FILES_OPEN()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void FILES_OPEN::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "State_FILES_OPEN_OnEntry.mm"
}

void FILES_OPEN::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "State_FILES_OPEN_OnExit.mm"
}

void FILES_OPEN::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "State_FILES_OPEN_Internal.mm"
}

bool FILES_OPEN::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"

	return
	(
#			include "State_FILES_OPEN_Transition_0.expr"
	);
}
bool FILES_OPEN::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"

	return
	(
#			include "State_FILES_OPEN_Transition_1.expr"
	);
}


