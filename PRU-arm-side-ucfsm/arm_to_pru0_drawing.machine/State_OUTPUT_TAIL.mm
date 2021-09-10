//
// State_OUTPUT_TAIL.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_OUTPUT_TAIL.h"

#include "State_OUTPUT_TAIL_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

OUTPUT_TAIL::OUTPUT_TAIL(const char *name): CLState(name, *new OUTPUT_TAIL::OnEntry, *new OUTPUT_TAIL::OnExit, *new OUTPUT_TAIL::Internal, NULLPTR, new OUTPUT_TAIL::OnSuspend, new OUTPUT_TAIL::OnResume)
{
}

OUTPUT_TAIL::~OUTPUT_TAIL()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

}

void OUTPUT_TAIL::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_OnEntry.mm"
}

void OUTPUT_TAIL::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_OnExit.mm"
}

void OUTPUT_TAIL::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_Internal.mm"
}

void OUTPUT_TAIL::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_OnSuspend.mm"
}

void OUTPUT_TAIL::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_TAIL_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_FuncRefs.mm"
#	include "State_OUTPUT_TAIL_OnResume.mm"
}
