//
// State_INCREMENT.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_INCREMENT.h"

#include "State_INCREMENT_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

INCREMENT::INCREMENT(const char *name): CLState(name, *new INCREMENT::OnEntry, *new INCREMENT::OnExit, *new INCREMENT::Internal, NULLPTR, new INCREMENT::OnSuspend, new INCREMENT::OnResume)
{
	_transitions[0] = new Transition_0();
	_transitions[1] = new Transition_1();
	_transitions[2] = new Transition_2();
}

INCREMENT::~INCREMENT()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

	delete _transitions[0];
	delete _transitions[1];
	delete _transitions[2];
}

void INCREMENT::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"
#	include "State_INCREMENT_OnEntry.mm"
}

void INCREMENT::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"
#	include "State_INCREMENT_OnExit.mm"
}

void INCREMENT::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"
#	include "State_INCREMENT_Internal.mm"
}

void INCREMENT::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"
#	include "State_INCREMENT_OnSuspend.mm"
}

void INCREMENT::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"
#	include "State_INCREMENT_OnResume.mm"
}

bool INCREMENT::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"

	return
	(
#		include "State_INCREMENT_Transition_0.expr"
	);
}

bool INCREMENT::Transition_1::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"

	return
	(
#		include "State_INCREMENT_Transition_1.expr"
	);
}

bool INCREMENT::Transition_2::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_INCREMENT_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_INCREMENT_FuncRefs.mm"

	return
	(
#		include "State_INCREMENT_Transition_2.expr"
	);
}
