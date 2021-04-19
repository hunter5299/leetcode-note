#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
/*
全字母句 指包含英语字母表中每个字母至少一次的句子。

给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。

如果是，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-the-sentence-is-pangram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//暴力法
bool checkIfPangram(char * sentence){
	char i = 'a';
	//从a到z依次匹配字符串中是否包含
	while (i <= 'z'){
		char *head = sentence;
		while (head < sentence + strlen(sentence)){
			if (*head == i){
				break;
			}
			else{
				head++;
			}
		}
		//若循环到尾也没有匹配，则不是全字母句
		if (head >= sentence + strlen(sentence)){
			return false;
		}
		i++;
	}
	return true;
}

//
//数组法
bool checkIfPangram(char * sentence){
	int arr[26] = { 0 };
	char* head = sentence;
	char* end = sentence + strlen(sentence);
	int ret = 0;
	//*head-'a'是数组下标，若此字母顺序存在，则置为1；
	for (int i = 0; head < end; i++){
		arr[*head - 'a'] = 1;
		head++;
	}
	/*对比数组中的所有元素，若是1，则存在*/
	for (int i = 0; i<26; i++){
		//统计句子中的'a'-'z'各字母是否出现，若出现则++
		if (arr[i]>0){
			ret++;
		}
	}
	//若ret=26，则所有字母都包含再其中
	return ret == 26;
}