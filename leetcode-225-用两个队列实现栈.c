#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>


/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
typedef struct QNode{
	int val;
	struct QNode* next;
}QNode;
typedef struct {
	QNode* front;
	QNode* rear;
}Que;

typedef struct {
	Que *q1;
	Que *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate(){
	//申请栈的内存
	MyStack* newms = (MyStack*)malloc(sizeof(MyStack));
	//栈内保存了两个指针，分别维护两个队列
	newms->q1 = (Que*)malloc(sizeof(Que));
	newms->q2 = (Que*)malloc(sizeof(Que));
	//队列的初始化
	newms->q1->front = newms->q1->rear = NULL;
	newms->q2->front = newms->q2->rear = NULL;
	return newms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if ((obj == NULL) || (obj->q1 == NULL) || (obj->q2 == NULL)){
		return;
	}
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->next = NULL;
	newnode->val = x;
	//选择有元素的队入队，若两个队都没有元素，则入队q2
	//入队q2
	if (obj->q1->front == NULL){
		//若q2队列中无元素则队头队尾 都指向新元素
		if (obj->q2->front == NULL){
			obj->q2->front = obj->q2->rear = newnode;
		}
		else{
			obj->q2->rear->next = newnode;
			obj->q2->rear = newnode;
		}
	}
	//入队q1
	else{
		obj->q1->rear->next = newnode;
		obj->q1->rear = newnode;
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	if ((obj == NULL) || (obj->q1 == NULL) || (obj->q2 == NULL)){
		exit(-1);
	}
	int ret;
	//若队列q1中有元素，则表明元素入栈在q1,q2是空
	if (obj->q1->front != NULL){
		//转移q1中的元素到q2，直到只剩下q2的队尾
		while (obj->q1->front != obj->q1->rear){
			//若q2中无元素，则q2的队头队尾指向同一个结点
			if (obj->q2->front == NULL){
				obj->q2->front = obj->q2->rear = obj->q1->front;
				//q1队头迭代
				obj->q1->front = obj->q1->front->next;
				obj->q2->rear->next = NULL;
			}
			else{
				obj->q2->rear->next = obj->q2->front;


				obj->q2->front = obj->q2->front->next;
				obj->q2->rear = obj->q2->rear->next;

				obj->q2->rear->next = NULL;
			}
		}
		ret = obj->q1->front->val;
		free(obj->q1->front);
		obj->q1->front = obj->q1->rear = NULL;
	}
	//否则
	else {
		//转移q2中的元素到q1，直到只剩下q2的队尾
		while (obj->q2->front != obj->q2->rear){
			//若q1中无元素，则q1的队头队尾指向同一个结点
			if (obj->q1->front == NULL){
				obj->q1->front = obj->q1->rear = obj->q2->front;
				//q2队头迭代
				obj->q2->front = obj->q2->front->next;

				obj->q1->rear->next = NULL;
			}
			else if (obj->q1->rear != NULL){
				obj->q1->rear->next = obj->q2->front;
				//q1队尾迭代
				obj->q1->rear = obj->q1->rear->next;
				//q2队头迭代
				obj->q2->front = obj->q2->front->next;

				obj->q1->rear->next = NULL;
			}
		}

		//返回最后一个元素的值，出栈
		ret = obj->q2->front->val;
		free(obj->q2->front);
		obj->q2->front = obj->q2->rear = NULL;
	}
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (obj == NULL){
		exit(-1);
	}
	QNode* cur;
	int ret;
	if (obj->q1->front != NULL){
		cur = obj->q1->front;
		while (cur != obj->q1->rear){
			cur = cur->next;
		}
		ret = cur->val;
	}
	else{
		cur = obj->q2->front;
		while (cur != obj->q2->rear){
			cur = cur->next;
		}
		ret = cur->val;
	}
	return ret;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (obj == NULL){
		return true;
	}
	return (obj->q1->front == NULL) && (obj->q2->front == NULL) ? true : false;
}

void myStackFree(MyStack* obj) {
	if (obj == NULL){
		return;
	}
	while (obj->q1->front){
		QNode* del = obj->q1->front;
		obj->q1->front = obj->q1->front->next;
		free(del);
	}
	obj->q1->front = obj->q1->rear = NULL;

	while (obj->q2->front){
		QNode* del = obj->q2->front;
		obj->q2->front = obj->q2->front->next;
		free(del);
	}
	obj->q2->front = obj->q2->rear = NULL;
	free(obj);
}