#define _CRT_SECURE_NO_WARNINGS 1
#include"ListNode.h"

/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/
struct Node* deleteDuplication(struct Node* pHead) {
	if (pHead == NULL){
		return NULL;
	}
	int count = 0;
	struct Node* cur = pHead;

	//����������
	while (cur){
		count++;
		cur = cur->next;
	}

	//������������
	int *arr = (int*)malloc(sizeof(int)*count);
	int i = 0;
	cur = pHead;
	while (count--){
		arr[i++] = cur->val;
		cur = cur->next;
	}
	count = i;
	//�������ڵ�Ԫ��ȥ���ظ��Ľ��ֵ
	int front = 0, end = 1;
	while (end <= count){
		//Сϸ�ڣ�<=����������val����ͬʱ��������һ��Ԫ��
		if (arr[end] == arr[front]){
			for (int j = end + 1; j<count; j++){
				//��end=1��count=1,��arr[0]=arr[2]���������arr[1]����arr[0]
				//����ʱֻ��һ����ЧԪ�أ����Ե�������1 2 2 3 3 4 4�������ʱ����ʱ��Ȼ�������
				//arr[0]=arr[2]����Ϊ 1 4 4 4 4 4 4 �±�2���ḳ���±�0
				//�ܽᣬ��ֻ��һ����ЧԪ��ʱ���˷��������������Ϊ�����
				//Ԫ�ض��������ˣ�Ҫô��arr[0]��ͬ����ɾ������ͬ���򲻻����ѭ��

				arr[j - 2] = arr[j];
			}
			count -= 2;
			end--; front--;
		}
		end++;
		front++;
	}
	//�Ա������������ֵ������������֮�У���β������
	struct Node* guard = (struct Node*)malloc(sizeof(struct Node));
	struct Node* guardTail = guard;
	cur = pHead;

	i = 0;
	//��������Ч����Ϊ0����ֱ�ӷ���NULL��
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
		//�ͷŲ��������ڵ�Ԫ��
		//free(t);
		//t = NULL;
	}
	guardTail->next = NULL;
	cur = guard;
	guard = guard->next;
	free(cur);
	return guard;
}