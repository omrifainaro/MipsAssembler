#include "Instruction.h"

void initInstructionsTable() {
	ITEM cur;
	int i;
	instructions = newTable(20);
	registers = newTable(20);
	for (i = 0; i < NUMBER_OF_OPCODES; i++) {
		cur = newItem(functionCode[i].name, functionCode[i].code, functionCode[i].parserFunc);
		insertTable(instructions, cur);
	}
	for (i = 0; i < NUMBER_OF_REGISTERS; i++) {
		cur = newItem(REGISTER_NAMES[i], i, NULL);
		insertTable(registers, cur);
	}
}

INSTRUCTION dummyParse(char* instruction) {
	INSTRUCTION inst;
	memset(&inst, 0, sizeof(INSTRUCTION));
	printf("parsing: %s\n", instruction);
	return inst;
}

INSTRUCTION parseArithmeticInstruction(char strInstruction[]) {
	char* token;
	INSTRUCTION inst;
	inst.type = R_TYPE;
	inst.rInst.opcode = 0;
	inst.rInst.shift = 0;
	token = strtok(strInstruction, " ");
	inst.rInst.func = getValueTable(instructions, token);
	token = strtok(NULL, ", ");
	inst.rInst.rd = getValueTable(registers, token);
	token = strtok(NULL, ", ");
	inst.rInst.rt = getValueTable(registers, token);
	token = strtok(NULL, ", ");
	inst.rInst.rs = getValueTable(registers, token);
	token = strtok(NULL, ", ");
	if (token != NULL) {
		printf("Instruction not found!");
		memset(&inst, 0, sizeof(INSTRUCTION));
		return inst;
	}
	return inst;
}
