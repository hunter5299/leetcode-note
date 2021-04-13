#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"
using namespace std;

/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:

	//此代码解法没有考虑数据的溢出，对于大数值不能适用
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		long int a = 0, b = 0;
		int count, pow, ret;

		//还原链表l1表示的数字
		count = 0;
		while (l1){
			//恢复当前节点数字的权重
			pow = 1;
			for (int i = 0; i < count; i++){
				pow *= 10;
			}
			//还原当前节点数字及低位数字的值
			a = a + ((l1->val)*pow);
			count++;
			l1 = l1->next;
		}
		//还原链表l2表示的数字
		count = 0;
		while (l2){
			pow = 1;
			for (int i = 0; i < count; i++){
				pow *= 10;
			}
			b = b + ((l2->val)*pow);
			count++;
			l2 = l2->next;
		}
		//数字相加
		ret = a + b;

		//建立新链表，并存储对应节点数字
		ListNode *result = nullptr;
		ListNode *temp = nullptr;
		//若ret为0，说明两列表存储数值都为0
		if (!ret){
			temp = new ListNode(ret);
			return temp;
		}
		while (ret){
			if (!result){
				result = new ListNode(ret % 10);
				temp = result;
			}
			else{
				result->next = new ListNode(ret % 10);
				result = result->next;
			}
			ret = ret / 10;
		}
		return temp;
	}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *result = new ListNode(-1);
		ListNode *temp = result;
		int sum;
		bool pow = false;
		while (l1 || l2){
			sum = 0;
			if (l1){
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2){
				sum += l2->val;
				l2 = l2->next;
			}
			if (pow){
				sum++;
			}
			temp->next = new ListNode(sum % 10);
			temp = temp->next;
			pow = sum >= 10 ? true : false;

		}
		if (pow){
			temp->next = new ListNode(1);
		}

		//释放第一个内存空间
		temp = result;
		result = temp->next;
		delete temp;
		return result;
	}
};