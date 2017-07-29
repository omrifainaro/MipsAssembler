#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <string.h>

char uppercase(char c) {
	if (c >= 'a' && c <= 'z')
		return c + ('A' - 'a');
	return c;
}

void toUpper(char* str) {
	int i = 0;
	for (; str[i] != '\0'; i++) {
		str[i] = uppercase(str[i]);
	}
}
#endif