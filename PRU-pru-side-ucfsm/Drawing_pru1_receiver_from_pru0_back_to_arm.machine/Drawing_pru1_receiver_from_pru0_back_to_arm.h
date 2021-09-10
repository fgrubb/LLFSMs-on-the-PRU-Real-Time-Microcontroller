//
//Drawing_pru1_receiver_from_pru0_back_to_arm.h
//
//Automatically created through MiEditLLFSM -- do not change manually!
//
#ifndef __clfsm__Drawing_pru1_receiver_from_pru0_back_to_arm__
#define __clfsm__Drawing_pru1_receiver_from_pru0_back_to_arm__

#include "CLMachine.h"

namespace FSM
{
	class CLState;

	namespace CLM
	{
		class Drawing_pru1_receiver_from_pru0_back_to_arm: public CLMachine
		{
			CLState *_states[6];
			public:
			Drawing_pru1_receiver_from_pru0_back_to_arm(int mid  = 0, const char *name = "Drawing_pru1_receiver_from_pru0_back_to_arm");
			virtual ~Drawing_pru1_receiver_from_pru0_back_to_arm();
			virtual CLState * const * states() const { return _states; }
			virtual int numberOfStates() const { return 6; }
#			include "Drawing_pru1_receiver_from_pru0_back_to_arm_Variables.h"
		};
	}
}

extern "C"
{
	FSM::CLM::Drawing_pru1_receiver_from_pru0_back_to_arm *CLM_Create_Drawing_pru1_receiver_from_pru0_back_to_arm(int mid, const char *name);
}

#endif // defined(__gufsm__Drawing_pru1_receiver_from_pru0_back_to_arm__)
