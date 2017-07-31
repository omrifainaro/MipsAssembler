#pragma once
#include "Linkedlist.h"

typedef struct {
	int size;
	LINKED_LIST** elements;
} HASHTABLE;

unsigned int hashkey(unsigned char key[], int size);
HASHTABLE* newTable(int size);
void insert(HASHTABLE* table, ITEM item);
int getValue(HASHTABLE* table, char key[]);
void printTable(HASHTABLE* table);
void removeTable(HASHTABLE* table);