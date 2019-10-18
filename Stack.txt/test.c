#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include"Queue.h"

void test_stack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	printf("%d\n", StackTop(&s));
	StackPush(&s, 2);
	printf("%d\n", StackTop(&s));
	StackPush(&s, 3);
	printf("%d\n", StackTop(&s));
	StackPush(&s, 4);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));

	printf("栈长:%d\n", StackSize(&s));

	StackDestroy(&s);
	if (s._data == NULL)
		printf("释放成功!\n");
}

void test_queue()
{
	QueueNode q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueSize(&q));
	QueueDestroy(&q);
	if (q._front == NULL)
		printf("销毁成功！\n");
}

int main()
{
	test_stack();     //栈测试
	//test_queue();   //堆测试
	system("pause");
	return 0;
}
