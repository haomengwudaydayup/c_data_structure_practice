#include"contact.h"


void test_RQueue()
{
	RQueue qu;
	RQueueInit(&qu);
	

	RQueuePush(&qu, 1);
	RQueuePush(&qu, 2);
	RQueuePush(&qu, 3);
	RQueuePush(&qu, 4);
	RQueuePush(&qu, 5);
	RQueuePrint(&qu);
	RQueuePop(&qu);
	RQueuePrint(&qu);
	RQueuePop(&qu);
	RQueuePrint(&qu);
	RQueuePop(&qu);
	RQueuePrint(&qu);
	RQueuePop(&qu);
	RQueuePrint(&qu);
	RQueuePop(&qu);
	RQueuePrint(&qu);
	RQueuePop(&qu);
	RQueuePrint(&qu);


	RQueueDestroy(&qu);
}

int main()
{

	test_RQueue();
	system("pause");
	return 0;
}
