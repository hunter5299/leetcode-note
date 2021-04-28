#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
*/


//向下调整
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
			//交换
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
	//建堆
	for (int i = (k - 2) / 2; i >= 0; i--){
		adjustDown(ret, k, i);
	}
	int i = k;
	//对比
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