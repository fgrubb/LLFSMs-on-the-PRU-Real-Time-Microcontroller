# LLFSMs-on-the-PRU-Real-Time-Microcontroller

This repository holds the LLFSM state machines and other resources for the paper published.
Extra important information not put in the paper will be put here as an addition.

The board is a BeagleBone AI (AM5729), this is the multi-core, multi-arch upgrade to the BeagleBone Black (which used the Sitara AM3359).
The examples here run on the PRU, in the AI, this is 4 cores (only 2 used in this example), the Black has 2 cores, mostly the same, but their register definitions will be slighly different.
This code could be easily ported to the Black if one goes through the register names in the code and matches them up with the AM335x headers.
The main difference is likely the IEP timer configuration, and reading the timer.  The AI uses 2 x 32 bit registers, making it a 64 bit timer, the Black has a single 32 bit timer register.
The interrupts are configured automatically by the Linux Kernel Module (from TI, as part of the standard BB install from beagleboard.org), the PRU firmware resource_table header has the data structure arrays which the Kernel Module interprates, and configures.  One can do this manually, but leaving it to the LKM is done for it to also set up the needed Vring buffers and options to receive interrupts on the Linux side.  It also helps when using dmesg to look at logs when the firmware starts.

## Contents of this Repository
State machines using the LLFSM structure, which are run on the ucFSM scheduler for "Bare Metal" applications on micro-controllers.

State diagrams, some were in the paper, but others not to save space, they are here in full size.

Model checking/formal verification proof (using NuSMV and nuXMV)

Supporting configuration files, such as device tree source

Pinout information due to some modifications of the PRU Cape.

Instructions for how to use this all.

## Important Info For PRU IO Pins: LEDs, Buttons & LCD
This project relies on the PRU Cape, one can use their own proto board with BeagleBone AI, or Black header layouts, but then must edit the device tree file.
Device tree source must be compiled to a binary, then copied to the uBoot/dtb folder, may be easiest to just back up the older file, and add the new one using same name.
The general defines header file has IO pin definitions for LEDs, buttons and LCD connections, it mentions this reliance on the device tree file.

## General Notes
### Compiler Flags
At times, the compiler flag PRU_UCFSM (under a #define) is used to add PRU specific code, allowing easier portability to compile and run on Linux without those lines added.  In most cases, this is because the flag is only used when compiling for the PRU, and the "native host" Linux Makefile won't have this in its command to the compiler binary.

### Random Usage Tips
Run these commands before loading PRU firmware:

DYNAMIC_DEBUG needs to be enabled in the Kernel before below works:

echo 8 > /proc/sys/kernel/printk

echo -n 'module remoteproc +p' > /sys/kernel/debug/dynamic_debug/control

echo -n 'module pru_rproc +p' > /sys/kernel/debug/dynamic_debug/control


### Other Resources


#### TI tools & links for the SoC in the BeagleBone AI
TI's git with their PRU examples: https://git.ti.com/cgit/pru-software-support-package/pru-software-support-package/

https://www.ti.com/tool/PROCESSOR-SDK-AM57X

https://www.ti.com/tool/download/PROCESSOR-SDK-LINUX-AM57X#downloads

Linux SDK release notes:
https://software-dl.ti.com/processor-sdk-linux/esd/docs/06_03_00_106/linux/Release_Specific_PLSDK_Release_Notes.html

Linux SDK documentation & intermediate intro to PRU:
https://software-dl.ti.com/processor-sdk-linux/esd/docs/06_03_00_106/linux/Foundational_Components_PRU-ICSS_PRU_ICSSG.html

&copy; Fisher Grubb & Prof Vladimir Estivill-Castro: the authors of the paper submitted to ISCeng2021, developers of this software.
