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

void insert(HASHTABLE* table, ITEM item) {
	unsigned int index = hashkey(item.key, table->size);
	append(table->elements[index], newNode(item));
}

void remove(HASHTABLE* table, char key[]) {
	int index = hashkey(key, table->size);
	removeFromList(table->elements[index], key);
}

int getValue(HASHTABLE* table, char key[]) {
	int index = hashkey(key, table->size);
	LINKED_LIST* list = table->elements[index];
	NODE* cur = list->first;
	for (; cur != NULL; cur = cur->next) {
		if (isEqual(cur->item, key)) {
			return cur->item.value;
		}
	}
	return NOT_IN_HASH_TABLE;
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
	int i = 0;
	for (; i < table->size; i++) {
		delete(table->elements[i]);
	}
}