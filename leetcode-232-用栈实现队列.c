#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
 

*/


//先实现栈的数据结构
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
typedef struct {
	Stack stPush;
	Stack stPop;
} MyQueue;
void StackInit(Stack* ps){
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 100);
	ps->_top = 0;
	ps->_capacity = 100;
}
//检查容量
void STCapCheck(Stack* ps){
	if (ps->_capacity <= ps->_top){
		int newCap = sizeof(STDataType)* (ps->_capacity + 10);
		ps->_a = (STDataType*)realloc(ps->_a, newCap);
		ps->_capacity = newCap;
	}
}// 入栈 
int StackPush(Stack* ps, STDataType data){
	STCapCheck(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
	return data;
}
// 出栈 
int StackPop(Stack* ps){
	if (StackEmpty(ps)){
		exit(-1);
	}
	int ret = ps->_a[ps->_top - 1];
	ps->_top--;
	return ret;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps){
	if (StackEmpty(ps)){
		exit(-1);
	}
	return ps->_a[ps->_top - 1];
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps){
	return ps->_top == 0 ? 1 : 0;
}
// 销毁栈 
void StackDestroy(Stack* ps){
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}
/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* t = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&t->stPush);
	StackInit(&t->stPop);
	return t;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->stPush, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//若pop栈是空的，则将push栈的数据依次出栈并入栈到pop栈
	if (StackEmpty(&obj->stPop)){
		while (!StackEmpty(&obj->stPush)){
			StackPush(&obj->stPop, StackPop(&obj->stPush));
		}
	}
	//否则直接将pop栈出栈
	return StackPop(&obj->stPop);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	//若pop栈是空的，则将push栈的数据依次出栈并入栈到pop栈
	int ret;
	if (StackEmpty(&obj->stPop)){
		while (!StackEmpty(&obj->stPush)){
			StackPush(&obj->stPop, StackPop(&obj->stPush));
		}
	}
	//否则直接将pop栈出栈
	return StackTop(&obj->stPop);
}


/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->stPop) && StackEmpty(&obj->stPush);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->stPush);
	StackDestroy(&obj->stPop);
	free(obj);
}
