# LLFSMs-on-the-PRU-Real-Time-Microcontroller

This repository holds the LLFSM state machines and other resources for the paper published.
Extra important information not put in the paper will be put here as an addition.

## Important Info For PRU IO Pins: LEDs, Buttons & LCD
This project relies on the PRU Cape, one can use their own proto board with BeagleBone AI, or Black header layouts, but then must edit the device tree file.
Device tree source must be compiled to a binary, then copied to the uBoot/dtb folder, may be easiest to just back up the older file, and add the new one using same name.
The general defines header file has IO pin definitions for LEDs, buttons and LCD connections, it mentions this reliance on the device tree file.

&copy; Fisher Grubb & Prof Vladimir Estivill-Castro: the authors of the paper, developers of this software.
