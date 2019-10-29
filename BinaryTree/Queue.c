#include"Queue.h"

//队列初始化
void QueueInit(Queue* q)
{
	if (!q)
		return;
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

//队列销毁
void QueueDestroy(Queue* q)
{
	if (!q)
		return;
	if (!QueueEmpty(q))
	{
		QueueNode* p = NULL;
		while (q->_front)
		{
			p = q->_front->_next;
			free(q->_front);
			q->_front = p;
		}
	}
}

//创建节点信息
QueueNode* CreateNode(QDataType x)
{
	QueueNode* p = (QueueNode*)malloc(sizeof(QueueNode));
	p->_data = x;
	p->_next = NULL;
	return p;
}

//入队
void QueuePush(Queue* q, QDataType x)
{
	if (!q)
		return;
	if (QueueEmpty(q))
	{
		q->_front = q->_rear = CreateNode(x);
		++q->_size;
	}
	else
	{
		q->_rear->_next = CreateNode(x);
		q->_rear = q->_rear->_next;
		++q->_size;
	}
}

//出队
void QueuePop(Queue* q)
{
	if (!QueueEmpty(q))
	{
		QueueNode* p = q->_front->_next;
		free(q->_front);
		q->_front = p;
		if (!q->_front)
			q->_rear = NULL;
		--q->_size;
	}
}
//队头元素
QDataType QueueFront(Queue* q)
{
	if (!QueueEmpty(q))
		return q->_front->_data;
	printf("空队！\n");
	return -3;
}

//队列为空
int QueueEmpty(Queue* q)
{
	if (q->_front == NULL)
		return 1;
	return 0;
}

//队列长度
int QueueSize(Queue* q)
{
	return q->_size;
}
