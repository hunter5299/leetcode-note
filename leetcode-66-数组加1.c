#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/plus-one
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include"ListNode.h"
int* plusOne(int* digits, int digitsSize, int* returnSize){
	if (digits == NULL){
		return NULL;
	}
	//flagΪ��λ��־��tΪ��ʱ������iΪ�����±�
	int flag = 0, t = 0, i = 0;
	int* arr = (int*)malloc(sizeof(int)*(digitsSize + 1));

	//�Ƚ�ĩβԪ�ؼ�һ�������ĿҪ��
	digits[digitsSize - 1] += 1;

	//������ÿ��Ԫ����ֲ��������
	for (i = digitsSize - 1; i >= 0; i--){
		t = digits[i] + flag;
		flag = 0;

		//��t>=10�����λ
		if (t >= 10){
			flag = 1;
			t = t % 10;
		}
		arr[i] = t;
	}

	//���������λ�����ֲ��flagΪ�����λ�������ν�Ԫ�������ƶ�һλ�����λ��1
	if (i<0 && flag){
		for (int j = digitsSize; j>0; j--){
			arr[j] = arr[j - 1];
		}
		arr[0] = 1;
	}
	*returnSize = digitsSize + flag;
	return arr;
}