#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Linkedlist.h"

typedef INSTRUCTION(*pCallbackParser)(char* instruct);

typedef struct {
	int size;
	LINKED_LIST** elements;
} HASHTABLE;

unsigned int hashkey(unsigned char key[], int size);
HASHTABLE* newTable(int size);
void insert(HASHTABLE* table, ITEM item);
void remove(HASHTABLE* table, char key[]);
void update(HASHTABLE* table, char key[], pCallbackParser func);
int getValue(HASHTABLE* table, char key[]);
ITEM getItem(HASHTABLE* table, char key[]);
void printTable(HASHTABLE* table);
void removeTable(HASHTABLE* table);

#endif // !LINKED_LIST_H