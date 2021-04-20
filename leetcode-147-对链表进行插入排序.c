#define _CRT_SECURE_NO_WARNINGS 1

#include"ListNode.h"
/*
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/insertion-sort-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL){
		return NULL;
	}
	struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
	guard->next = head;
	//用tail记录已经排过序的末尾，next是未排序组的第一个,cur是已排序组的第一个，往后迭代
	struct ListNode* tail = head, *cur, *next;
	next = tail->next;
	while (next != NULL){
		cur = guard->next;
		struct ListNode* prev = guard;
		next = tail->next;
		while (cur != next && next != NULL){
			if (cur->val >= next->val){
				struct ListNode* locate = next;
				if (locate->next == NULL){
					tail->next = NULL;
				}
				//将next插入cur的前面
				prev->next = locate;
				//尾部与next的后面建立连接
				tail->next = locate->next;
				//正在被排序的元素后面连接cur
				locate->next = cur;

				break;
			}
			else{
				cur = cur->next;
				prev = prev->next;
			}
		}
		//若cur与next相遇，则说明前面都不符合,直接将尾部+1；
		if (cur == next){
			next = next->next;
			tail = tail->next;
		}
	}
	head = guard->next;
	free(guard);
	return head;
}