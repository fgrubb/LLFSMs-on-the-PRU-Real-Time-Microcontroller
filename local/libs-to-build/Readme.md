# Library Source Headers
These are the main foundational libraries, the Makefile builds & copies them to the ../libs folder for the machines later to link against.

## Instructions
run "make", it will generate the library objects in the build folder, then run "make install".
This will copy these compiled libraries into the ../libs dir, it will also copy the headers into the ../includes dir.

Then one can go about building PRU and ARM machines.
