#include <stdio.h>
#include <string.h>
#include "Instruction.h"

extern HASHTABLE* instructions;

int main(){
	initInstructionsTable();
	printTable(instructions);
	printf("ADD: %x\n", getValue(instructions, "ADD"));
	removeTable(instructions);
	getchar();
	return 1;
}