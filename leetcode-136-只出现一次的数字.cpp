#define _CRT_SECURE_NO_WARNINGS 1
/*����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�*/


/*  ��� */
int singleNumber(int* nums, int numsSize){
	int ret = 0;
	for (int i = 0; i<numsSize; i++){
		ret ^= nums[i];
	}
	return ret;
}