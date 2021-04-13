#define _CRT_SECURE_NO_WARNINGS 1

/*����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

����Լ������������ظ�Ԫ�ء�*/


int searchInsert(int* nums, int numsSize, int target){
	/*���Ӷ�Ϊn��������
	if(nums==NULL||numsSize==0){
	return -1;
	}
	int i=0;
	for(i=0;i<numsSize;i++){
	if(nums[i]>=target){
	return i;
	}
	else if((i+1)==numsSize){
	return numsSize;
	}
	}*/
	/*���ֲ��� ʱ�临�Ӷ�logn*/
	int right = numsSize - 1;
	int left = 0;
	int mid;
	int ans = numsSize;
	while (left <= right){
		mid = (right - left) / 2 + left;
		if (nums[mid] >= target){
			ans = mid;
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return ans;
}