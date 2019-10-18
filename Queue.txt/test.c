#include"contact.h"


void testQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	QueuePush(&pq, 6);
	QueuePush(&pq, 7);

	printf("%d\n", QueueFront(&pq));
	printf("%d\n", QueueBack(&pq));
	QueueDestory(&pq);

}


int main()
{
	testQueue();
	system("pause");
	return 0;
}
