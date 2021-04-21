#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
/*
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	t->arr = (int*)malloc(sizeof(int)*(k + 1));//多留出一个位置不存数据，方便操作
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
