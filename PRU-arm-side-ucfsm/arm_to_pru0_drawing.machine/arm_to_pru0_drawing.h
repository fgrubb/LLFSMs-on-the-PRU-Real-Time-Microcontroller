//
// arm_to_pru0_drawing.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_machine_arm_to_pru0_drawing_
#define clfsm_machine_arm_to_pru0_drawing_

#include "CLMachine.h"

namespace FSM
{
    class CLState;

    namespace CLM
    {
        class arm_to_pru0_drawing: public CLMachine
        {
            CLState *_states[8];
        public:
            arm_to_pru0_drawing(int mid  = 0, const char *name = "arm_to_pru0_drawing");
            virtual ~arm_to_pru0_drawing();
            virtual CLState * const * states() const { return _states; }
            virtual int numberOfStates() const { return 8; }
#           include "arm_to_pru0_drawing_Variables.h"
#           include "arm_to_pru0_drawing_Methods.h"
        };
    }
}

extern "C"
{
    FSM::CLM::arm_to_pru0_drawing *CLM_Create_arm_to_pru0_drawing(int mid, const char *name);
}

#endif // defined(clfsm_machine_arm_to_pru0_drawing_)
