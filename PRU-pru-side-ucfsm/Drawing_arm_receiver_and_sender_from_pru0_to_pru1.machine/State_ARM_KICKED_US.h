//
//State_ARM_KICKED_US.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__Drawing_arm_receiver_and_sender_from_pru0_to_pru1_State_ARM_KICKED_US_h__
#define __clfsm__Drawing_arm_receiver_and_sender_from_pru0_to_pru1_State_ARM_KICKED_US_h__

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
	namespace CLM
	{
		namespace FSMDrawing_arm_receiver_and_sender_from_pru0_to_pru1
		{
			namespace State
			{
				class ARM_KICKED_US: public CLState
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

					class Transition_1: public CLTransition
					{
						public:
						Transition_1(int toState = 3): CLTransition(toState) {}

						virtual bool check(CLMachine *, CLState *) const;
					};


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[2];
				public:
					ARM_KICKED_US(const char *name = "ARM_KICKED_US");
					virtual ~ARM_KICKED_US();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 2; }

#					include "State_ARM_KICKED_US_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__Drawing_arm_receiver_and_sender_from_pru0_to_pru1_State_ARM_KICKED_US__)
