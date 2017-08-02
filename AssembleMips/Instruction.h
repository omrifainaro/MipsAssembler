#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "HashTable.h"
#include "Utils.h"


typedef struct {
	unsigned int func : 6;
	unsigned int shift : 5;
	unsigned int rd : 5;
	unsigned int rt : 5;
	unsigned int rs : 5;
	unsigned int opcode : 6;
} R_INSTRUCTION;

typedef struct {
	signed int imm : 16;
	unsigned int rt : 5;
	unsigned int rs : 5;
	unsigned int opcode : 6;
} I_INSTRUCTION;

typedef struct {
	unsigned int addr : 26;
	unsigned int opcode : 6;
} J_INSTRUCTION;

typedef struct {
	union type {
		R_INSTRUCTION rInst;
		I_INSTRUCTION iInst;
		J_INSTRUCTION jInst;
	};
} INSTRUCTION;

typedef INSTRUCTION(*pCallbackParser)(char* instruct);

typedef struct {
	int code;
	char name[8];
	pCallbackParser parser;
} INST_INFO;

HASHTABLE* instructions;
HASHTABLE* registers;

INSTRUCTION parseArithmeticInstruction(char* instruction);
INSTRUCTION parseArithmeticInstructionShift(char* instruction);
INSTRUCTION parseImmArithmeticInstruction(char* instruction);
INSTRUCTION dummy(char* instruction);

static INST_INFO functionCode[NUMBER_OF_OPCODES] = {
	{ 0x0, "SLL\0",  dummy },
	{ 0x2, "SRL\0", dummy },
	{ 0x3, "SRA\0", dummy },
	{ 0x4, "SLLV\0", dummy },
	{ 0x6, "SRLV\0", dummy },
	{ 0x7, "SRAV\0", dummy },
	{ 0x8, "JR\0", dummy },
	{ 0x9, "JALR\0", dummy },
	{ 0xb, "SYSCALL\0", dummy },
	{ 0x10, "MFHI\0", dummy },
	{ 0x11, "MTHI\0", dummy },
	{ 0x12, "MFLO\0", dummy },
	{ 0x13, "MTLO\0", dummy },
	{ 0x18, "MULT\0", dummy },
	{ 0x19, "MULTU\0", dummy },
	{ 0x1a, "DIV\0", dummy },
	{ 0x1b, "DIVU\0", dummy },
	{ 0x20, "ADD\0", parseArithmeticInstruction },
	{ 0x21, "ADDU\0", dummy },
	{ 0x22, "SUB\0", dummy },
	{ 0x23, "SUBU\0", dummy },
	{ 0x24, "AND\0", dummy },
	{ 0x25, "OR\0", dummy },
	{ 0x26, "XOR\0", dummy },
	{ 0x27, "NOR\0", dummy },
	{ 0x29, "SLTU\0", dummy },
	{ 0x2a, "SLT\0", dummy },
	{ 0x2, "J\0", dummy },
	{ 0x3, "JAL\0", dummy },
	{ 0x4, "BEQ\0", dummy },
	{ 0x5, "BNE\0", dummy },
	{ 0x6, "BLEZ\0", dummy },
	{ 0x7, "BGTZ\0", dummy },
	{ 0x8, "ADDI\0", dummy },
	{ 0x9, "ADDIU\0", dummy },
	{ 0xa, "SLTI\0", dummy },
	{ 0xb, "SLTIU\0", dummy },
	{ 0xc, "ANDI\0", dummy },
	{ 0xd, "ORI\0", dummy },
	{ 0xe, "XORI\0", dummy },
	{ 0xf, "LUI\0", dummy },
	{ 0x20, "LB\0", dummy },
	{ 0x21, "LH\0", dummy },
	{ 0x23, "LW\0", dummy },
	{ 0x24, "LBU\0", dummy },
	{ 0x25, "LHU\0", dummy },
	{ 0x28, "SB\0", dummy },
	{ 0x29, "SH\0", dummy },
	{ 0x2b, "SW\0", dummy }
};

void initTables();

#endif