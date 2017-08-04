#pragma once
#include "Linkedlist.h"

typedef struct {
	int size;
	LINKED_LIST** elements;
} HASHTABLE;

unsigned int hashkey(unsigned char key[], int size);
HASHTABLE* newTable(int size);
void insertTable(HASHTABLE* table, ITEM item);
int getValueTable(HASHTABLE* table, char key[]);
ITEM* getItemTable(HASHTABLE* table, char key[]);
void printTable(HASHTABLE* table);
void removeTable(HASHTABLE* table);