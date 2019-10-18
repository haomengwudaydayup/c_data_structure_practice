#include"contact.h"

//队列的初始化， 切记： 链表实现
void QueueInit(Queue* pq)
{
	if (!pq)
		return;
	pq->front = pq->rear = NULL;	//头结点都不会在初始化开辟空间
	pq->lengh = 0;
}

//队列的销毁
void QueueDestory(Queue* pq)
{
	if (!pq)
		return;
	if (pq->front == NULL)
		return;
	else
	{
		while (pq->front != NULL)
		{
			QueueNode *p = pq->front->_next;
			free(pq->front);
			pq->front = p;
		}
	}
}

//构建节点
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *pq = (QueueNode *)malloc(sizeof(QueueNode));
	if (!pq)
		exit(0);

	pq->_data = x;
	pq->_next = NULL;
	return pq;
}

//队列的入队操作
void QueuePush(Queue* pq, QUDataType x)
{
	if (!pq)
		return;

	if (pq->front == NULL)
	{
		pq->front = pq->rear = BuyQueueNode(x);
		++pq->lengh;
	}
	else
	{
		pq->rear->_next = BuyQueueNode(x);
		pq->rear = pq->rear->_next;
		++pq->lengh;
	}
}

//队列的出队操作
void QueuePop(Queue* pq)
{
	if (!pq)
		return;

	if (pq->front == NULL)		//队空
	{
		return;
	}
	else
	{
		QueueNode *p = pq->front->_next;
		free(pq->front);
		pq->front = p;
		if (pq->front == NULL)
			pq->rear = NULL;	//最后一个元素删除，rear也要进行操作！
	}
}

//返回队头元素
QUDataType QueueFront(Queue* pq) 
{
	if (!pq)
		return;

	if (pq->front != NULL)
		return pq->front->_data;
	else
		return -1;
}

//返回队尾元素
QUDataType QueueBack(Queue* pq)
{
	if (!pq)
		return;
	if (pq->rear != NULL)
		return pq->rear->_data;
	else
		return -1;
}
//判断队列是否为空
int QueueEmpty(Queue* pq)
{
	if (!pq)
		return;
	if (pq->front == NULL)
		return 0;
	else
		return 1;
}

//队列的长度
int QueueSize(Queue* pq)
{
	return pq->lengh;
}

