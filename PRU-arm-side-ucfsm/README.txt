INTRODUCTION
============

Fies to verify arm-pru communications in C++.

This files have a series of programs to test the communication of text files from the
arm/debian processor in the BeagleBone to the PRU.

1) The most elementary program is 
generate_input.cpp

This program generates the file input.txt with random words so we can text that the output
is the same as the input with
diff input.txt output.txt

2) pure_arm_to_pru.cpp
This is the copying of input.txt to output.txt
If compiled from intel/ubuntu it will not attempt to send the data to
the rpmsg device where a PRU program should be listening.
If compiled in the debian/arm it will send the data to the rpmsg device

3) pattern_to_pru.cpp
This is a program that rather than using a text input, produces a pattern
of counting binary values so that we can text the comunication from arm to pru.
You need to compile it for the arm and have a receiving program in the PRU
to observe it working.

4) open_test.c
C program to test the system call primitive open used in C++ to be able
to output to the device that is the rpmsg

5) pure_pru_to_arm.cpp
This is the inverse communication of data from the pru0 to the arm and constructing
a file named received.txt

6) arm_to_pru0.machine
The sending of input to the arm with model-driven software devleopment as this is
a llfsm for ucfsm.


PROPER LLFSMs for arm-pru and back communication
================================================

Typically, clean first

make -f LOCALMakefile MACHINE_NAME=arm_to_pru0 clean

make -f LOCALMakefile MACHINE_NAME=pru1_to_arm clean


Then build:
(you need the Fisher libraries and the code of ucfsm as sibling folders)

make -f LOCALMakefile MACHINE_NAME=arm_to_pru0

make -f LOCALMakefile MACHINE_NAME=pru1_to_arm clean

The machines are each in their destination directories local0 and local1

THE LLFSMS that run in the PRU
===============================
They are in the directory Paper-LLFSM-PRU/PRU-pru-side-ucfsm. You need the environment with the cross-compiler.

make -f PRUMakefile clean

make -f PRUMakefile MACHINE_NAME=arm_receiver_and_sender_from_pru0_to_pru1 
builds to run in the PRU0 the machine that receives from the arm and forwards to PRU1.


make -f PRUMakefile MACHINE_NAME=pru1_receiver_from_pru0_back_to_arm  PRU=1
build to run in the PRU1 the machine that receives from PRU0 and forwards to arm.

MOVE the cross compile to run in PRU(s)
===========================================
See readme from PRU

But essentially, we need 
to copy into the firmware
with root priviledges
cp PRU-pru-side-ucfsm_gen0.exe /lib/firmware/
cp PRU-pru-side-ucfsm_gen1.exe /lib/firmware/


Indicate who is running what
echo "PRU-pru-side-ucfsm_gen0.exe" > /sys/class/remoteproc/remoteproc2/firmware
echo "PRU-pru-side-ucfsm_gen1.exe" > /sys/class/remoteproc/remoteproc1/firmware

RUN THE EXPERIMENT
==================
Generate a large file of text.

In Paper-LLFSM-PRU/PRU-arm-side-ucfsm

do a 
make generate_input
This should produce a program in ./build/
named generate_input
Run it with
./build/generate_input text

And when asked provide a number like 100
You will get a file input.txt
with 10100 characters (one hundred lines of 100 characters and a \n per line).

Start the machine in PRU0
echo "start" > /sys/class/remoteproc/remoteproc2/state

You can check that the rpmgs bridge is set up with
ls -la /dev/rpmsg_pru30
this should exist

Start the machine in PRU1
echo "start" > /sys/class/remoteproc/remoteproc3/state
Similarly you can check for the existance of /dev/rpmsg_pru31

Also, if using the version with LEDS, you will see corresponding leds flashing for each machine's initial set up.

Run now the sender and the receiver in the arm side with
source run.sh
In the LEDS version you will see many lights flashing as the characters as passed across
(and probably diagnostic output in the terminal).
This long file will thus take a long time to transmit because of the LEDS flashsing patterns.


To verify sucessful transmision of the random data in input.txt do
diff input.txt received.txt
