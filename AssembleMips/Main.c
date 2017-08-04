#include <stdio.h>
#include <string.h>
#include "Instruction.h"

extern HASHTABLE* instructions;
extern ITEM* getItemTable(HASHTABLE*, char[]);

int main(){
	initInstructionsTable();
	printTable(instructions);
	char inst[20] = "ADD t0, t1, t2\0";
	char* token = strtok(inst, " ");
	ITEM* about = getItemTable(instructions, token);
	*(token + strlen(token)) = ' ';
	INSTRUCTION parsed = about->func(inst);
	if (parsed.type == R_TYPE)
		printf("opcode: opcode:0x%x rd:0x%x rt:0x%x rs:0x%x func:0x%x shamt:0x%x\n", parsed.rInst.opcode, parsed.rInst.rd,
			parsed.rInst.rt, parsed.rInst.rs, parsed.rInst.func, parsed.rInst.shift);

	removeTable(instructions);
	getchar();
	return 1;
}