#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 
*/

void reverse(char* start, char* end){
	while (start<end){
		char t = *start;
		*start = *end;
		*end = t;
		start++; end--;
	}
}

char* reverseLeftWords(char* s, int n){
	if (s == NULL || n == 0){
		return s;
	}
	int len = strlen(s);
	//三次翻转法
	reverse(s, s + len - 1);
	reverse(s, s + len - n - 1);
	reverse(s + len - n, s + len - 1);
	return s;
}