#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>

/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/

bool isPowerOfTwo(int n){
	if (n <= 0){
		return false;
	}
	/*数据溢出
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
	//用1左移，左移后与n比较，若相等，则是2的i次幂
	while (i < 31){
		if (ret << i == n){
			flag = true;
			break;
		}
		i++;
	}
	return flag;
}