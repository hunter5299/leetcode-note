#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*989������ʽ�������ӷ�*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	int flag = 0;
	int t = 0;
	int i, j;
	//��������Ŀռ��С����numsizeΪ1����k��һ������ֵʱ����ô���벻��ȫ
	int* arr = (int*)malloc(sizeof(int)*(numSize + 200));
	int retS = 0;
	//num��ջ
	i = numSize;
	while (i){
		num++;
		i--;
	}
	num--;
	i = 0;
	//k��ջͬʱ��num����
	while (k && numSize){
		t = (*num) + (k % 10) + flag;
		flag = 0;
		if (t >= 10){
			arr[i] = t % 10;
			flag = 1;
		}
		else{
			arr[i] = t;
		}
		i++;
		num--;
		k = k / 10;
		numSize--;
	}
	if (k>0){
		while (k){
			t = k % 10 + flag;
			flag = 0;
			if (t >= 10){
				arr[i] = t % 10;
				flag = 1;
			}
			else{
				arr[i] = t;
			}
			i++;
			k = k / 10;
		}
	}
	if (numSize>0){
		while (numSize--){
			t = (*num) % 10 + flag;
			flag = 0;
			if (t >= 10){
				arr[i] = t % 10;
				flag = 1;
			}
			else{
				arr[i] = t;
			}
			i++;
			num--;
		}
	}
	if (flag){
		arr[i] = 1;
		i++;
	}
	retS = i;
	j = 0;
	i--;
	while (j <= i){
		int t = arr[j];
		arr[j] = arr[i];
		arr[i] = t;
		j++;
		i--;
	}
	*returnSize = retS;
	return arr;
}