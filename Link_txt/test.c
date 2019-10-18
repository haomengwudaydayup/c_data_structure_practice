/*
  test测区
*/

#include"contact.h"

void test_Stack()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 4);
	StackPush(&ps, 5);
	StackPush(&ps, 6);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackPop(&ps);
	printf("%d\n", StackTop(&ps));
	StackDestory(&ps);
}

int main()
{
	test_Stack();
	system("pause");
	return 0;
}
