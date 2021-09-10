//
// State_FILES_OPEN.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_FILES_OPEN.h"

#include "State_FILES_OPEN_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

FILES_OPEN::FILES_OPEN(const char *name): CLState(name, *new FILES_OPEN::OnEntry, *new FILES_OPEN::OnExit, *new FILES_OPEN::Internal, NULLPTR, new FILES_OPEN::OnSuspend, new FILES_OPEN::OnResume)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

FILES_OPEN::~FILES_OPEN()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

	delete _transitions[0];
	delete _transitions[1];
}

void FILES_OPEN::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"
#	include "State_FILES_OPEN_OnEntry.mm"
}

void FILES_OPEN::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"
#	include "State_FILES_OPEN_OnExit.mm"
}

void FILES_OPEN::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"
#	include "State_FILES_OPEN_Internal.mm"
}

void FILES_OPEN::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"
#	include "State_FILES_OPEN_OnSuspend.mm"
}

void FILES_OPEN::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"
#	include "State_FILES_OPEN_OnResume.mm"
}

bool FILES_OPEN::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"

	return
	(
#		include "State_FILES_OPEN_Transition_0.expr"
	);
}

bool FILES_OPEN::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FILES_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FILES_OPEN_FuncRefs.mm"

	return
	(
#		include "State_FILES_OPEN_Transition_1.expr"
	);
}
