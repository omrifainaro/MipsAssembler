#include "Instruction.h"

void initTables() {
	ITEM cur;
	instructions = newTable(20);
	registers = newTable(20);
	int i = 0;
	for (; i < NUMBER_OF_OPCODES; i++) {
		cur = newItem(functionCode[i].name, functionCode[i].code, functionCode[i].parser);
		insert(instructions, cur);
	}
	for (i = 0; i < NUMBER_OF_REGISTERS; i++){
		cur = newItem(REGISTER_NAMES[i], i, NULL);
	}
}

INSTRUCTION parseArithmeticInstruction(char* instruction) {
	INSTRUCTION inst;
	char* token;
	inst.rInst.opcode = 0;
	inst.rInst.shift = 0;
	token = strtok(instruction, ' ');
	inst.rInst.func = getValue(instructions, token);
	token = (NULL, ", ");
	inst.rInst.rd = getValue(registers, token);
	token = (NULL, ", ");
	inst.rInst.rt = getValue(registers, token);
	token = (NULL, ", ");
	inst.rInst.rs = getValue(registers, token);
	token = (NULL, ", ");
	if (token != NULL) {
		printf("Instruction not found!");
		memset(&inst, 0, sizeof(instruction));
		return inst;
	}
	return inst;
}

INSTRUCTION parseImmArithmeticInstruction(char* instruction) {

}

INSTRUCTION parseArithmeticInstructionShift(char* instruction) {}

INSTRUCTION dummy(char* instruction) {}