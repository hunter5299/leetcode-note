#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define bool int
#define false 0
#define true 1
/*
bool isValid(char * s){
	if (s == NULL){
		return false;
	}
	//ջ�����ݽṹ��������������ţ�����ջ���������������ջ
	int len = strlen(s);
	char *arr = (char*)malloc(sizeof(char)*len);
	int count = 0, i = 0;
	int flag = false;
	while (len--){
		if ((*s == '(') || (*s == '{') || (*s == '[')){
			switch(*s){
			case '(':
				arr[i] = ')';
				break;
			case '[':
				arr[i] = ']';
				break;
			case '{':
				arr[i] = '}';
				break;
			}
			i++;
			count++;
		}
		else{
			//��iΪ0����˵�����������ſ�ʼ
			if (i == 0){
				return false;
			}
			if (arr[i - 1] == *s){
				count--;
				i--;
			}
			else{
				break;
			}
		}
		s++;
	}
	if (count == 0){
		flag = true;
	}
	return flag;
}
*/
/*�Ż�һ�´��룬�ṹ����*/
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
	//char arr[len];c99��֧�ָ���������ʼ�����鳤��
	char* arr = (char*)malloc(sizeof(char)*len);
	int i = 0;
	int flag = false;
	while (len--){
		if ((*s == '(') || (*s == '{') || (*s == '[')){
			arr[i] = pair(s);
			i++;
		}
		else{
			if (i == 0 || arr[i - 1] != *s){
				return false;
			}
			i--;
		}
		s++;
	}
	
	return i==0 ? 1 : 0;
}
void test(){
	bool ret = 0;
	char* p = "]";
	ret = isValid(p);

	printf("ret = %d\n", ret);
	system("pause");
}
int main(){
	test();
	return 0;
}