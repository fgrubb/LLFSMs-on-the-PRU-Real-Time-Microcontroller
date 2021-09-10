//
//State_COPY_CHAR.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_to_pru0_Includes.h"
#include "arm_to_pru0.h"

#include "State_COPY_CHAR.h"
#include "State_COPY_CHAR_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0;
using namespace State;

COPY_CHAR::COPY_CHAR(const char *name):CLState(name, *new COPY_CHAR::OnEntry,*new COPY_CHAR::OnExit, *new COPY_CHAR::Internal)
{
	_transitions[0] = new Transition_0();
}

COPY_CHAR::~COPY_CHAR()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void COPY_CHAR::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "State_COPY_CHAR_OnEntry.mm"
}

void COPY_CHAR::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "State_COPY_CHAR_OnExit.mm"
}

void COPY_CHAR::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"
#	include "State_COPY_CHAR_Internal.mm"
}

bool COPY_CHAR::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_COPY_CHAR_VarRefs.mm"

	return
	(
#			include "State_COPY_CHAR_Transition_0.expr"
	);
}


