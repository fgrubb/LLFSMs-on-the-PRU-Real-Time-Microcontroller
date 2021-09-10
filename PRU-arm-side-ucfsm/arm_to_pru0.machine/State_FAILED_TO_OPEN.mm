//
//State_FAILED_TO_OPEN.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_to_pru0_Includes.h"
#include "arm_to_pru0.h"

#include "State_FAILED_TO_OPEN.h"
#include "State_FAILED_TO_OPEN_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0;
using namespace State;

FAILED_TO_OPEN::FAILED_TO_OPEN(const char *name):CLState(name, *new FAILED_TO_OPEN::OnEntry,*new FAILED_TO_OPEN::OnExit, *new FAILED_TO_OPEN::Internal)
{

}

FAILED_TO_OPEN::~FAILED_TO_OPEN()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void FAILED_TO_OPEN::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_OnEntry.mm"
}

void FAILED_TO_OPEN::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_OnExit.mm"
}

void FAILED_TO_OPEN::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_VarRefs.mm"
#	include "State_FAILED_TO_OPEN_Internal.mm"
}



