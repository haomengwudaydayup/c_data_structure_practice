#pragma once
/*
    队列的实现，不带头
*/
#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
typedef int QUDataType;

//队列 ，， 采用链表实现队列, 不带头
typedef struct QueueNode
{
	QUDataType _data;
	
	struct Queue *_next;
}QueueNode;

//再创建两个结构体指针 front, rear， 进行操作！
typedef struct Queue
{
	QueueNode *front;
	QueueNode *rear;
	size_t lengh;
}Queue;

void QueueInit(Queue* pq);		//队列的初始化
void QueueDestory(Queue* pq);	//队列的销毁
QueueNode* BuyQueueNode(QUDataType x);		//构建节点
void QueuePush(Queue* pq, QUDataType x);	//队列的插入操作
void QueuePop(Queue* pq);		//队列的删除操作
QUDataType QueueFront(Queue* pq);	//返回队头元素	
QUDataType QueueBack(Queue* pq);	//返回队尾元素
int QueueEmpty(Queue* pq);		//判断队列是否为空
