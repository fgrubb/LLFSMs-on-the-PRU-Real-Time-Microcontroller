//
//State_RECEIVED_FROM_PRU1.h
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#ifndef __clfsm__pru1_receiver_from_pru0_back_to_arm_State_RECEIVED_FROM_PRU1_h__
#define __clfsm__pru1_receiver_from_pru0_back_to_arm_State_RECEIVED_FROM_PRU1_h__

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
				class RECEIVED_FROM_PRU1: public CLState
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
						Transition_0(int toState = 5): CLTransition(toState) {}

						virtual bool check(CLMachine *, CLState *) const;
					};


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[1];
				public:
					RECEIVED_FROM_PRU1(const char *name = "RECEIVED_FROM_PRU1");
					virtual ~RECEIVED_FROM_PRU1();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 1; }

#					include "State_RECEIVED_FROM_PRU1_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__pru1_receiver_from_pru0_back_to_arm_State_RECEIVED_FROM_PRU1__)
