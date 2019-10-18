#include"contact.h"

void RQueueInit(RQueue *qu)
{
	if (!qu)		//刚进来会是随机值
		return;
	//在初始化分配空间内存

	qu->_data = (DataType *)malloc(sizeof(DataType) * (N + 1));	//分配N+1个空间
	if (!qu)
		exit(0);		//分配失败
	qu->_front = qu->_rear = 0;

}

void RQueueDestroy(RQueue *qu)
{
	if (!qu)
		return;

	free(qu->_data);
	qu->_data = NULL;		//规范
}

int RQueueOver(RQueue * qu)
{
	if (!qu)
		exit(0);

	if ((qu->_rear + 1) % (N + 1) == (qu->_front))
		return 1;	//队满
	else
		return 0;
}

void RQueuePush(RQueue *qu, DataType x)
{
	if (!qu)
		return;
	//push， 应注意队满情况

	if (RQueueOver(qu))
	{
		printf("队满啦！\n");
		return;
	}

	qu->_data[qu->_rear++] = x;
	if (qu->_rear == N + 1)
		qu->_rear = 0;
}

int RQueueEmpty(RQueue *qu)
{
	if (!qu)
		return;

	if (qu->_front == qu->_rear)
		return 1;
	else
		return 0;
}

void RQueuePop(RQueue *qu)
{
	if (!qu)
		return;

	if (RQueueEmpty(qu))
	{
		printf("队空!\n");
		return;
	}

	++qu->_front;
	if (qu->_front == N + 1)
		qu->_front = 0;
}

void RQueuePrint(RQueue *qu)
{
	if (!qu)
		return;
	int st = qu->_front;
	while (st != qu->_rear)
	{
		printf("%d ", qu->_data[st++]);
		if (st == N + 1)
			st = 0;
	}
	printf("\n");
}
