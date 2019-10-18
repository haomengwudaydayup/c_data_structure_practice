#pragma once

/*
	循环队列的实现需要头节点， 方便设计和控制.
*/

#include<stdio.h>
#include<stdlib.h>
#include<vld.h>

#define N 5 // 循环队列的存储个数
typedef int DataType;


//循环队列 -- 线性表实现
typedef struct RNode
{
	DataType *_data;
	int _front;
	int _rear;
}RQueue;

void RQueueInit(RQueue *qu);
void RQueueDestroy(RQueue *qu);
void RQueuePush(RQueue *qu, DataType x);
void RQueuePop(RQueue *qu);
void RQueuePrint(RQueue *qu);	//打印
