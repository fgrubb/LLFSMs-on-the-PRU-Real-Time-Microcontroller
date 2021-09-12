extern "C" {
#include <stdint.h>
#include <pru_cfg.h>
#include <pru_intc.h>
#include <rsc_types.h>
#include <pru_rpmsg_cpp.h>
#include <PRU-ucfsm-general-defines.h>
#include "PRU-LEDS.h"
#include "pru_comms.h"
}
#include <string.h>
#include "Resource_Table_Wrapper.h"


/* The PRU-ICSS system events used for RPMsg are defined in the Linux device tree
 * PRU0 uses system event 16 (To ARM) and 17 (From ARM)
 * PRU1 uses system event 18 (To ARM) and 19 (From ARM)
 */

//IRQ receiving
//Host-0 Interrupt sets bit 30 in register R31
#define PRU0_HOST0          		(1<<30)
#define PRU1_PRU0_INTERRUPT	(18)
#define IRQ_PRU0_TO_ARM		16
#define IRQ_ARM_TO_PRU0		17
#define IRQ_XFR_TIMEOUT		3

//IRQ generation
#define PRU_IRQ_out_strobe  16

#define IRQ_XFR_PRU0_TO_PRU1	20
#define IRQ_XFR_PRU1_TO_PRU0	21

/*
 * Using the name 'rpmsg-pru' will probe the rpmsg_pru driver found
 * at linux-x.y.z/drivers/rpmsg/rpmsg_pru.c
 */
#define CHAN_NAME		"rpmsg-pru"
#define CHAN_DESC		"PRU0 Channel 30"
#define CHAN_PORT		30 // creates /dev/rpmsg_pru30
#define RPMSG_PRU_PORT		1024

/*
 * Used to make sure the Linux drivers are ready for RPMsg communication
 * Found at linux-x.y.z/include/uapi/linux/virtio_config.h
 */
#define VIRTIO_CONFIG_S_DRIVER_OK	4




