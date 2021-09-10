pattern_to_pru_on_arm : pattern_to_pru.cpp pru_comms.o
	g++ pattern_to_pru.cpp -I../../Fisher-libs build/pru_comms.o -DON_THE_ARM -o build/pattern_to_pru_on_arm
pattern_to_pru : pattern_to_pru.cpp pru_comms.o
	g++ pattern_to_pru.cpp -I../../Fisher-libs build/pru_comms.o -o build/pattern_to_pru
pure_arm_to_pru_on_arm :  pure_arm_to_pru.cpp
	 g++ -DON_THE_ARM pure_arm_to_pru.cpp -o build/pure_arm_to_pru_on_arm
pure_arm_to_pru :  pure_arm_to_pru.cpp
	 g++ pure_arm_to_pru.cpp -o  build/pure_arm_to_pru
pure_pru_to_arm :  pure_pru_to_arm.cpp
	 g++ pure_pru_to_arm.cpp -o  build/pure_pru_to_arm
pure_pru_to_arm_on_arm :  pure_pru_to_arm.cpp
	 g++ pure_pru_to_arm.cpp -DON_THE_ARM -o  build/pure_pru_to_arm_on_arm
pure_pru_to_arm_testing :  pure_pru_to_arm.cpp
	 g++ pure_pru_to_arm.cpp -DTESTING -o  build/pure_pru_to_arm_testing
pru_comms.o : ../../Fisher-libs/pru_comms.h  ../../Fisher-libs/pru_comms.c
	gcc -I../../Fisher-libs -c ../../Fisher-libs/pru_comms.c -o build/pru_comms.o
generate_input: generate_input.cpp  pru_comms.o
	g++ generate_input.cpp -I../../Fisher-libs build/pru_comms.o  -o build/generate_input
clean:
	rm -fr  build/* 
