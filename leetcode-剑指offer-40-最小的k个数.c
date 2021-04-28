#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
������������ arr ���ҳ�������С�� k ������
���磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
*/


//���µ���
void adjustDown(int* a, int len, int start){
	if (a == NULL || len<0){
		exit(-1);
	}
	int parent = start;
	int child = parent * 2 + 1;
	while (child < len){
		if (child + 1 < len && a[child + 1] >a[child]){
			child++;
		}
		if (a[child]> a[parent]){
			//����
			int t = a[child];
			a[child] = a[parent];
			a[parent] = t;

			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	if (k <= 0){
		*returnSize = 0;
		return NULL;
	}
	int* ret = (int*)malloc(sizeof(int)*k);

	for (int i = 0; i<k; i++){
		ret[i] = arr[i];
	}
	//����
	for (int i = (k - 2) / 2; i >= 0; i--){
		adjustDown(ret, k, i);
	}
	int i = k;
	//�Ա�
	while (i < arrSize){
		if (ret[0]>arr[i]){
			ret[0] = arr[i];
			adjustDown(ret, k, 0);
		}
		i++;
	}
	*returnSize = k;
	return ret;
}