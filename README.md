# LLFSMs-on-the-PRU-Real-Time-Microcontroller

This repository holds the LLFSM state machines and other resources for the paper published.
Extra important information not put in the paper will be put here as an addition.

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
At times, the compiler flag PRU_UCFSM (under a #define) is used to add PRU specific code, allowing easier portability to compile and run on Linux without those lines added.  In most cases, this is because the flag is only used when compiling for the PRU, and the "native host" Linux Makefile won't have this in its command to the compiler binary.

&copy; Fisher Grubb & Prof Vladimir Estivill-Castro: the authors of the paper submitted to ISCeng2021, developers of this software.
