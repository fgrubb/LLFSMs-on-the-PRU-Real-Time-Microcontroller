# LLFSMs on the PRU Real-Time Microcontroller

This repository holds the LLFSM state machines and other resources for the paper published.
Extra important information not put in the paper will be put here as an addition.

If state-machines aren't as important to you, and you're looking for generic code to use PRU features or attachments, of immediate use is:

* LCD library for generic character LCDs (made for 4 lines x 20 chars, should work with 2 lines x 16 chars)  
* IEP timer example, essentially a 64 bit timer, there is a function to configure it, including for an interrupt flag, and to read it for use similar to the Arduino micros().  
* Sending registers between PRUs for fast transfer without ARM interaction over the XFR bus, this involves interrupts and preventing timeouts, and dealing with them if they occur.  
* Different tips and tricks in the code, comments to explain what it is doing and why.

The board is a BeagleBone AI (AM5729), this is the multi-core, multi-arch upgrade to the BeagleBone Black (which used the Sitara AM3359).
The examples here run on the PRU, in the AI, this is 4 cores (only 2 used in this example), the Black has 2 cores, mostly the same, but their register definitions will be slighly different.
This code could be easily ported to the Black if one goes through the register names in the code and matches them up with the AM335x headers.
The main difference is likely the IEP timer configuration, and reading the timer.  The AI uses 2 x 32 bit registers, making it a 64 bit timer, the Black has a single 32 bit timer register.
The interrupts are configured automatically by the Linux Kernel Module (from TI, as part of the standard BB install from beagleboard.org), the PRU firmware resource_table header has the data structure arrays which the Kernel Module interprates, and configures.  One can do this manually, but leaving it to the LKM is done for it to also set up the needed Vring buffers and options to receive interrupts on the Linux side.  It also helps when using dmesg to look at logs when the firmware starts.
## Basic Instructions to get started
1. Get and install the PRU compiler tools from the resources section at the bottom of this page.
2. Look in the PRU-arm-side-ucfsm dir for the device tree files .dtb and .dts.  Backup the file your board boots from (likely in the uboot/dtb/ folder), copy this one over it so you don't have to change any names and configs.  I struggled to get uboot to use a different file name.
3. Make a folder where you want to test this project, then clone into it by copying and pasting the link from the green code button.
4. Change to the "local/libs-to-build" dir, run make, then "make install".  This will copy compiled libraries & headers.
5. Change to the PRU-pru-side-ucfsm folder, run "make -f PRUMakefile" and it will give you an error message with paths to add, such as where the PRU compiler is.
6. Compile both machines, for both PRU 0 & 1 using the 2 different machine name folders, without adding the ".machine" at the end.
7. Copy the "local" and "PRU-arm-side-ucfsm" dirs to your BeagleBone-AI, also the 2 binary compiled files from PRU-pru-side-ucfsm/gen0 & gen1 folders
8. Build the ARM/Linux side machines by running "make -f LOCALMakefile" and then seeing the error message to compile the 2 machines.
9. Copy the PRU binaries from gen0 and gen1 to /lib/firmware of the BeagleBone
10. Run the script "PRU_dev_script.sh" to enable debugging print statements, and set up the machine names to be loaded into the PRUs
11. Copy, paste and run the start commands for both PRUs.
12. Run the script in the ARM-side folder "ARM_run_send_receive_PRUs.sh".
13. Watch the PRU Cape LEDs flash and messages printed to the console as the text is sent across.  The LEDs will stop flashing when transferred.
14. Run "diff input.txt received.txt" and see if it shows a difference between the 2 files. If nothing printed, then was successful, also manually inspect both files.

### Notes:
Everything should work now as Makefiles etc have been changed for all to be self contained in this repository.  You will need to copy the ARM side machine folder and local with includes & ARM ucFSM libs onto your BeagleBone to compile with the ARM under Linux.  PRU files can be done on either your laptop, or the BeagleBone.

I have not yet gone through the instructions in detail, but what I've put should be enough.

Will add complete instructions with video later on.

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
#### Debugging
These are in the PRU_dev_script.sh.  
Run these commands before loading PRU firmware to allow dmesg to print more helpful info, such as Kernel Modules configuring interrupts & RPMsg passing Vrings:

DYNAMIC_DEBUG needs to be enabled in the Kernel before below works:

echo 8 > /proc/sys/kernel/printk

echo -n 'module remoteproc +p' > /sys/kernel/debug/dynamic_debug/control

echo -n 'module pru_rproc +p' > /sys/kernel/debug/dynamic_debug/control

#### Compiling & Other Related Advice
##### Stack & Heap
If your app keeps crashing, freezing, and you have no idea why, or what it's doing (always helps to have the JTAG if you can get it)
Check to make sure the heap and stack are not too small (you don't have to just make both bigger, you may find out its the heap that's the issue)
Review your Makefile settings for the compiler in ALL Makefiles, including libraries:
STACK_SIZE=0x100
HEAP_SIZE=0x100

### Other Resources


#### TI tools & links for the SoC in the BeagleBone AI
TI's git with their PRU examples: https://git.ti.com/cgit/pru-software-support-package/pru-software-support-package/

PRU industrial libraries with some source: https://www.ti.com/tool/PRU-ICSS-INDUSTRIAL-SW

TI Sitara AM5729 page with most documents, especially the Tech Ref Manual & some PRU docs: https://www.ti.com/product/AM5729

PRU compiler tools & docs:
https://www.ti.com/tool/PRU-CGT

https://www.ti.com/tool/download/PROCESSOR-SDK-LINUX-AM57X#downloads

Linux SDK release notes:
https://software-dl.ti.com/processor-sdk-linux/esd/docs/06_03_00_106/linux/Release_Specific_PLSDK_Release_Notes.html

Linux SDK documentation & intermediate intro to PRU:
https://software-dl.ti.com/processor-sdk-linux/esd/docs/06_03_00_106/linux/Foundational_Components_PRU-ICSS_PRU_ICSSG.html

Mark Yoder's PRU Cookbook examples, (PDF book in docs folder): https://github.com/MarkAYoder/PRUCookbook

#### MiPal
MiEditLLFSM, the Java based LLFSM gui viewer & editor written by Prof Vladimir Estivill-Castro  
MiPal downloads: http://mipal.net.au/downloads.php  
Related publications: http://mipal.net.au/publications.php

ICSEng2021 Conference 14-16 December: https://icseng.pwr.edu.pl/  
Conference paper:  https://link.springer.com/chapter/10.1007%2F978-3-030-92604-5_35

Contact: fisher.grubb@gmail.com

&copy; Fisher Grubb & Prof Vladimir Estivill-Castro: the authors of the paper submitted to ISCeng2021, developers of this software.
