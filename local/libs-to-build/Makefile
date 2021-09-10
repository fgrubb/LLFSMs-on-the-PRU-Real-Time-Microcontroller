# This Makefile is an expansion of the original TI one in their PRU examples folder.

# PRU_CGT environment variable must point to the TI PRU code gen tools directory. E.g.:
#(Desktop Linux) export PRU_CGT=/path/to/pru/code/gen/tools/ti-cgt-pru_2.1.2
#(Windows) set PRU_CGT=C:/path/to/pru/code/gen/tools/ti-cgt-pru_2.1.2
#(ARM Linux*) export PRU_CGT=/usr/share/ti/cgt-pru
#
# *ARM Linux also needs to create a symbolic link to the /usr/bin/ directory in
# order to use the same Makefile
#(ARM Linux) ln -s /usr/bin/ /usr/share/ti/cgt-pru/bin

ifndef PRU_CGT
define ERROR_BODY

*******************************************************************************
PRU_CGT environment variable is not set. Examples of a path (Desktop Linux):
export PRU_CGT=~/ti/ccs1010/ccs/tools/compiler/ti-cgt-pru_2.3.3


/path/to/pru/code/gen/tools/ti-cgt-pru_2.1.2
(Windows):
set PRU_CGT=C:/path/to/pru/code/gen/tools/ti-cgt-pru_2.1.2

(ARM Linux):
export PRU_CGT=/usr/share/ti/cgt-pru

*ARM Linux also needs to create a symbolic link to the /usr/bin/ directory in
order to use the same Makefile
(ARM Linux):
ln -s /usr/bin/ /usr/share/ti/cgt-pru/bin
*******************************************************************************

endef
$(error $(ERROR_BODY))
endif

ifndef PRU_LOCAL_HOME
define LOCAL_ERROR_BODY

*******************************************************************************
You must define PRU_LOCAL_HOME so that the make install can move include headers in compiled
libraries to that well known place. Typically  ../local
For instance:
export PRU_LOCAL_HOME=../local
*******************************************************************************
endef
$(error $(LOCAL_ERROR_BODY))
endif

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MKFILE_PATH))))
#PRU_HOME=/home/vlad/BeagleBone/PRU_Co-processors/Hand_on_labs/pru-software-support-package-5.7.0
PROJ_NAME=$(CURRENT_DIR)
#LINKER_COMMAND_FILE=../AM335x_PRU.cmd
LINKER_COMMAND_FILE=../include/AM57xx_PRU.cmd
LIBS=--library=../lib/rpmsg_lib.lib
INCLUDE=--include_path=$(PRU_CGT)/include --include_path=$(PRU_LOCAL_HOME)/include_TI_regs/am572x_2_0 # --include_path=../include #--include_path=../libs-to-build #--include_path=./FirstMachine.machine/
#INCLUDE=--include_path=$(PRU_HOME)/include --include_path=$(PRU_HOME)/include/am335x #--include_path=../../../lab_3/solution/PRU_HDQ_TempSensor0
STACK_SIZE=0x100
HEAP_SIZE=0x100
GEN_DIR=PRU-build

#Common compiler and linker flags (Defined in 'PRU Optimizing C/C++ Compiler User's Guide)
CFLAGS=-v3 -O2 --display_error_number --endian=little --hardware_mac=on --obj_directory=$(GEN_DIR) --pp_directory=$(GEN_DIR) -ppd -ppa -DPRU_UCFSM
#Linker flags (Defined in 'PRU Optimizing C/C++ Compiler User's Guide)
LFLAGS=--reread_libs --warn_sections --stack_size=$(STACK_SIZE) --heap_size=$(HEAP_SIZE)

TARGET=$(GEN_DIR)/PRU-ucfsm-timer-lib.object $(GEN_DIR)/PRU-ucfsm-LCD-lib.object $(GEN_DIR)/pru_comms.object $(GEN_DIR)/PRU-LEDS.object $(GEN_DIR)/PRU-ucfsm-PRU_XFR_Comms-lib.object $(GEN_DIR)/PRU-ucfsm-PRU_IRQ-lib.object
MAP=$(GEN_DIR)/$(PROJ_NAME).map
SOURCES=$(wildcard *.c)  
#Using .object instead of .obj in order to not conflict with the CCS build process
OBJECTS=$(patsubst %,$(GEN_DIR)/%,$(SOURCES:.c=.object)) #$(patsubst ,%,$(GEN_DIR)/%,$(SOURCES/./FirstMachine.machine/:.mm=.object))

all: printStart $(TARGET) printEnd

install:
	@echo ''
	@echo '************************************************************'
	@echo 'Copying include files to ' $(PRU_LOCAL_HOME)/includes
	mkdir -p $(PRU_LOCAL_HOME)/includes
	cp *.h $(PRU_LOCAL_HOME)/includes
	@echo '************************************************************'
	@echo 'Copying taegret libraries files to ' $(PRU_LOCAL_HOME)/libs
	mkdir -p $(PRU_LOCAL_HOME)/libs
	cp $(GEN_DIR)/*.object $(PRU_LOCAL_HOME)/libs


printStart:
	@echo ''
	@echo '************************************************************'
	@echo 'Building project: $(PROJ_NAME)'
	@echo 'File that need compilation: $(SOURCES)'
	@echo 'Corresponding object files: $(OBJECTS)'

printEnd:
	@echo ''
	@echo 'Output files can be found in the "$(GEN_DIR)" directory'
	@echo ''
	@echo 'Finished building project: $(PROJ_NAME)'
	@echo 'RUN make install to copy includes and compiled modules to well-known place'
	@echo '************************************************************'
	@echo ''

# Invokes the compiler on all cc files in the directory to create the object files
$(GEN_DIR)/%.object: %.c
	@mkdir -p $(GEN_DIR)
	@echo ''
	@echo 'Building file: $<'
	@echo 'Invoking: PRU Compiler'
	$(PRU_CGT)/bin/clpru $(INCLUDE) $(CFLAGS) -fe $@ $<
#$(INCLUDE)
	
.PHONY: all clean

# Remove the $(GEN_DIR) directory
clean:
	@echo ''
	@echo '************************************************************'
	@echo 'Cleaning project: $(PROJ_NAME)'
	@echo ''
	@echo 'Removing files in the "$(GEN_DIR)" directory'
	@rm -rf $(GEN_DIR)
	@echo ''
	@echo 'Finished cleaning project: $(PROJ_NAME)'
	@echo '************************************************************'
	@echo ''

# Includes the dependencies that the compiler creates (-ppd and -ppa flags)
-include $(OBJECTS:%.object=%.pp)

