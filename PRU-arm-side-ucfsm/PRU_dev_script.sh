#!/bin/bash 

#Script for setting environment for various PRU dev features.


#Get Kernel module remoteproc framework to print more detailed info to dmesg etc.
echo "Kernel will give extra debug messages for LKMs: remoteproc, pru_rproc."
echo 8 > /proc/sys/kernel/printk
echo -n 'module remoteproc +p' > /sys/kernel/debug/dynamic_debug/control
echo -n 'module pru_rproc +p' > /sys/kernel/debug/dynamic_debug/control

echo "Setting PRU LKM to load: PRU-pru-side-ucfsm_gen 1 & 2."
echo "PRU0: PRU-pru-side-ucfsm_gen0.exe"
echo "PRU-pru-side-ucfsm_gen0.exe" > /sys/class/remoteproc/remoteproc6/firmware

echo "PRU1: PRU-pru-side-ucfsm_gen1.exe"
echo "PRU-pru-side-ucfsm_gen1.exe" > /sys/class/remoteproc/remoteproc7/firmware

echo "Now ready for you to start by running:"
echo "echo \"start\" > /sys/class/remoteproc/remoteproc6/state"
echo "echo \"start\" > /sys/class/remoteproc/remoteproc7/state"

#echo "ARM-PRU0-Comms.out" > /sys/class/remoteproc/remoteproc6/firmware
#echo "ARM-PRU1-Comms.out" > /sys/class/remoteproc/remoteproc7/firmware

#echo "PRU0-comms.out" > /sys/class/remoteproc/remoteproc6/firmware
#echo "PRU1-comms.out" > /sys/class/remoteproc/remoteproc7/firmware

#echo "start" > /sys/class/remoteproc/remoteproc6/state
#echo "start" > /sys/class/remoteproc/remoteproc7/state
