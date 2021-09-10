//
// State_INITIAL.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_INITIAL.h"

#include "State_INITIAL_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

INITIAL::INITIAL(const char *name): CLState(name, *new INITIAL::OnEntry, *new INITIAL::OnExit, *new INITIAL::Internal, NULLPTR, new INITIAL::OnSuspend, new INITIAL::OnResume)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
}

INITIAL::~INITIAL()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

	delete _transitions[0];
	delete _transitions[1];
}

void INITIAL::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"
#	include "State_INITIAL_OnEntry.mm"
}

void INITIAL::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"
#	include "State_INITIAL_OnExit.mm"
}

void INITIAL::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"
#	include "State_INITIAL_Internal.mm"
}

void INITIAL::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"
#	include "State_INITIAL_OnSuspend.mm"
}

void INITIAL::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"
#	include "State_INITIAL_OnResume.mm"
}

bool INITIAL::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"

	return
	(
#		include "State_INITIAL_Transition_0.expr"
	);
}

bool INITIAL::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INITIAL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INITIAL_FuncRefs.mm"

	return
	(
#		include "State_INITIAL_Transition_1.expr"
	);
}
