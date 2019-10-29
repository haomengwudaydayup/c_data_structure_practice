#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//#include<vld.h>

/*	
	树的实现
*/

typedef char BTNDataType;

typedef struct BTNode
{
	BTNDataType val;				//数据域
	struct BTNode* _lchild;			//左孩子节点
	struct BTNode* _rchild;			//右孩子节点
}BTNode;

//初始化创建树
BTNode* BTNodeInit(BTNDataType* a, int* pi);
//树的销毁
void BTNodeDestroy(BTNode** root);
//先序遍历
void BinaryTreePrevOrder(BTNode* root);
//中序遍历
void BinaryTreeInOrder(BTNode* root);
//后序遍历
void BinaryTreePostOrder(BTNode* root);
//镜像转化
void MirrorRecursively(BTNode* root);
//判断是否为对称二叉树
int isSameTree(BTNode* root);
// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root);
//树的节点个数
int BinaryTreeSize(BTNode* root); 
//树的叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
//第k层节点的个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//第k层节点的叶子个数
int BinaryTreeLevelKLeafSize(BTNode* root, int k);
//返回查找的节点的值
BTNode* BinaryTreeFind(BTNode* root, BTNDataType x);
//层序遍历
void BinaryTreeLevelOrder(BTNode* root);
//非递归实现的先序遍历
void BinaryTreePrevOrderNonR(BTNode* root);
//非递归实现的中序遍历
void BinaryTreeInOrderNonR(BTNode* root);
//非递归实现的后序遍历
void BinaryTreePostOrderNonR(BTNode* root);
