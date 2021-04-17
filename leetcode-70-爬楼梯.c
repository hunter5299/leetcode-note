#define _CRT_SECURE_NO_WARNINGS 1
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/
int climbStairs(int n){
	//斐波那契数列问题,递归容易堆栈溢出，使用迭代

	int f1 = 0, f2 = 1;
	int f3 = 0;
	while (n--){
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}