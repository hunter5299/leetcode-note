#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int n = 0;
		int i = 0;
		while (i<s.size())
		{
			switch (s[i])
			{
			case 'M':
				n += 1000;
				i++;
				break;
			case 'D':
				n += 500;
				i++;
				break;
			case 'C':
				if (s[i + 1] == 'M')
				{
					n += 900;
					i += 2;
					break;
				}
				else if (s[i + 1] == 'D')
				{
					n += 400;
					i += 2;
					break;
				}
				else
				{
					n += 100;
					i++;
					break;
				}
			case 'L':
				n += 50;
				i++;
				break;
			case 'X':
				if (s[i + 1] == 'C')
				{
					n += 90;
					i += 2;
					break;
				}
				else if (s[i + 1] == 'L')
				{
					n += 40;
					i += 2;
					break;
				}
				else
				{
					n += 10;
					i++;
					break;
				}
			case 'V':
				n += 5;
				i++;
				break;
			case 'I':
				if (s[i + 1] == 'X')
				{
					n += 9;
					i += 2;
					break;
				}
				else if (s[i + 1] == 'V')
				{
					n += 4;
					i += 2;
					break;
				}
				else
				{
					n++;
					i++;
					break;
				}
			}
		}
		return n;
	}
};
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int>mymap = { { "I", 1 }, { "V", 5 }, { "X", 10 }, { "L", 50 },
		{ "C", 100 }, { "D", 500 }, { "M", 1000 } };
		int Firstnum = mymap[s.substr(0, 1)];
		int prenum = Firstnum;
		int sum = 0;
		for (int i = 1; i<s.size(); ++i){
			int num = mymap[s.substr(i, 1)];
			if (prenum < num){
				sum -= prenum;
			}
			if (prenum >= num){
				sum += prenum;
			}
			prenum = num;
		}
		sum += prenum;
		return sum;
	}
};

作者：chao - ji - ha - shi - qi
链接：https ://leetcode-cn.com/problems/roman-to-integer/solution/cli-yong-unorderedmapqiu-jie-by-chao-ji-926cb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。