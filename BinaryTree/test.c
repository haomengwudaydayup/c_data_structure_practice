//#include"BTNodeTree.h"
#include"Stack.h"
#include"Queue.h"
void test_BTNodeTree()
{
	/*char str[] = { '8', '6', '5', '#', '4', '#', '#', '7', '#', '#', '6', '7',
				'#', '#', '9', '#', '#' };*/

	char str[] = { '1', '5', '#', '#', '3', '#', '#' };
	//char str[] = { '1', '#', '#' };
	
	int pi = 0;

	BTNode* root = BTNodeInit(str, &pi);

	puts("先序遍历");
	BinaryTreePrevOrder(root);
	puts("\n中序遍历");
	BinaryTreeInOrder(root);
	puts("\n后序遍历");
	BinaryTreePostOrder(root);
	puts("\n层序遍历");
	BinaryTreeLevelOrder(root);

	puts("\n非递归实现的先序遍历");
	BinaryTreePrevOrderNonR(root);
	puts("\n非递归实现的中序遍历");
	BinaryTreeInOrderNonR(root);
	puts("\n非递归实现的后序遍历");
	BinaryTreePostOrderNonR(root);


	if (BinaryTreeComplete(root))
	{
		puts("\n完全二叉树");
	}
	else
		puts("\n非完全二叉树！");

	printf("二叉树节点的个数为%d\n", BinaryTreeSize(root));
	printf("二叉树叶子节点的个数为:%d\n", BinaryTreeLeafSize(root));

	printf("第k层的节点个数为:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("第k层的节点叶子个数为:%d\n", BinaryTreeLevelKLeafSize(root, 3));
	
	BTNode* p = BinaryTreeFind(root, '3');
	if (p)
		printf("返回的值为:%c\n", p->val);
	else
		puts("没有这个值的节点");
	
	
	puts("");
	BTNodeDestroy(&root);
	if (root == NULL)
		puts("清空");
	else
		puts("内存泄漏！");
}

int main()
{
	test_BTNodeTree();

	system("pause");
	return 0;
}
