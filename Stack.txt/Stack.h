#pragma once
-------栈接口， 方便调用专门制作--------


#include<stdio.h>
#include<stdlib.h>
//#include<vld.h>

//栈接口 -- 为方便以后调用方便所开辟设计的
/*
	采取线性表实现栈操作。
*/

typedef int SDataType;

typedef struct Stack
{
	SDataType* _data;		//指针
	size_t _size;				//大小
	size_t _memory;		//当前的容量
}Stack;

//初始化栈
void StackInit(Stack* s);
//栈插入
void StackPush(Stack* s, SDataType x);
//栈删除
void StackPop(Stack* s);
//栈顶元素
SDataType StackTop(Stack* s);
//栈大小
int StackSize(Stack* s);
//判断栈是否为空
int StackEmpty(Stack* s);
//判断栈满
int StackOver(Stack* s);
//栈销毁
void StackDestroy(Stack* s);
