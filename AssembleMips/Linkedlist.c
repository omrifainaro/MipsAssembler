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

ITEM newItem(char key[], int value) {
	ITEM item;
	strcpy(item.key, key);
	item.value = value;
	return item;
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
	printf("{'%s': 0x%x}", item.key, item.value);
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

void delete(LINKED_LIST* list) {
	NODE* cur = list->first;
	NODE* next;
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}

void removeFromList(LINKED_LIST* list, char key[]) {
	NODE* cur = list->first;
	NODE* toDelete;
	if (isEqual(cur->item, key)) {
		toDelete = cur;
		list->first = toDelete->next;
	}
	else {
		while (cur->next != NULL) {
			if (isEqual(cur->next->item, key)) {
				toDelete = cur->next;
				cur->next = toDelete->next;
			}
			cur = cur->next;
		}
	}
	free(toDelete);
}