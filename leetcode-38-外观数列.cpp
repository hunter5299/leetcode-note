#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
/*给定一个正整数 n ，输出外观数列的第 n 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

countAndSay(1) = "1"
countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

char * countAndSay(int n){
	/*从1往n直接循环推*/

	//t存放当次被统计好的字符串
	char* t = (char*)malloc(sizeof(char)* 5000);


	char* ret = (char*)malloc(sizeof(char)* 5000);

	/*往ret中填入初始字符串*/
	ret[0] = '1';
	ret[1] = '\0';
	int i = 1;
	while (i<n){
		//辅助指针指向字符串
		char* tt = ret;
		//变量j记录当次t中的位置
		int j = 0;
		//若ret中放的字符串未到字符串末尾，则执行循环
		while (*tt != '\0'){
			int count = 1;
			//key记录当前的字符，count记录出现次数
			char key = *tt;
			//tt往后指，若*tt==key，则出现次数+1；
			while (*(++tt) == key){
				count++;
			}
			//先写入次数，再写入字符
			t[j++] = count + '0';
			t[j++] = key;
		}
		//手动加上结尾
		t[j] = '\0';
		//写入ret结果中去
		strcpy(ret, t);
		i++;
	}
	free(t);
	return ret;
}