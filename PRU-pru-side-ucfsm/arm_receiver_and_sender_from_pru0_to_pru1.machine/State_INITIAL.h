//
//State_INITIAL.h
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#ifndef __clfsm__arm_receiver_and_sender_from_pru0_to_pru1_State_INITIAL_h__
#define __clfsm__arm_receiver_and_sender_from_pru0_to_pru1_State_INITIAL_h__

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
	namespace CLM
	{
		namespace FSMarm_receiver_and_sender_from_pru0_to_pru1
		{
			namespace State
			{
				class INITIAL: public CLState
				{
					class OnEntry: public CLAction
					{
						virtual void perform(CLMachine *, CLState *) const;
					};
					class OnExit: public CLAction
					{
						virtual void perform(CLMachine *, CLState *) const;
					};
					class Internal: public CLAction
					{
						virtual void perform(CLMachine *, CLState *) const;
					};
					class Transition_0: public CLTransition
					{
						public:
						Transition_0(int toState = 2): CLTransition(toState) {}

						virtual bool check(CLMachine *, CLState *) const;
					};


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[1];
				public:
					INITIAL(const char *name = "INITIAL");
					virtual ~INITIAL();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 1; }

#					include "State_INITIAL_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__arm_receiver_and_sender_from_pru0_to_pru1_State_INITIAL__)
