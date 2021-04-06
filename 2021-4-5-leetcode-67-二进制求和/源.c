#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*67二进制求和*/
char * addBinary(char * a, char * b){
	if (a == NULL || b == NULL){
		return NULL;
	}
	int t = 0;
	int alen = strlen(a);
	int blen = strlen(b);
	int i = 0;//计数下标
	int flag = 0;//进位标志
	char* arr = (char*)malloc(sizeof(char)*(alen + blen+1));
	//字符串a每个字符入栈
	while (*a != '\0'){
		a++;
	}
	a--;
	//字符串b每个字符入栈
	while (*b != '\0'){
		b++;
	}
	b--;
	//出栈运算
	while (alen && blen){
		t = *a - '0' + *b - '0' + flag;
		a--;
		b--;
		flag = 0;
		if (t == 2){
			arr[i] = '0';
			flag = 1;
		}
		else if (t > 2){
			flag = 1;
			arr[i] = '1';
		}
		else{
			arr[i] = '0' + t;
		}
		i++;
		alen--;
		blen--;
	}
	if (alen > 0){
		while (alen--){
			t = *a - '0' + flag;
			a--;
			flag = 0;
			if (t == 2){
				flag = 1;
				arr[i] = '0';
			}
			else{
				arr[i] = '0' + t;
			}
			i++;
		}
	}
	else if (blen > 0){
		while (blen--){
			t = *b - '0' + flag;
			b--;
			flag = 0;
			if (t == 2){
				flag = 1;
				arr[i] = '0';
			}
			else{
				arr[i] = '0' + t;
			}
			i++;
		}
	}
	if (flag){
		arr[i] = '1';
		i++;
	}
	
	arr[i] = '\0';

	
	//翻转'\0'之前的字符串
	i--;
	int j = 0;
	char ta = 0;
	while (i >= j){
		ta = arr[j];
		arr[j] = arr[i];
		arr[i] = ta;
		i--;
		j++;
	}
	return arr;
}
/*989数组形式的整数加法*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	int flag = 0;
	int t = 0;
	int i, j;
	//对于申请的空间大小，若numsize为1，而k是一个极大值时，这么申请不安全
	int* arr = (int*)malloc(sizeof(int)*(numSize + 200));
	int retS = 0;
	//num入栈
	i = numSize;
	while (i){
		num++;
		i--;
	}
	num--;
	i = 0;
	//k入栈同时与num计算
	while (k && numSize){
		t = (*num) + (k % 10) + flag;
		flag = 0;
		if (t >= 10){
			arr[i] = t % 10;
			flag = 1;
		}
		else{
			arr[i] = t;
		}
		i++;
		num--;
		k = k / 10;
		numSize--;
	}
	if (k>0){
		while (k){
			t = k % 10 + flag;
			flag = 0;
			if (t >= 10){
				arr[i] = t % 10;
				flag = 1;
			}
			else{
				arr[i] = t;
			}
			i++;
			k = k / 10;
		}
	}
	if (numSize>0){
		while (numSize--){
			t = (*num) % 10 + flag;
			flag = 0;
			if (t >= 10){
				arr[i] = t % 10;
				flag = 1;
			}
			else{
				arr[i] = t;
			}
			i++;
			num--;
		}
	}
	if (flag){
		arr[i] = 1;
		i++;
	}
	retS = i;
	j = 0;
	i--;
	while (j <= i){
		int t = arr[j];
		arr[j] = arr[i];
		arr[i] = t;
		j++;
		i--;
	}
	*returnSize = retS;
	return arr;
}
void test(){
	char* pa = "100";
	char* pb = "110010";
	//结果应为11110
	char* arr = addBinary(pa, pb);
	printf("%s\n", arr);
	free(arr);
}
void test02(){
	int arr[3] = { 2,1,5 };
	int k = 806;
	int retS = 0;
	int *pret;
	int i = 0;
	pret =  addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), k, &retS);
	while (retS){
		printf("%d\n", pret[i]);
		i++;
		retS--;
	}
}
int main(){
	test02();
	system("pause");
	return 0;
}