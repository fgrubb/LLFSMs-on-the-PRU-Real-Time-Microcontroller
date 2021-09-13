//
//State_FAILED_TO_OPEN.h
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#ifndef __clfsm__pru1_to_arm_State_FAILED_TO_OPEN_h__
#define __clfsm__pru1_to_arm_State_FAILED_TO_OPEN_h__

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
	namespace CLM
	{
		namespace FSMpru1_to_arm
		{
			namespace State
			{
				class FAILED_TO_OPEN: public CLState
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wzero-length-array"
				CLTransition *_transitions[0];
				public:
					FAILED_TO_OPEN(const char *name = "FAILED_TO_OPEN");
					virtual ~FAILED_TO_OPEN();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 0; }

#					include "State_FAILED_TO_OPEN_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__pru1_to_arm_State_FAILED_TO_OPEN__)
