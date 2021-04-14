#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct Node* copyRandomList(struct Node* head) {
	/*先赋值每个结点，插入原链表，然后依次赋值对应的random，再断裂链接形成原链表和新链表*/
	if (head == NULL){
		return NULL;
	}
	//1.赋值每个结点，并插入原链表，每个新节点在复制对象的后面
	struct Node* copy, *cur, *next;
	cur = head;
	while (cur){
		copy = (struct Node*)malloc(sizeof(struct Node));
		copy->val = cur->val;

		copy->next = cur->next;
		next = cur->next;
		cur->next = copy;

		cur = next;
	}

	//2.赋值randow给复制的结点
	cur = head;
	while (cur){
		copy = cur->next;
		if (cur->random == NULL){
			copy->random = NULL;
		}
		else{
			copy->random = cur->random->next;
		}
		cur = copy->next;
	}

	//3.分割链表
	struct Node* copyHead;
	copyHead = head->next;
	cur = head;
	copy = copyHead;
	while (copy && copy->next){
		cur->next = copy->next;
		cur = copy->next;
		copy->next = cur->next;
		copy = copy->next;
	}
	return copyHead;
}