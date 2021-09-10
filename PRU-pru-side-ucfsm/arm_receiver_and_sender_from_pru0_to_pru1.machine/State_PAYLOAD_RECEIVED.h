//
//State_PAYLOAD_RECEIVED.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__arm_receiver_and_sender_from_pru0_to_pru1_State_PAYLOAD_RECEIVED_h__
#define __clfsm__arm_receiver_and_sender_from_pru0_to_pru1_State_PAYLOAD_RECEIVED_h__

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
				class PAYLOAD_RECEIVED: public CLState
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
						Transition_0(int toState = 6): CLTransition(toState) {}

						virtual bool check(CLMachine *, CLState *) const;
					};


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[1];
				public:
					PAYLOAD_RECEIVED(const char *name = "PAYLOAD_RECEIVED");
					virtual ~PAYLOAD_RECEIVED();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 1; }

#					include "State_PAYLOAD_RECEIVED_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__arm_receiver_and_sender_from_pru0_to_pru1_State_PAYLOAD_RECEIVED__)
