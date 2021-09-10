Examples of Models Produced from a Generic Model described with Eclipse-Modelling Framework
The meta-model is a slight extension of that one defined in
	*) Miguel Carrillo, Vladimir Estivill-Castro, David A. Rosenblueth: " Verification and Simulation of Time-Domain Properties for Models of Behaviour". MODELSWARD (Revised Selected Papers) 2020: 225-249

The model is the file with xmi extension.

A model-to-text transformation produces dot and then the PDF view of the arrangement of LLFSMs
	file.xmi -> file.dot -(with dot) -> file.pdf

Another model-to-text transforamtion produces .smv files for input to NuSMV or nuXmv.
	file.xmi -> file.smv

Appending the files of properties and running the model checker provides the formal verification.

Example of the arm side machine:
=================================

% cat ArmSideSender.smv PropertiesArmSender.smv > ArmSideSenderWithProperties.smv 
% NuSMV -ctt ArmSideSenderWithProperties.smv

Important output:

However, all the states without successors are
non-reachable, so the machine is deadlock-free.
##########################################################

-- specification  G (arm_to_pru0.At_OUTPUT_TAIL -> (file_generator.At_TEST_EOF & w_b.EOF))  is true

-- specification  G (arm_to_pru0.At_FILES_OPEN -> (w_b.EOF ->  F arm_to_pru0.At_OUTPUT_TAIL))  is true

-- specification  G (arm_to_pru0.At_OUTPUT_TAIL -> arm_to_pru0.total_output = file_generator.total_chars_generated + 1)  is true

Example of the PRU-0 side machine:
==================================
% cat Pru0ToPru1.smv PropertiesPRU0.smv > Pru0ToPru1WithProperties.smv
% NuSMV -ctt Pru0ToPru1WithProperties.smv

Important output:

However, all the states without successors are
non-reachable, so the machine is deadlock-free.
##########################################################

-- specification  G ((arm_to_pru0.At_OUTPUT_TAIL & pru1_to_arm.At_RESET) ->  F ( G arm_to_pru0.total_blocks_forwarded = pru1_to_arm.total_blocks_received))  is true

-- specification  G ((arm_to_pru0.At_OUTPUT_TAIL & pru1_to_arm.At_RESET) ->  F [0,12]  G arm_to_pru0.total_blocks_forwarded = pru1_to_arm.total_blocks_received)  is true

