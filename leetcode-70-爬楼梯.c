#define _CRT_SECURE_NO_WARNINGS 1
/*
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
*/
int climbStairs(int n){
	//쳲�������������,�ݹ����׶�ջ�����ʹ�õ���

	int f1 = 0, f2 = 1;
	int f3 = 0;
	while (n--){
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}