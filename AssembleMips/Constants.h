#pragma once

#define TRUE 1
#define FALSE 0
#define MAX_NAME 8

#define NUMBER_OF_R_OPCODES 27
#define NUMBER_OF_IJ_OPCODES 22

#define CODE_ERROR 7777
#define NOT_IN_HASH_TABLE 6666
#define INSTRUCTION_SIZE 8 //bytes
#define R_TYPE 0
#define I_TYPE 1
#define J_TYPE 2

static char* REGISTER_NAMES[32] = { "zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2",
"t3", "t4", "t5", "t6", "t7", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0",
"k1", "gp", "sp", "fp", "ra" };
