//
// State_FAILED_TO_OPEN.mm
//
// Automatically created through MiCASE -- do not change manually!
//
#include "arm_to_pru0_drawing_Includes.h"
#include "arm_to_pru0_drawing.h"
#include "State_FAILED_TO_OPEN.h"

#include "State_FAILED_TO_OPEN_Includes.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0_drawing;
using namespace State;

FAILED_TO_OPEN::FAILED_TO_OPEN(const char *name): CLState(name, *new FAILED_TO_OPEN::OnEntry, *new FAILED_TO_OPEN::OnExit, *new FAILED_TO_OPEN::Internal, NULLPTR, new FAILED_TO_OPEN::OnSuspend, new FAILED_TO_OPEN::OnResume)
{
}

FAILED_TO_OPEN::~FAILED_TO_OPEN()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();
	delete onSuspendAction();
	delete onResumeAction();

}

void FAILED_TO_OPEN::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_OnEntry.mm"
}

void FAILED_TO_OPEN::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_OnExit.mm"
}

void FAILED_TO_OPEN::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_Internal.mm"
}

void FAILED_TO_OPEN::OnSuspend::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_OnSuspend.mm"
}

void FAILED_TO_OPEN::OnResume::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_drawing_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "arm_to_pru0_drawing_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_FuncRefs.mm"
#	include "State_FAILED_TO_OPEN_OnResume.mm"
}
