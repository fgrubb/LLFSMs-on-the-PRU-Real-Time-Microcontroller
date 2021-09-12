
//#define PRU1

extern "C" {
#include <stdint.h>
#include <stdlib.h>
#include <pru_cfg.h>
#include <pru_intc.h>
#include <rsc_types.h>
#include <pru_rpmsg_cpp.h>
//#include <PRU-ucfsm-LCD-lib.h>
#include <PRU-ucfsm-general-defines.h>
#include "PRU-LEDS.h"
#include "pru_comms.h"
//#include <PRU-ucfsm-PRU_XFR_Comms-lib.h>
#include <string.h>
}

#include "Resource_Table_Wrapper.h"

//#include "resource_table_RPMSG_1_CPP.h"

#define PRU1_HOST1		((uint32_t) 1 << 31)

#define IRQ_XFR_TIMEOUT		3
#define IRQ_XFR_PRU0_TO_PRU1	20
#define IRQ_XFR_PRU1_TO_PRU0	21
#define IRQ_PRU1_TO_ARM		18
#define IRQ_ARM_TO_PRU1		19

#define PRU_IRQ_out_strobe		16

#define RPMSG_CHAN_DRV		"rpmsg-pru"
#define RX_CHAN_DESC		"PRU1 Port 31"
#define RPMSG_PORT		31
#define RPMSG_PRU_PORT		1024

#define VIRTIO_CONFIG_S_DRIVER_OK	4

#define PRU1_RPMsg_test_str		"PRU1: RPMsg ready\n\0"







