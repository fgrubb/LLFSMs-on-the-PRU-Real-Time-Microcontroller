//
// State_COPY_CHAR.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_COPY_CHAR.h"

#include "State_COPY_CHAR_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

COPY_CHAR::COPY_CHAR(const char *name): CLState(name, *new COPY_CHAR::OnEntry, *new COPY_CHAR::OnExit, *new COPY_CHAR::Internal, NULLPTR, new COPY_CHAR::OnSuspend, new COPY_CHAR::OnResume)
{
	_transitions[0] = new Transition_0();
}

COPY_CHAR::~COPY_CHAR()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

	delete _transitions[0];
}

void COPY_CHAR::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_COPY_CHAR_FuncRefs.mm"
#	include "State_COPY_CHAR_OnEntry.mm"
}

void COPY_CHAR::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_COPY_CHAR_FuncRefs.mm"
#	include "State_COPY_CHAR_OnExit.mm"
}

void COPY_CHAR::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_COPY_CHAR_FuncRefs.mm"
#	include "State_COPY_CHAR_Internal.mm"
}

void COPY_CHAR::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_COPY_CHAR_FuncRefs.mm"
#	include "State_COPY_CHAR_OnSuspend.mm"
}

void COPY_CHAR::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_COPY_CHAR_FuncRefs.mm"
#	include "State_COPY_CHAR_OnResume.mm"
}

bool COPY_CHAR::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_COPY_CHAR_FuncRefs.mm"

	return
	(
#		include "State_COPY_CHAR_Transition_0.expr"
	);
}
