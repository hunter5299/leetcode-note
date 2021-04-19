#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>


/*
�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨ���е�ȫ�����ֲ�����push��top��pop �� empty����

ʵ�� MyStack �ࣺ

void push(int x) ��Ԫ�� x ѹ��ջ����
int pop() �Ƴ�������ջ��Ԫ�ء�
int top() ����ջ��Ԫ�ء�
boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-stack-using-queues
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	//����ջ���ڴ�
	MyStack* newms = (MyStack*)malloc(sizeof(MyStack));
	//ջ�ڱ���������ָ�룬�ֱ�ά����������
	newms->q1 = (Que*)malloc(sizeof(Que));
	newms->q2 = (Que*)malloc(sizeof(Que));
	//���еĳ�ʼ��
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
	//ѡ����Ԫ�صĶ���ӣ��������Ӷ�û��Ԫ�أ������q2
	//���q2
	if (obj->q1->front == NULL){
		//��q2��������Ԫ�����ͷ��β ��ָ����Ԫ��
		if (obj->q2->front == NULL){
			obj->q2->front = obj->q2->rear = newnode;
		}
		else{
			obj->q2->rear->next = newnode;
			obj->q2->rear = newnode;
		}
	}
	//���q1
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
	//������q1����Ԫ�أ������Ԫ����ջ��q1,q2�ǿ�
	if (obj->q1->front != NULL){
		//ת��q1�е�Ԫ�ص�q2��ֱ��ֻʣ��q2�Ķ�β
		while (obj->q1->front != obj->q1->rear){
			//��q2����Ԫ�أ���q2�Ķ�ͷ��βָ��ͬһ�����
			if (obj->q2->front == NULL){
				obj->q2->front = obj->q2->rear = obj->q1->front;
				//q1��ͷ����
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
	//����
	else {
		//ת��q2�е�Ԫ�ص�q1��ֱ��ֻʣ��q2�Ķ�β
		while (obj->q2->front != obj->q2->rear){
			//��q1����Ԫ�أ���q1�Ķ�ͷ��βָ��ͬһ�����
			if (obj->q1->front == NULL){
				obj->q1->front = obj->q1->rear = obj->q2->front;
				//q2��ͷ����
				obj->q2->front = obj->q2->front->next;

				obj->q1->rear->next = NULL;
			}
			else if (obj->q1->rear != NULL){
				obj->q1->rear->next = obj->q2->front;
				//q1��β����
				obj->q1->rear = obj->q1->rear->next;
				//q2��ͷ����
				obj->q2->front = obj->q2->front->next;

				obj->q1->rear->next = NULL;
			}
		}

		//�������һ��Ԫ�ص�ֵ����ջ
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