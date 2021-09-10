//
// State_OUTPUT_TAIL.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_arm_to_pru0_drawing_State_OUTPUT_TAIL_h
#define clfsm_arm_to_pru0_drawing_State_OUTPUT_TAIL_h

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"

#include "CLState.h"
#include "CLAction.h"
#include "CLTransition.h"

namespace FSM
{
    namespace CLM
    {
      namespace FSMarm_to_pru0_drawing
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

                class OnSuspend: public CLAction
                {
                    virtual void perform(CLMachine *, CLState *) const;
                };

                class OnResume: public CLAction
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

#                   include "State_OUTPUT_TAIL_Variables.h"
#                   include "State_OUTPUT_TAIL_Methods.h"
            };
        }
      }
    }
}

#endif
#pragma clang diagnostic pop
