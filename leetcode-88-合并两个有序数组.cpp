#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

/*给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if (nums1 == NULL || nums2 == NULL || 0 == n){
		return;
	}
	int i, j, k;
	i = m;
	j = n;
	k = 0;
	/*直接覆盖到第一个数组后面*/
	while (j){
		nums1[i] = nums2[k];
		i++; k++; j--;
	}
	/*冒泡排序*/
	for (i = 0; i<n + m; i++){
		for (j = 1; j<n + m - i; j++){
			if (nums1[j - 1]>nums1[j]){
				k = nums1[j];
				nums1[j] = nums1[j - 1];
				nums1[j - 1] = k;
			}
		}
	}
}