//
//arm_to_pru0.h
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#ifndef __clfsm__arm_to_pru0__
#define __clfsm__arm_to_pru0__

#include "CLMachine.h"

namespace FSM
{
	class CLState;

	namespace CLM
	{
		class arm_to_pru0: public CLMachine
		{
			CLState *_states[8];
			public:
			arm_to_pru0(int mid  = 0, const char *name = "arm_to_pru0");
			virtual ~arm_to_pru0();
			virtual CLState * const * states() const { return _states; }
			virtual int numberOfStates() const { return 8; }
#			include "arm_to_pru0_Variables.h"
		};
	}
}

extern "C"
{
	FSM::CLM::arm_to_pru0 *CLM_Create_arm_to_pru0(int mid, const char *name);
}

#endif // defined(__gufsm__arm_to_pru0__)
