/*
 * Written by Fisher Grubb for MPhil under Vladimir Estivill-Castro & Rene Hexel (MiPal Lab, Griffith University, Nathan, Brisbane Australia)
 *  
 * Part of PRU implementation library for ucFSM
 * 
 * Code to test different features of the PRU, focusing on IEP timer to measure & keep track of time, especially for the scheduler.
 * 
 * File: PRU-ucfsm-timer.c
 */

/* Todo:
 * Separate timer config fuctions such as for interrupts, resetting, clearing etc.
 * micros() should use high counter also, will unsigned long suffice?
 */

#include <stdint.h>
#include "PRU-ucfsm-general-defines.h"
#include "PRU-ucfsm-timer-lib.h"

unsigned long micros(){
        //Implementation to replace equivalent of Arduino version, such as in wiring.c
/*
    //The AI timer register is actually Low and High both of 32bits to make 64.  BB Black timer is 32 bits.
    unsigned long long IEP_Counter_Merged = CT_IEP.HIGH_COUNTER;
    
    //Lower 32 bits of variable should hold higher 32 bit timer register, shift it to the higher half
    IEP_Counter_Merged << 32;
    //Now add the lower timer to lower half:
    IEP_Counter_Merged += CT_IEP.LOW_COUNTER;
    
    if (IEP_Counter_Merged >= 200){
        return microseconds = IEP_Counter_Merged/200;
    }
    else{
        return = 0;
    }
    
*/
    unsigned long microseconds = CT_IEP.LOW_COUNTER;
    //Comparison and division value would be Delay_1uS (200) for 200MHz timer speed.
    //If timer count isn't 1, but is 10, then value would be 20 instead (200/10)
        
    if (microseconds >= 20){
        return microseconds/20;
    }
    else{
        return 0;
    }
} /* micros */
    
    
    
    /* This function generally shouldn't be used, was only orignally as a test for the PRU flag based interrupts.
     * 
     * Todo: LEDs flash, R31 vs only timer regs etc, global interrupts needed?
     */  
void check_timer_loop(void){
    int timer_not_triggered = 1;
    while(timer_not_triggered){
        
    if(CT_IEP.CMP_STS_bit.CMP_HIT == 0x1){
                    __R30 = (LED5 | LED7);
//                    __delay_cycles(100000000); // half-second/10 delay
                    __R30 = LED6;
//                    __delay_cycles(100000000); // half-second/10 delay
                    __R30 = 0x0000;
                    
                    
                    timer_not_triggered = 0;
                }
    }
}

//New IEP_timer_init function:
void IEP_timer_init(unsigned int timer_CMP0L, unsigned int timer_prescalar){
    /*
     * Timer initialisation function receives compare/match value,
     * and prescalar to slow clock down.  If both 0, then both disabled.
     */
    
        // Clear SYSCFG[STANDBY_INIT] to enable OCP master port
        CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
        
        /* Disable counter */
        CT_IEP.GLB_CFG_bit.CNT_ENABLE = 0;
        
        /* Reset Count register, later need to use both, currently only LOW */
        CT_IEP.LOW_COUNTER = 0x0;
        CT_IEP.HIGH_COUNTER = 0x0;
        
        /* Clear overflow status register */
        CT_IEP.GLB_STS_bit.CNT_OVF = 0x1;
        
        /* Clear compare status */
        CT_IEP.CMP_STS_bit.CMP_HIT = 0xFFFF;
        
        if(timer_CMP0L > 0){
            //timer_CMP0L more than 0 is for compare interrupt, should generally be recieved as 0.
            
            CT_IEP.CMP0_0 = timer_CMP0L;
            CT_IEP.CMP1_0 = 0;      //Timer compare high, currently set to 0, implement later when tested

            /* Disable compensation */
            CT_IEP.COMPEN_bit.COMPEN_CNT = 0x0;
                
            /* Enable CMP0 and reset on event */
            CT_IEP.CMP_CFG_bit.CMP0_RST_CNT_EN = 0x1;
            CT_IEP.CMP_CFG_bit.CMP_EN = 0x1;
            
            //Put further interrupt settings here if needed for timer compare,
            //or other features.  Basics are in TI IEP example.
        }
        else{
            /*Timer compare is disabled, so will count up the full 64 bits and overflow.
             */
            
            //Reset these compare match values in case were previously set
            CT_IEP.CMP0_0 = 0;
            CT_IEP.CMP1_0 = 0;
            
            /* Disable CMP0 and it's reset on event */
            CT_IEP.CMP_CFG_bit.CMP0_RST_CNT_EN = 0x0;
            CT_IEP.CMP_CFG_bit.CMP_EN = 0x0;
        }
        if(timer_prescalar > 0){
            /* timer_prescalar is to slow clock down from usual 200MHz
             */
            
            //Enable compensation counter mode
            CT_IEP.GLB_CFG_bit.CMP_INC = 1;
            
            // Disable fast compensation, off when using DEFAULT_INC or SLOW_COMPEN. On when need to temporarily speed up the IEP clock.
            CT_IEP.COMPEN_bit.COMPEN_CNT = 0x0;
            
            //Slow Compensation to slow the timer down (prescaler)
            CT_IEP.SLOW_COMPEN = timer_prescalar;
            
            // IEP DEFAULT_INC only enabled when no clock compensation
            CT_IEP.GLB_CFG_bit.DEFAULT_INC = 0x0;
        }
        else{
            /*If no prescaler needed, timer will run at 200MHz, with increment of 1
             */
            //Disable compensation inc value 0 due to mode being disabled
            CT_IEP.GLB_CFG_bit.CMP_INC = 0x0;
        
            //Slow compensation is disabled
            CT_IEP.SLOW_COMPEN = 0x0;
        
            //Compensation counter mode disabled
            CT_IEP.COMPEN_bit.COMPEN_CNT = 0x0;
            
            // IEP counter increments by 1 per clock cycle
            CT_IEP.GLB_CFG_bit.DEFAULT_INC = 0x1;
        
        }
        //Enable counter, final state to activate all timer settings.
        CT_IEP.GLB_CFG_bit.CNT_ENABLE = 0x1;
    }
