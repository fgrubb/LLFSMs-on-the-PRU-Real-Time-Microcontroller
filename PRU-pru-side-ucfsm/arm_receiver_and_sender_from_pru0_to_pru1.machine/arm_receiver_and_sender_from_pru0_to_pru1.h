//
//arm_receiver_and_sender_from_pru0_to_pru1.h
//
//Automatically created through MiEditCLFSM -- do not change manually!
//
#ifndef __clfsm__arm_receiver_and_sender_from_pru0_to_pru1__
#define __clfsm__arm_receiver_and_sender_from_pru0_to_pru1__

#include "CLMachine.h"

namespace FSM
{
	class CLState;

	namespace CLM
	{
		class arm_receiver_and_sender_from_pru0_to_pru1: public CLMachine
		{
			CLState *_states[7];
			public:
			arm_receiver_and_sender_from_pru0_to_pru1(int mid  = 0, const char *name = "arm_receiver_and_sender_from_pru0_to_pru1");
			virtual ~arm_receiver_and_sender_from_pru0_to_pru1();
			virtual CLState * const * states() const { return _states; }
			virtual int numberOfStates() const { return 7; }
#			include "arm_receiver_and_sender_from_pru0_to_pru1_Variables.h"
		};
	}
}

extern "C"
{
	FSM::CLM::arm_receiver_and_sender_from_pru0_to_pru1 *CLM_Create_arm_receiver_and_sender_from_pru0_to_pru1(int mid, const char *name);
}

#endif // defined(__gufsm__arm_receiver_and_sender_from_pru0_to_pru1__)
