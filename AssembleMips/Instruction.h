#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "HashTable.h"


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
	int code;
	char name[8];
} INST_INFO;

typedef struct {
	union type {
		R_INSTRUCTION rInst;
		I_INSTRUCTION iInst;
		J_INSTRUCTION jInst;
	};
} INSTRUCTION;

static INST_INFO rFunctionCode[NUMBER_OF_R_OPCODES] = {
	{ 0x0, "SLL\0" },
	{ 0x2, "SRL\0" },
	{ 0x3, "SRA\0" },
	{ 0x4, "SLLV\0" },
	{ 0x6, "SRLV\0" },
	{ 0x7, "SRAV\0" },
	{ 0x8, "JR\0" },
	{ 0x9, "JALR\0" },
	{ 0xb, "SYSCALL\0" },
	{ 0x10, "MFHI\0" },
	{ 0x11, "MTHI\0" },
	{ 0x12, "MFLO\0" },
	{ 0x13, "MTLO\0" },
	{ 0x18, "MULT\0" },
	{ 0x19, "MULTU\0" },
	{ 0x1a, "DIV\0" },
	{ 0x1b, "DIVU\0" },
	{ 0x20, "ADD\0" },
	{ 0x21, "ADDU\0" },
	{ 0x22, "SUB\0" },
	{ 0x23, "SUBU\0" },
	{ 0x24, "AND\0" },
	{ 0x25, "OR\0" },
	{ 0x26, "XOR\0" },
	{ 0x27, "NOR\0" },
	{ 0x29, "SLTU\0" },
	{ 0x2a, "SLT\0" }
};

static INST_INFO ijFunctionCode[NUMBER_OF_IJ_OPCODES] = {
	{ 0x2, "J\0" },
	{ 0x3, "JAL\0" },
	{ 0x4, "BEQ\0" },
	{ 0x5, "BNE\0" },
	{ 0x6, "BLEZ\0" },
	{ 0x7, "BGTZ\0" },
	{ 0x8, "ADDI\0" },
	{ 0x9, "ADDIU\0" },
	{ 0xa, "SLTI\0" },
	{ 0xb, "SLTIU\0" },
	{ 0xc, "ANDI\0" },
	{ 0xd, "ORI\0" },
	{ 0xe, "XORI\0" },
	{ 0xf, "LUI\0" },
	{ 0x20, "LB\0" },
	{ 0x21, "LH\0" },
	{ 0x23, "LW\0" },
	{ 0x24, "LBU\0" },
	{ 0x25, "LHU\0" },
	{ 0x28, "SB\0" },
	{ 0x29, "SH\0" },
	{ 0x2b, "SW\0" }
};

HASHTABLE* instructions;
void initInstructionsTable();