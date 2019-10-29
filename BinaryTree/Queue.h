#pragma once
#include"BTNodeTree.h"


//队列接口 -- 为方便以后调用方便所开辟设计的
/*
	采用不带头链表节点实现的
	接
*/

typedef BTNode* QDataType;

typedef struct QueueNode
{
	QDataType _data;		//数据域
	struct QueueNode* _next;	//指针域
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
	size_t _size;
}Queue;

//队列初始化
void QueueInit(Queue* q);
//队列销毁
void QueueDestroy(Queue* q);
//入队
void QueuePush(Queue* q, QDataType x);
//出队
void QueuePop(Queue* q);
//队头元素
QDataType QueueFront(Queue* q);
//队列为空
int QueueEmpty(Queue* q);

//队列长度
int QueueSize(Queue* q);

