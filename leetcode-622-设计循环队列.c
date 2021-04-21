#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
/*
������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������

ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

���ʵ��Ӧ��֧�����²�����

MyCircularQueue(k): �����������ö��г���Ϊ k ��
Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
isFull(): ���ѭ�������Ƿ�������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/design-circular-queue
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
typedef struct {
	int k;
	int front;
	int rear;
	int *arr;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* t = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	t->k = k;
	t->front = t->rear = 0;
	t->arr = (int*)malloc(sizeof(int)*(k + 1));//������һ��λ�ò������ݣ��������
	return t;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->front == obj->rear){
		return true;
	}
	return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj == NULL){
		return false;
	}
	if ((obj->rear + 1) % (obj->k + 1) == obj->front){
		return true;
	}

	return false;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj)){
		return false;
	}
	else{
		obj->arr[obj->rear] = value;
		obj->rear = (obj->rear + 1) % (obj->k + 1);
	}
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)){
		return false;
	}
	else{
		obj->front = (obj->front + 1) % (obj->k + 1);
	}
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	return obj->arr[obj->front];
}


int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	int prev;
	if (obj->rear == 0){
		prev = obj->k;
	}
	else{
		prev = obj->rear - 1;
	}
	return obj->arr[prev];
}



void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);
}
