
// Mapping sysevts to a channel. Each pair contains a sysevt, channel.
struct ch_map pru_intc_map[] = { {16, 2},
				 {17, 0},
};
/*
struct my_resource_table {
	struct resource_table base;

	uint32_t offset[2]; // Should match 'num' in actual definition

	// rpmsg vdev entry
	struct fw_rsc_vdev rpmsg_vdev;
	struct fw_rsc_vdev_vring rpmsg_vring0;
	struct fw_rsc_vdev_vring rpmsg_vring1;

	// intc definition
	struct fw_rsc_custom pru_ints;
};
*/
#pragma DATA_SECTION(".resource_table")
#pragma RETAIN
struct my_resource_table resourceTable_tail = {
	1,	/* Resource table version: only version 1 is supported by the current driver */
	2,	/* number of entries in the table */
	0, 0,	/* reserved, must be zero */
	/* offsets to entries */
	{
		offsetof(struct my_resource_table, rpmsg_vdev),
		offsetof(struct my_resource_table, pru_ints),
	},

	/* rpmsg vdev entry */
	{
		(uint32_t)TYPE_VDEV,                    //type
		(uint32_t)VIRTIO_ID_RPMSG,              //id
		(uint32_t)0,                            //notifyid
		(uint32_t)RPMSG_PRU_C0_FEATURES,	//dfeatures
		(uint32_t)0,                            //gfeatures
		(uint32_t)0,                            //config_len
		(uint8_t)0,                             //status
		(uint8_t)2,                             //num_of_vrings, only two is supported
		{ (uint8_t)0, (uint8_t)0 },             //reserved
		/* no config data */
	},
	/* the two vrings */
	{
		FW_RSC_ADDR_ANY,        //da, will be populated by host, can't pass it in
		16,                     //align (bytes),
		PRU_RPMSG_VQ0_SIZE,     //num of descriptors
		0,                      //notifyid, will be populated, can't pass right now
		0                       //reserved
	},
	{
		FW_RSC_ADDR_ANY,        //da, will be populated by host, can't pass it in
		16,                     //align (bytes),
		PRU_RPMSG_VQ1_SIZE,     //num of descriptors
		0,                      //notifyid, will be populated, can't pass right now
		0                       //reserved
	},

	{
		TYPE_POSTLOAD_VENDOR, PRU_INTS_VER0 | TYPE_PRU_INTS,
		sizeof(struct fw_rsc_custom_ints),
		{
			0x0000,
			/* Channel-to-host mapping, 255 for unused */
			0, HOST_UNUSED, 2, HOST_UNUSED, HOST_UNUSED,
			HOST_UNUSED, HOST_UNUSED, HOST_UNUSED, HOST_UNUSED, HOST_UNUSED,
			/* Number of evts being mapped to channels */
			(sizeof(pru_intc_map) / sizeof(struct ch_map)),
			/* Pointer to the structure containing mapped events */
			pru_intc_map,
		},
	},
};

