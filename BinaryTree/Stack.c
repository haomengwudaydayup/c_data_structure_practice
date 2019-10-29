#include"Stack.h"


//初始化栈
void StackInit(Stack* s)
{
	if (!s)
		return;
	s->_data = NULL;	//初始化为空
	s->_memory = s->_size = 0;	//初始化为0
}

//栈插入
void StackPush(Stack* s, SDataType x)
{
	if (!s)
		return;

	if (StackOver(s))	//栈满
	{
		int nums = s->_data == NULL ? 10 : (2 * s->_memory);
		SDataType* p = (int*)realloc(s->_data, sizeof(SDataType) * nums);
		if (!p)
		{
			printf("开辟空间失败！\n");
			exit(0);
		}
		s->_data = p;
		s->_memory = nums;
	}
	s->_data[s->_size++] = x;
}

//栈删除
void StackPop(Stack* s)
{
	if (!s)
		return;
	if (!StackEmpty(s))
	{
		--s->_size;
	}
	else
		printf("栈空！\n");
}

//栈顶元素
SDataType StackTop(Stack* s)
{
	if (!StackEmpty(s))
	{
		return s->_data[s->_size - 1];
	}
	return -3;
}

//栈大小
int StackSize(Stack* s)
{
	return s->_size;
}

//判断栈是否为空
int StackEmpty(Stack* s)
{

	if (s->_size == 0)
		return 1;
	return 0;
}

//判断栈满
int StackOver(Stack* s)
{
	if (s->_memory == s->_size)
		return 1;
	return 0;
}

//栈销毁
void StackDestroy(Stack* s)
{
	if (s->_data)
	{
		free(s->_data);
		s->_data = NULL;
	}
}
