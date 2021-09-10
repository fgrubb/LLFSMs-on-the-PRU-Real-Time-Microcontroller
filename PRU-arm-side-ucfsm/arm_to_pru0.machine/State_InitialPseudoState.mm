//
//State_InitialPseudoState.mm
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#include "arm_to_pru0_Includes.h"
#include "arm_to_pru0.h"

#include "State_InitialPseudoState.h"
#include "State_InitialPseudoState_Includes.h"

using namespace FSM;
using namespace CLM;
using namespace FSMarm_to_pru0;
using namespace State;

InitialPseudoState::InitialPseudoState(const char *name):CLState(name, *new InitialPseudoState::OnEntry,*new InitialPseudoState::OnExit, *new InitialPseudoState::Internal)
{
	_transitions[0] = new Transition_0();
}

InitialPseudoState::~InitialPseudoState()
{
	delete &onEntryAction();
	delete &onExitAction();
	delete &internalAction();

}

void InitialPseudoState::OnEntry::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_InitialPseudoState_VarRefs.mm"
#	include "State_InitialPseudoState_OnEntry.mm"
}

void InitialPseudoState::OnExit::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_InitialPseudoState_VarRefs.mm"
#	include "State_InitialPseudoState_OnExit.mm"
}

void InitialPseudoState::Internal::perform(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_InitialPseudoState_VarRefs.mm"
#	include "State_InitialPseudoState_Internal.mm"
}

bool InitialPseudoState::Transition_0::check(CLMachine *_machine, CLState *_state) const
{
#	include "arm_to_pru0_VarRefs.mm"
#	include "State_InitialPseudoState_VarRefs.mm"

	return
	(
#			include "State_InitialPseudoState_Transition_0.expr"
	);
}


