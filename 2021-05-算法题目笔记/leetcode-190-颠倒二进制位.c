#define _CRT_SECURE_NO_WARNINGS 1
#define uint32_t unsigned int
/*
颠倒给定的 32 位无符号整数的二进制位。
输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。

来源：力扣（LeetCode）
*/
uint32_t reverseBits(uint32_t n) {
	int arr[32] = { 0 };
	int i = 0;
	//反转并存入数组
	while (i < 32){
		arr[i] = (n >> i) & 1;
		i++;
	}

	i = 0;

	//还原数字
	uint32_t ret = 2;
	while (i < 32){
		//左移
		ret = ret << 1;
		ret = ret | arr[i];
		i++;
	}
	return ret;
}