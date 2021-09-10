//
// State_OUTPUT_BLOCK.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_arm_to_pru0_drawing_State_OUTPUT_BLOCK_h
#define clfsm_arm_to_pru0_drawing_State_OUTPUT_BLOCK_h

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
            class OUTPUT_BLOCK: public CLState
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

                class Transition_0: public CLTransition
                {
                public:
                    Transition_0(int toState = 2): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    OUTPUT_BLOCK(const char *name = "OUTPUT_BLOCK");
                    virtual ~OUTPUT_BLOCK();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_OUTPUT_BLOCK_Variables.h"
#                   include "State_OUTPUT_BLOCK_Methods.h"
            };
        }
      }
    }
}

#endif
