#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
char pair(char*s){
	switch (*s){
	case '(':
		return ')';
	case '[':
		return ']';
	case '{':
		return '}';
	}
	return 0;
}
bool isValid(char * s){
	if (s == NULL){
		return false;
	}
	/*ջ�����ݽṹ��������������ţ�����ջ���������������ջ*/
	int len = strlen(s);
	char *arr = (char*)malloc(sizeof(char));
	int i = 0;
	int flag = false;
	while (len--){
		if ((*s == '(') || (*s == '{') || (*s == '[')){
			arr[i] = pair(s);
			i++;
		}
		else{
			if (i == 0 || arr[i - 1] != *s){
				free(arr);
				return false;
			}
			i--;
		}
		s++;
	}
	if (i == 0){
		flag = true;
	}
	feree(arr);
	return flag;
}