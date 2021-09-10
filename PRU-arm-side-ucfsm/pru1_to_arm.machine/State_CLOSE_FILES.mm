//
//State_CLOSE_FILES.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "pru1_to_arm_Includes.h"
#include "pru1_to_arm.h"

#include "State_CLOSE_FILES.h"
#include "State_CLOSE_FILES_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMpru1_to_arm;
using namespace State;

CLOSE_FILES::CLOSE_FILES(const char *name):CLState(name, *new CLOSE_FILES::OnEntry,*new CLOSE_FILES::OnExit, *new CLOSE_FILES::Internal)
{

}

CLOSE_FILES::~CLOSE_FILES()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void CLOSE_FILES::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_CLOSE_FILES_VarRefs.mm"
#	include "State_CLOSE_FILES_OnEntry.mm"
}

void CLOSE_FILES::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_CLOSE_FILES_VarRefs.mm"
#	include "State_CLOSE_FILES_OnExit.mm"
}

void CLOSE_FILES::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "pru1_to_arm_VarRefs.mm"
#	include "State_CLOSE_FILES_VarRefs.mm"
#	include "State_CLOSE_FILES_Internal.mm"
}



