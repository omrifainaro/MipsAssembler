#include <stdio.h>
#include <string.h>
#include "Instruction.h"

extern HASHTABLE* instructions;

int main(){
	initTables();
	printTable(instructions);
	printf("ADD: %x\n", getValue(instructions, "ADD"));
	ITEM temp = getItem(instructions, "ADD");
	char* inst = "ADD t0, t1, t2";
	INSTRUCTION temp = temp.pFunc(inst);
	getchar();
	return 1;
}