#include "Linkedlist.h"

LINKED_LIST* newList() {
	LINKED_LIST* list = (LINKED_LIST*)malloc(sizeof(LINKED_LIST));
	list->first = NULL;
	return list;
}

NODE* newNode(ITEM item) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->item = item;
	node->next = NULL;
	return node;
}

ITEM newItem(char key[], int value, callback func) {
	ITEM item;
	strcpy(item.key, key);
	item.value = value;
	item.func = func;
	return item;
}

int getValueList(LINKED_LIST* list, char key[]) {
	NODE* cur = list->first;
	for (; cur != NULL; cur = cur->next) {
		if (isEqual(cur->item, key)) {
			return cur->item.value;
		}
	}
	return NOT_IN_HASH_TABLE;
}

ITEM* getItemList(LINKED_LIST* list, char key[]) {
	ITEM err;
	NODE* cur = list->first;
	for (; cur != NULL; cur = cur->next) {
		if (isEqual(cur->item, key)) {
			return &cur->item;
		}
	}
	memset(&err, 0, 0);
	return &err;
}

void append(LINKED_LIST* list, NODE* node) {
	if (list->first == NULL) {
		list->first = node;
	}
	else{
		NODE* cur = list->first;
		while (cur->next != NULL) { cur = cur->next; }
		cur->next = node;
	}
}

void printItem(ITEM item) {
	printf("{'%s': 0x%x, %p}", item.key, item.value);
}

void printList(LINKED_LIST* list) {
	NODE* cur = list->first;
	while (cur != NULL) {
		printItem(cur->item);
		printf("->");
		cur = cur->next;
	}
	printf("NULL");
}

int isEqual(ITEM item, char key[]) {
	int i = 0;
	for (; i < MAX_NAME && key[i] != '\0'; i++) {
		if (item.key[i] != key[i]) {
			return FALSE;
		}
	}
	return TRUE;
}

void removeList(LINKED_LIST* list) {
	NODE *cur, *toDelete;
	cur = list->first;
	while (cur != NULL) {
		toDelete = cur;
		cur = cur->next;
		free(toDelete);
	}
}