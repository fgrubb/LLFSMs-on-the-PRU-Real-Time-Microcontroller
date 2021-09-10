//
//Drawing_arm_receiver_and_sender_from_pru0_to_pru1.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__Drawing_arm_receiver_and_sender_from_pru0_to_pru1__
#define __clfsm__Drawing_arm_receiver_and_sender_from_pru0_to_pru1__

#include "CLMachine.h"

namespace FSM
{
	class CLState;

	namespace CLM
	{
		class Drawing_arm_receiver_and_sender_from_pru0_to_pru1: public CLMachine
		{
			CLState *_states[7];
			public:
			Drawing_arm_receiver_and_sender_from_pru0_to_pru1(int mid  = 0, const char *name = "Drawing_arm_receiver_and_sender_from_pru0_to_pru1");
			virtual ~Drawing_arm_receiver_and_sender_from_pru0_to_pru1();
			virtual CLState * const * states() const { return _states; }
			virtual int numberOfStates() const { return 7; }
#			include "Drawing_arm_receiver_and_sender_from_pru0_to_pru1_Variables.h"
		};
	}
}

extern "C"
{
	FSM::CLM::Drawing_arm_receiver_and_sender_from_pru0_to_pru1 *CLM_Create_Drawing_arm_receiver_and_sender_from_pru0_to_pru1(int mid, const char *name);
}

#endif // defined(__gufsm__Drawing_arm_receiver_and_sender_from_pru0_to_pru1__)
