pattern_to_pru_on_arm : pattern_to_pru.cpp pru_comms-lib.o
	g++ pattern_to_pru.cpp -I../local/libs-to-build/ build/pru_comms-lib.o -DON_THE_ARM -o build/pattern_to_pru_on_arm
pattern_to_pru : pattern_to_pru.cpp pru_comms-lib.o
	g++ pattern_to_pru.cpp -I../local/libs-to-build/ build/pru_comms-lib.o -o build/pattern_to_pru
pure_arm_to_pru_on_arm :  pure_arm_to_pru.cpp
	 g++ -DON_THE_ARM pure_arm_to_pru-lib.cpp -o build/pure_arm_to_pru_on_arm
pure_arm_to_pru :  pure_arm_to_pru.cpp
	 g++ pure_arm_to_pru-lib.cpp -o  build/pure_arm_to_pru
pure_pru_to_arm :  pure_pru_to_arm.cpp
	 g++ pure_pru_to_arm.cpp -o  build/pure_pru_to_arm
pure_pru_to_arm_on_arm :  pure_pru_to_arm.cpp
	 g++ pure_pru_to_arm.cpp -DON_THE_ARM -o  build/pure_pru_to_arm_on_arm
pure_pru_to_arm_testing :  pure_pru_to_arm.cpp
	 g++ pure_pru_to_arm.cpp -DTESTING -o  build/pure_pru_to_arm_testing
pru_comms-lib.o : ../local/libs-to-build/pru_comms-lib.h  ../local/libs-to-build//pru_comms-lib.c
	gcc -I../local/libs-to-build/ -c ../local/libs-to-build/pru_comms-lib.c -o build/pru_comms-lib.o
generate_input: generate_input.cpp  pru_comms-lib.o
	g++ generate_input.cpp -I../local/libs-to-build/ build/pru_comms-lib.o  -o build/generate_input
clean:
	rm -fr  build/* 
