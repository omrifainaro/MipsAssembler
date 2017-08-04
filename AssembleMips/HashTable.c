#include "HashTable.h"

unsigned int hashkey(unsigned char key[], int size) {
	int i;
	int sum = 0;
	for (i = 0; i < MAX_NAME && key[i] != '\0'; i++) {
		sum += key[i];
	}
	return sum % size;
}

HASHTABLE* newTable(int size) {
	int i = 0;
	HASHTABLE* table = (HASHTABLE*)malloc(sizeof(HASHTABLE));
	table->size = size;
	table->elements = (LINKED_LIST**)malloc(sizeof(LINKED_LIST*) * size);
	for (; i < table->size; i++) {
		table->elements[i] = newList();
	}
	return table;
}

void insertTable(HASHTABLE* table, ITEM item) {
	unsigned int index = hashkey(item.key, table->size);
	append(table->elements[index], newNode(item));
}

int getValueTable(HASHTABLE* table, char key[]) {
	int index = hashkey(key, table->size);
	LINKED_LIST* list = table->elements[index];
	return getValueList(list, key);
}

ITEM* getItemTable(HASHTABLE* table, char key[]) {
	int index = hashkey(key, table->size);
	LINKED_LIST* list = table->elements[index];
	return getItemList(list, key);
}

void printTable(HASHTABLE* table) {
	int i = 0;
	for (; i < table->size; i++) {
		printf("%d:[", i);
		printList(table->elements[i]);
		printf("]\n");
	}
}

void removeTable(HASHTABLE* table) {
	int i;
	for (i = 0; i < table->size; i++) {
		removeList(table->elements[i]);
	}
}