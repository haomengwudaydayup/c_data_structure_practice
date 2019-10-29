//#include"BTNodeTree.h"
#include"Stack.h"
#include"Queue.h"

//初始化创建树
BTNode* BTNodeInit(BTNDataType* a, int* pi)
{
	if (!a)
		return;	

	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->val = a[*pi];
		++(*pi);

		root->_lchild = BTNodeInit(a, pi);
		++(*pi);
		root->_rchild = BTNodeInit(a, pi);


		return root;
	}
	else
		return NULL;
}

//树的销毁
void BTNodeDestroy(BTNode** root)
{
	//树的销毁采用后序遍历的方式释放， 采用二级指针来释放。
	if (*root)
	{
		BTNodeDestroy(&(*root)->_lchild);
		BTNodeDestroy(&(*root)->_rchild);
		free(*root);
		*root = NULL;
	}
	else
		return;
}

//先序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->val);
		BinaryTreePrevOrder(root->_lchild);
		BinaryTreePrevOrder(root->_rchild);
	}
	else
		return;
}
//中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_lchild);
		printf("%c ", root->val);
		BinaryTreeInOrder(root->_rchild);
	}
}

 //后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_lchild);
		BinaryTreePostOrder(root->_rchild);
		printf("%c ", root->val);
	}
}

//非递归实现的先序遍历
void BinaryTreePrevOrderNonR(BTNode* root)
{
	if (!root)
		return;
	//需要栈实现.
	Stack st;
	StackInit(&st);
	BTNode* cur = root;

	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			printf("%c ", cur->val);
			StackPush(&st, cur);
			cur = cur->_lchild;
		}
		//出来就是cur == NULL，  左到底

		BTNode* Top = StackTop(&st);
		StackPop(&st);

		if (Top->_rchild)
			cur = Top->_rchild;
	}

	StackDestroy(&st);
}

//非递归实现的中序遍历
void BinaryTreeInOrderNonR(BTNode* root)
{
	if (!root)
		return;

	Stack st;
	StackInit(&st);
	BTNode* cur = root;

	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_lchild;
		}

		BTNode* Top = StackTop(&st);
		printf("%c ", Top->val);
		StackPop(&st);

		if (Top->_rchild)
			cur = Top->_rchild;
	}

}

//非递归实现的后序遍历
void BinaryTreePostOrderNonR(BTNode* root)
{
	if (!root)
		return;

	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	BTNode* prev = NULL;

	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_lchild;
		}

		BTNode* Top = StackTop(&st);
		if (!Top->_rchild || Top->_rchild == prev)
		{
			printf("%c ", Top->val);
			StackPop(&st);
			prev = Top;
		}
		else
			cur = Top->_rchild;
	}
}

//层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (!root)
		return;

	Queue q;
	QueueInit(&q);
	
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->val);

		if (front->_lchild)
			QueuePush(&q, front->_lchild);
		if (front->_rchild)
			QueuePush(&q, front->_rchild);
	}
	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root)
{
	//0代表不是完全二叉树的情况， 1代表是完全二叉树的情况
	if (!root)
		return 0;

	Queue q;
	QueueInit(&q);

	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;
		else
		{
			QueuePush(&q, front->_lchild);
			QueuePush(&q, front->_rchild);
		}
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		
		if (front != NULL)
		{
			QueueDestroy(&q);
			return 0;
		}
	}

	return 1;
}

//树的节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root)
	{
		return BinaryTreeSize(root->_lchild) + BinaryTreeSize(root->_rchild)
			+ 1;
	}
	else
		return 0;
}

//树的叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	if (root->_lchild == NULL && root->_rchild == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_lchild) + BinaryTreeLeafSize(root->_rchild);
}

//第k层节点的个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k <= 0)
		return 0;

	if (root && k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_lchild, k - 1) + BinaryTreeLevelKSize(root->_rchild, k - 1);
}

//第k层节点的叶子个数
int BinaryTreeLevelKLeafSize(BTNode* root, int k)
{
	if (!root || k <= 0)
		return 0;

	if (root && k == 1)
	{
		if (root->_lchild == NULL && root->_rchild == NULL)
			return 1;
		return 0;
	}

	return BinaryTreeLevelKLeafSize(root->_lchild, k - 1) +
		BinaryTreeLevelKLeafSize(root->_rchild, k - 1);
}

//返回查找的节点的值
BTNode* BinaryTreeFind(BTNode* root, BTNDataType x)
{
	if (!root)
		return NULL;
	if (root->val == x)
		return root;
	else
	{
		return BinaryTreeFind(root->_lchild, x);
		return BinaryTreeFind(root->_rchild, x);
	}
}

//镜像转化
void MirrorRecursively(BTNode* root)
{
	if (!root)
		return;
	if (root->_lchild == NULL && root->_rchild == NULL)	//可有效提高效率
		return;

	BTNode* tmp = root->_lchild;
	root->_lchild = root->_rchild;
	root->_rchild = tmp;

	if(root->_lchild)
		MirrorRecursively(root->_lchild);
	if(root->_rchild)
		MirrorRecursively(root->_rchild);
}


// -- two
int Judge_Same(BTNode* root1, BTNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;
	else if (root1 != NULL && root2 == NULL)
		return 0;
	else if (root1 == NULL && root2 != NULL)
		return 0;

	if (root1->val == root2->val)
	{
		return Judge_Same(root1->_lchild, root2->_rchild)
			&& Judge_Same(root1->_rchild, root2->_lchild);
	}
	else
		return 0;
}

//判断一个数是否是另一棵树的子树。 - one
int isSameTree(BTNode* root)
{
	if (!root)
		return 0;	//0代表失败
	if (root->_lchild != NULL && root->_rchild != NULL)
	{
		return Judge_Same(root->_lchild, root->_rchild);
	}
	else if (root->_lchild == NULL && root->_rchild == NULL)
		return 1;
	else
		return 0;
}
