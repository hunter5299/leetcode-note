#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

int lengthOfLastWord(char * s){
	if (s == NULL){
		return 0;
	}
	//ʹ��һ��������������¼����
	char *arr = (char*)malloc(sizeof(char)*strlen(s) + 50);
	char * cur = s;
	int i = 0, len = 0;
	while (*cur){
		/*��������*/
		//��û�������ո���д������
		if (*cur != ' '){
			arr[i] = *cur;
			i++;
		}
		//�������ո���
		else{
			char* temp = cur;
			int flag = 0;//���ո���Ƿ��е���
			while (*temp){
				if (*temp == ' '){
					temp++;
				}
				else{
					flag = 1;
					break;
				}
			}
			//���е��ʣ���i��0�������ͷ��ʼ��¼�µ���
			if (flag){
				i = 0;
			}
		}
		cur++;
	}
	//������ĩβ��0�����ַ���
	arr[i] = '\0';
	len = strlen(arr);
	free(arr);
	return len;
}