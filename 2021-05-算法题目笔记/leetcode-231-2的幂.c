#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>

/*
����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���
*/

bool isPowerOfTwo(int n){
	if (n <= 0){
		return false;
	}
	/*�������
	int ret = n;
	bool flag=false;
	while(ret <= n){
	if(ret == n){
	flag = true;
	break;
	}
	ret = ret * 2;
	}
	return flag;
	*/
	int ret = 1, i = 0;
	bool flag = false;
	//��1���ƣ����ƺ���n�Ƚϣ�����ȣ�����2��i����
	while (i < 31){
		if (ret << i == n){
			flag = true;
			break;
		}
		i++;
	}
	return flag;
}