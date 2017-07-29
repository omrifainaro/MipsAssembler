#include "Instruction.h"

void initInstructionsTable() {
	instructions = newTable(20);
	ITEM* cur = NULL;
	int i = 0;
	for (; i < NUMBER_OF_R_OPCODES; i++) {
		cur = newItem(rFunctionCode[i].name, rFunctionCode[i].code);
		insert(instructions, cur);
	}
	for (i=0; i < NUMBER_OF_IJ_OPCODES; i++) {
		cur = newItem(ijFunctionCode[i].name, ijFunctionCode[i].code);
		insert(instructions, cur);
	}
}