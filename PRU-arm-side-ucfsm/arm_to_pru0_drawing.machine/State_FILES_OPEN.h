//
// State_FILES_OPEN.h
//
// Automatically created through MiCASE -- do not change manually!
//
#ifndef clfsm_arm_to_pru0_drawing_State_FILES_OPEN_h
#define clfsm_arm_to_pru0_drawing_State_FILES_OPEN_h

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
            class FILES_OPEN: public CLState
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
                    Transition_0(int toState = 4): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                class Transition_1: public CLTransition
                {
                public:
                    Transition_1(int toState = 6): CLTransition(toState) {}

                    virtual bool check(CLMachine *, CLState *) const;
                };

                CLTransition *_transitions[2];

                public:
                    FILES_OPEN(const char *name = "FILES_OPEN");
                    virtual ~FILES_OPEN();

                    virtual CLTransition * const *transitions() const { return _transitions; }
                    virtual int numberOfTransitions() const { return 2; }

#                   include "State_FILES_OPEN_Variables.h"
#                   include "State_FILES_OPEN_Methods.h"
            };
        }
      }
    }
}

#endif
