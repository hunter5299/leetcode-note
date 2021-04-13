#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*989数组形式的整数加法*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	int flag = 0;
	int t = 0;
	int i, j;
	//对于申请的空间大小，若numsize为1，而k是一个极大值时，这么申请不安全
	int* arr = (int*)malloc(sizeof(int)*(numSize + 200));
	int retS = 0;
	//num入栈
	i = numSize;
	while (i){
		num++;
		i--;
	}
	num--;
	i = 0;
	//k入栈同时与num计算
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