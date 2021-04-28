#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
*/
#include<stdbool.h>
void HeapSort(int* a, int n){
	//1.����,�����һ����Ҷ�ӽڵ㿪ʼ�����������������µ���
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(a, n, i);
	}
	//2. �����򣬽��������һ��Ҷ�ӽڵ㽻�����˽ڵ㲻�������ĵ������������
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


//���µ�����ɾ���������ǵ���
void AdjustDown(int* a, int n, int start){
	assert(a || n < 0 || start < 0 || start >= n);
	int parent = start;
	int child = parent * 2 + 1;
	while (child < n){
		//���Ӵ������ӣ������
		if (child + 1 < n && a[child + 1] > a[child]){
			child++;
		}
		//���� С�� �ӣ��򽻻�,�����Ѿ��Ƕѣ�����ѭ��
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
///��ֱ�ӶԱȣ�����Ҫnƽ����ʱ�临�Ӷȣ�������
//1.����nlogn�����򷨶���������Ȼ���ٶԱ����ڵ�Ԫ��
bool containsDuplicate(int* nums, int numsSize) {
	HeapSort(nums, numsSize);

	for (int i = 0; i<numsSize; i++){
		if (i + 1<numsSize && nums[i] == nums[i + 1]){
			return true;
		}
	}
	return false;
}