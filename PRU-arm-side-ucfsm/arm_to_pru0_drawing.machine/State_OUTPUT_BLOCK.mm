//
// State_OUTPUT_BLOCK.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_OUTPUT_BLOCK.h"

#include "State_OUTPUT_BLOCK_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

OUTPUT_BLOCK::OUTPUT_BLOCK(const char *name): CLState(name, *new OUTPUT_BLOCK::OnEntry, *new OUTPUT_BLOCK::OnExit, *new OUTPUT_BLOCK::Internal, NULLPTR, new OUTPUT_BLOCK::OnSuspend, new OUTPUT_BLOCK::OnResume)
{
	_transitions[0] = new Transition_0();
}

OUTPUT_BLOCK::~OUTPUT_BLOCK()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

	delete _transitions[0];
}

void OUTPUT_BLOCK::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_OnEntry.mm"
}

void OUTPUT_BLOCK::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_OnExit.mm"
}

void OUTPUT_BLOCK::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_Internal.mm"
}

void OUTPUT_BLOCK::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_OnSuspend.mm"
}

void OUTPUT_BLOCK::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_OnResume.mm"
}

bool OUTPUT_BLOCK::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_OUTPUT_BLOCK_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_OUTPUT_BLOCK_FuncRefs.mm"

	return
	(
#		include "State_OUTPUT_BLOCK_Transition_0.expr"
	);
}
