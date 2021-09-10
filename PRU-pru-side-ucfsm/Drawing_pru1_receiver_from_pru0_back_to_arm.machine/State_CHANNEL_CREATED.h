//
//State_CHANNEL_CREATED.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__Drawing_pru1_receiver_from_pru0_back_to_arm_State_CHANNEL_CREATED_h__
#define __clfsm__Drawing_pru1_receiver_from_pru0_back_to_arm_State_CHANNEL_CREATED_h__

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
	namespace CLM
	{
		namespace FSMDrawing_pru1_receiver_from_pru0_back_to_arm
		{
			namespace State
			{
				class CHANNEL_CREATED: public CLState
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
						Transition_0(int toState = 3): CLTransition(toState) {}

						virtual bool check(CLMachine *, CLState *) const;
					};


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[1];
				public:
					CHANNEL_CREATED(const char *name = "CHANNEL_CREATED");
					virtual ~CHANNEL_CREATED();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 1; }

#					include "State_CHANNEL_CREATED_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__Drawing_pru1_receiver_from_pru0_back_to_arm_State_CHANNEL_CREATED__)
