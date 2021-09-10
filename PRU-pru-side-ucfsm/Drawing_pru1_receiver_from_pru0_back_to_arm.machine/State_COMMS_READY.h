//
//State_COMMS_READY.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__Drawing_pru1_receiver_from_pru0_back_to_arm_State_COMMS_READY_h__
#define __clfsm__Drawing_pru1_receiver_from_pru0_back_to_arm_State_COMMS_READY_h__

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
				class COMMS_READY: public CLState
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
					COMMS_READY(const char *name = "COMMS_READY");
					virtual ~COMMS_READY();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 1; }

#					include "State_COMMS_READY_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__Drawing_pru1_receiver_from_pru0_back_to_arm_State_COMMS_READY__)
