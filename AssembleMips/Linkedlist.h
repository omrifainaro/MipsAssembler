#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"

typedef struct _ITEM{
	char key[MAX_NAME];
	unsigned int value;
} ITEM;

typedef struct _NODE{
	ITEM* item;
	struct _NODE* next;
} NODE;

typedef struct _LINKED_LIST{
	NODE* first;
} LINKED_LIST;

LINKED_LIST* newList();
NODE* newNode(ITEM* item);
ITEM* newItem(char key[], int value);
void append(LINKED_LIST* list, NODE* node);
void printList(LINKED_LIST* list);
void printItem(ITEM* item);
int isEqual(ITEM* item, char key[]);