#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
struct Node* deleteDuplication(struct Node* pHead) {
	if (pHead == NULL){
		return NULL;
	}
	int count = 0;
	struct Node* cur = pHead;

	//计算链表长度
	while (cur){
		count++;
		cur = cur->next;
	}

	//建立辅助数组
	int *arr = (int*)malloc(sizeof(int)*count);
	int i = 0;
	cur = pHead;
	while (count--){
		arr[i++] = cur->val;
		cur = cur->next;
	}
	count = i;
	//对数组内的元素去除重复的结点值
	int front = 0, end = 1;
	while (end <= count){
		//小细节：<=否则当链表结点val都相同时，会留下一个元素
		if (arr[end] == arr[front]){
			for (int j = end + 1; j<count; j++){
				//若end=1，count=1,则arr[0]=arr[2]，并不会把arr[1]赋给arr[0]
				//但此时只有一个有效元素，所以当链表是1 2 2 3 3 4 4这种情况时，此时依然不会造成
				//arr[0]=arr[2]，因为 1 4 4 4 4 4 4 下标2不会赋给下标0
				//总结，若只有一个有效元素时，此方法并不会出错，因为后面的
				//元素都被覆盖了，要么与arr[0]相同，则删除，不同，则不会进入循环

				arr[j - 2] = arr[j];
			}
			count -= 2;
			end--; front--;
		}
		end++;
		front++;
	}
	//对比数组与链表的值，若存在数组之中，则尾插连接
	struct Node* guard = (struct Node*)malloc(sizeof(struct Node));
	struct Node* guardTail = guard;
	cur = pHead;

	i = 0;
	//若数组有效长度为0，则直接返回NULL；
	if (count <= 0){
		return NULL;
	}
	while (cur && count){
		struct Node* t = NULL;
		if (cur->val == arr[i]){

			guardTail->next = cur;
			guardTail = guardTail->next;
			i++;
			count--;
		}
		else{
			t = cur;
		}
		cur = cur->next;
		//释放不在数组内的元素
		//free(t);
		//t = NULL;
	}
	guardTail->next = NULL;
	cur = guard;
	guard = guard->next;
	free(cur);
	return guard;
}