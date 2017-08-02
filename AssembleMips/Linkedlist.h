#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"
#include "Instruction.h"

typedef struct _ITEM{
	char key[MAX_NAME];
	unsigned int value;
	pCallbackParser pFunc;
} ITEM;

typedef struct _NODE{
	ITEM item;
	struct _NODE* next;
} NODE;

typedef struct _LINKED_LIST{
	NODE* first;
} LINKED_LIST;

LINKED_LIST* newList();
NODE* newNode(ITEM item);
ITEM newItem(char key[], int value, pCallbackParser pFunc);
ITEM newItem(char key[], int value);
ITEM* getItemFromList(LINKED_LIST* list, char key[]);
int getValueFromList(LINKED_LIST* list, char key[]);
void append(LINKED_LIST* list, NODE* node);
void updateItem(LINKED_LIST* list, char key[], pCallbackParser parser);
void printList(LINKED_LIST* list);
void printItem(ITEM item);
int isEqual(ITEM item, char key[]);
void removeFromList(LINKED_LIST* list, char key[]);
void delete(LINKED_LIST* list);

#endif