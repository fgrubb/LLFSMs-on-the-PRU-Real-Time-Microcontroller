//
//State_OUTPUT_TAIL.h
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#ifndef __clfsm__arm_to_pru0_State_OUTPUT_TAIL_h__
#define __clfsm__arm_to_pru0_State_OUTPUT_TAIL_h__

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
	namespace CLM
	{
		namespace FSMarm_to_pru0
		{
			namespace State
			{
				class OUTPUT_TAIL: public CLState
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
					OUTPUT_TAIL(const char *name = "OUTPUT_TAIL");
					virtual ~OUTPUT_TAIL();

					virtual CLTransition * const *transitions() const { return _transitions; }
					virtual int numberOfTransitions() const { return 0; }

#					include "State_OUTPUT_TAIL_Variables.h"
#pragma clang diagnostic pop
				};
			}
		}
	}
}
#endif // defined(__gufsm__arm_to_pru0_State_OUTPUT_TAIL__)
