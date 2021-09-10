//
// State_COPY_CHAR.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_arm_to_pru0_drawing_State_COPY_CHAR_h
#define clfsm_arm_to_pru0_drawing_State_COPY_CHAR_h

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
            class COPY_CHAR: public CLState
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
                    Transition_0(int toState = 7): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[1];

                public:
                    COPY_CHAR(const char *name = "COPY_CHAR");
                    virtual ~COPY_CHAR();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 1; }

#                   include "State_COPY_CHAR_Variables.h"
#                   include "State_COPY_CHAR_Methods.h"
            };
        }
      }
    }
}

#endif
