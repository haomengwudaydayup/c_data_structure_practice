#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
typedef char BTDataType;

typedef struct BinartTree
{
	BTDataType val;
	struct BinartTree* left;
	struct BinartTree* right;
}BinaryTree;


BinaryTree* BinaryTreeInit(BTDataType* str, int* pi);
void BinaryTreeDestroy(BinaryTree* root);
void BinaryTreePrevOrder(BinaryTree* root);

void StringBuild(BinaryTree* root, BTDataType* str1, int* pi);
