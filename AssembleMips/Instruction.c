#include "Instruction.h"

void initInstructionsTable() {
	instructions = newTable(20);
	ITEM cur;
	int i = 0;
	for (; i < NUMBER_OF_OPCODES; i++) {
		cur = newItem(functionCode[i].name, functionCode[i].code);
		insert(instructions, cur);
	}
}