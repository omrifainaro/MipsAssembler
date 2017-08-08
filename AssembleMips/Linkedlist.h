#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"

extern struct _INSTRUCTION;
typedef struct _INSTRUCTION(*callback)(char[]);

typedef struct _ITEM{
	char key[MAX_NAME];
	unsigned int value;
	callback func;
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
ITEM newItem(char key[], int value, callback);
int getValueList(LINKED_LIST* list, char key[]);
ITEM* getItemList(LINKED_LIST* list, char key[]);
void appendList(LINKED_LIST* list, NODE* node);
void printList(LINKED_LIST* list);
void printItem(ITEM item);
int isEqual(ITEM item, char key[]);
void removeList(LINKED_LIST* list);