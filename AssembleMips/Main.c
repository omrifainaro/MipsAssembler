#include <stdio.h>
#include <string.h>
#include "Instruction.h"

extern HASHTABLE* instructions;
extern ITEM* getItemTable(HASHTABLE*, char[]);
extern void reverseFirstToken(char str[]);

int main(){
	initInstructionsTable();
	//printTable(instructions);
	char inst[20] = "SLL t0, t1, 20\0";
	char* token = strtok(inst, " ");
	ITEM* about = getItemTable(instructions, token);
	reverseFirstToken(inst);
	INSTRUCTION parsed = about->func(inst);
	printInstruction(parsed);
	removeTable(instructions);
	getchar();
	return 1;
}