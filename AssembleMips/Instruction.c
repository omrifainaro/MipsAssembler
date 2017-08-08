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

INSTRUCTION parseArithmeticImmInstruction(char strInstruction[]) {
	char* token;
	INSTRUCTION inst;
	inst.type = I_TYPE;
	token = strtok(strInstruction, " ");
	inst.iInst.opcode = getValueTable(instructions, token);
	token = strtok(NULL, ", ");
	inst.iInst.rs = getValueTable(registers, token);
	token = strtok(NULL, ", ");
	inst.iInst.rt = getValueTable(registers, token);
	token = strtok(NULL, ", ");
	inst.iInst.imm = atoi(token);
	token = strtok(NULL, ", ");
	if (token != NULL) {
		printf("Instruction not found!");
		memset(&inst, 0, sizeof(INSTRUCTION));
		return inst;
	}
	return inst;
}

INSTRUCTION parseShiftInstruction(char strInstruction[]) {
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
	inst.rInst.shift = atoi(token);
	token = strtok(NULL, ", ");
	if (token != NULL) {
		printf("Instruction not found!");
		memset(&inst, 0, sizeof(INSTRUCTION));
		return inst;
	}
	return inst;
}

void printInstruction(INSTRUCTION parsed) {
	if (parsed.type == R_TYPE)
		printf("opcode: opcode:0x%x rd:0x%x rt:0x%x rs:0x%x func:0x%x shamt:0x%x\n", parsed.rInst.opcode, parsed.rInst.rd,
			parsed.rInst.rt, parsed.rInst.rs, parsed.rInst.func, parsed.rInst.shift);
	else if (parsed.type == I_TYPE) {
		printf("opcode: opcode:0x%x rt:0x%x rs:0x%x imm:0x%x\n", parsed.iInst.opcode, parsed.iInst.rt,
			parsed.iInst.rs, parsed.iInst.imm);
	}
	else {
		printf("opcode: opcode:0x%x addr:0x%x\n", parsed.jInst.opcode, parsed.jInst.addr);
	}
}