#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

int lengthOfLastWord(char * s){
	if (s == NULL){
		return 0;
	}
	//使用一个辅助数组来记录单词
	char *arr = (char*)malloc(sizeof(char)*strlen(s) + 50);
	char * cur = s;
	int i = 0, len = 0;
	while (*cur){
		/*遍历单词*/
		//若没有遇到空格，则写入数组
		if (*cur != ' '){
			arr[i] = *cur;
			i++;
		}
		//若遇到空格，则
		else{
			char* temp = cur;
			int flag = 0;//检查空格后是否还有单词
			while (*temp){
				if (*temp == ' '){
					temp++;
				}
				else{
					flag = 1;
					break;
				}
			}
			//若有单词，则将i置0，数组从头开始记录新单词
			if (flag){
				i = 0;
			}
		}
		cur++;
	}
	//对数组末尾封0构成字符串
	arr[i] = '\0';
	len = strlen(arr);
	free(arr);
	return len;
}