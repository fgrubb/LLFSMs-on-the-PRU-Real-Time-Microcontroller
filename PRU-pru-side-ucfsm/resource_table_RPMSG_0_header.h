/*
 * Copyright (C) 2016-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _RSC_TABLE_PRU_H_
#define _RSC_TABLE_PRU_H_

#include <stddef.h>
#include <rsc_types.h>
#include "pru_virtio_ids.h"

/*
 * Sizes of the virtqueues (expressed in number of buffers supported,
 * and must be power of 2)
 */
#define PRU_RPMSG_VQ0_SIZE	16
#define PRU_RPMSG_VQ1_SIZE	16

/*
 * The feature bitmap for virtio rpmsg
 */
#define VIRTIO_RPMSG_F_NS	0		//name service notifications

/* This firmware supports name service notifications as one of its features */
#define RPMSG_PRU_C0_FEATURES	(1 << VIRTIO_RPMSG_F_NS)

/* Definition for unused interrupts */
#define HOST_UNUSED		255

#pragma DATA_SECTION(".resource_table")
#pragma RETAIN
struct my_resource_table {
	struct resource_table base;

	uint32_t offset[2]; /* Should match 'num' in actual definition */

	/* rpmsg vdev entry */
	struct fw_rsc_vdev rpmsg_vdev;
	struct fw_rsc_vdev_vring rpmsg_vring0;
	struct fw_rsc_vdev_vring rpmsg_vring1;

	/* intc definition */
	struct fw_rsc_custom pru_ints;
}resourceTable;


#endif /* _RSC_TABLE_PRU_H_ */
