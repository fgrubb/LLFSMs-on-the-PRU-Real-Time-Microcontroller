//
//State_CHECK_IRQ_FROM_PRU0.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__pru1_receiver_from_pru0_back_to_arm_State_CHECK_IRQ_FROM_PRU0_h__
#define __clfsm__pru1_receiver_from_pru0_back_to_arm_State_CHECK_IRQ_FROM_PRU0_h__

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
	namespace CLM
	{
		namespace FSMpru1_receiver_from_pru0_back_to_arm
		{
			namespace State
			{
				class CHECK_IRQ_FROM_PRU0: public CLState
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
						Transition_0(int toState = 4): CLTransition(toState) {}

						virtual bool check(CLMachine *, CLState *) const;
					};


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[1];
				public:
					CHECK_IRQ_FROM_PRU0(const char *name = "CHECK_IRQ_FROM_PRU0");
					virtual ~CHECK_IRQ_FROM_PRU0();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 1; }

#					include "State_CHECK_IRQ_FROM_PRU0_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__pru1_receiver_from_pru0_back_to_arm_State_CHECK_IRQ_FROM_PRU0__)
