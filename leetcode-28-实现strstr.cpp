#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

/*KMPÀ„∑®*/
void getNext(int* next, char* s) {
	int j = -1;
	next[0] = j;
	for (int i = 1; i < strlen(s); i++) {
		while (j >= 0 && s[i] != s[j + 1]) {
			j = next[j];
		}
		if (s[i] == s[j + 1]) {
			j++;
		}
		next[i] = j;
	}
}

int strStr(char * haystack, char * needle){
	if (strlen(needle) == 0) {
		return 0;
	}
	int j = -1;
	int* next = (int*)malloc(sizeof(int)* strlen(needle));
	getNext(next, needle);
	for (int i = 0; i < strlen(haystack); i++) {
		while (j >= 0 && haystack[i] != needle[j + 1]) {
			j = next[j];
		}
		if (haystack[i] == needle[j + 1]) {
			j++;
		}
		if (j == strlen(needle) - 1) {
			return i - strlen(needle) + 1;
		}
	}