#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*67���������*/
char * addBinary(char * a, char * b){
	if (a == NULL || b == NULL){
		return NULL;
	}
	int t = 0;
	int alen = strlen(a);
	int blen = strlen(b);
	int i = 0;//�����±�
	int flag = 0;//��λ��־
	char* arr = (char*)malloc(sizeof(char)*(alen + blen+1));
	//�ַ���aÿ���ַ���ջ
	while (*a != '\0'){
		a++;
	}
	a--;
	//�ַ���bÿ���ַ���ջ
	while (*b != '\0'){
		b++;
	}
	b--;
	//��ջ����
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

	
	//��ת'\0'֮ǰ���ַ���
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
/*989������ʽ�������ӷ�*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
	int flag = 0;
	int t = 0;
	int i, j;
	//��������Ŀռ��С����numsizeΪ1����k��һ������ֵʱ����ô���벻��ȫ
	int* arr = (int*)malloc(sizeof(int)*(numSize + 200));
	int retS = 0;
	//num��ջ
	i = numSize;
	while (i){
		num++;
		i--;
	}
	num--;
	i = 0;
	//k��ջͬʱ��num����
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
	//���ӦΪ11110
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