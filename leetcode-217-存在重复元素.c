#define _CRT_SECURE_NO_WARNINGS 1
/*
给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
*/
#include<stdbool.h>
void HeapSort(int* a, int n){
	//1.建堆,从最后一个非叶子节点开始调整，往上依次向下调整
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(a, n, i);
	}
	//2. 堆排序，将根与最后一个叶子节点交换，此节点不参与后面的调整，排序完成
	int end = n - 1;
	while (end >= 0){
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void Swap(int* a, int*b){
	assert(a || b);
	int t = *a;
	*a = *b;
	*b = t;
}


//向下调整，删除与排序是调用
void AdjustDown(int* a, int n, int start){
	assert(a || n < 0 || start < 0 || start >= n);
	int parent = start;
	int child = parent * 2 + 1;
	while (child < n){
		//右子大于左子，大根堆
		if (child + 1 < n && a[child + 1] > a[child]){
			child++;
		}
		//若根 小于 子，则交换,否则已经是堆，跳出循环
		if (a[child] > a[parent]){
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
///若直接对比，则需要n平方的时间复杂度，不符合
//1.先用nlogn的排序法对数组排序，然后再对比相邻的元素
bool containsDuplicate(int* nums, int numsSize) {
	HeapSort(nums, numsSize);

	for (int i = 0; i<numsSize; i++){
		if (i + 1<numsSize && nums[i] == nums[i + 1]){
			return true;
		}
	}
	return false;
}