#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*����һ�������� n �����������еĵ� n �

��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������

����Խ����������ɵݹ鹫ʽ����������ַ������У�

countAndSay(1) = "1"
countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/count-and-say
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/

char * countAndSay(int n){
	/*��1��nֱ��ѭ����*/

	//t��ŵ��α�ͳ�ƺõ��ַ���
	char* t = (char*)malloc(sizeof(char)* 5000);


	char* ret = (char*)malloc(sizeof(char)* 5000);

	/*��ret�������ʼ�ַ���*/
	ret[0] = '1';
	ret[1] = '\0';
	int i = 1;
	while (i<n){
		//����ָ��ָ���ַ���
		char* tt = ret;
		//����j��¼����t�е�λ��
		int j = 0;
		//��ret�зŵ��ַ���δ���ַ���ĩβ����ִ��ѭ��
		while (*tt != '\0'){
			int count = 1;
			//key��¼��ǰ���ַ���count��¼���ִ���
			char key = *tt;
			//tt����ָ����*tt==key������ִ���+1��
			while (*(++tt) == key){
				count++;
			}
			//��д���������д���ַ�
			t[j++] = count + '0';
			t[j++] = key;
		}
		//�ֶ����Ͻ�β
		t[j] = '\0';
		//д��ret�����ȥ
		strcpy(ret, t);
		i++;
	}
	free(t);
	return ret;
}