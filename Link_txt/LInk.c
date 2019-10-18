#include"contact.h"


//初始化链表
void InitNode(Node_head pHead)
{
	assert(pHead != NULL);
	
	pHead->head = NULL;
}

//链表的销毁
void DestoryNode(Node_head pHead)
{
	if (pHead == NULL)
	{
		printf("不需要删除，为存入数据\n");
		return;
	}

	LinkNode prev = pHead->head;
	LinkNode cur = NULL;
	while (prev != NULL)
	{
		cur = prev->next;
		free(prev);
		prev = cur;
	}

}

LinkNode Broad_memory(Datatype value)
{
	LinkNode p_node = (LinkNode)malloc(sizeof(Node));
	if (p_node == NULL)
		exit(0);

	p_node->data = value;
	p_node->next = NULL;
	return p_node;
}

void ListPushBack(Node_head pHead, Datatype value)
{
	assert(pHead != NULL);
	if (pHead->head == NULL)
	{
		pHead->head = Broad_memory(value);
	}
	else
	{
		LinkNode p_temp = pHead->head;
		while (p_temp->next)
		{
			p_temp = p_temp->next;
		}
		p_temp->next = Broad_memory(value);
	}
	
}

//遍历
void Print_Link(Node_head pHead)
{
	assert(pHead != NULL);	//
	
	LinkNode p_temp = pHead->head;
	while (p_temp)
	{
		if(!p_temp->next)
			printf("%d", p_temp->data);
		else
		{
			printf("%d->", p_temp->data);
		}

		p_temp = p_temp->next;
	}
	printf("\n");
}

////删除val元素的值
//void Deleted_val_Link(Node_head pHead, Datatype val)
//{
//	assert(pHead != NULL);
//
//	LinkNode p_temp = pHead->head;		//指向头节点
//
//	while (p_temp)
//	{
//		if (p_temp->next)		//正常操作！
//		{
//			if (p_temp->data == val)		//等于val的情况
//			{
//				/*替位操作*/
//				LinkNode p = p_temp->next;
//				p_temp->data = p->data;
//				p_temp->next = p->next;
//				free(p);
//				p = NULL;
//			}
//			else
//			{
//				p_temp = p_temp->next;
//			}
//		}
//		else  //尾节点
//		{
//			if (pHead->head == p_temp)		//只有一个节点
//			{
//				if (p_temp->data == val)
//				{
//					free(p_temp);
//					p_temp = NULL;
//				}
//			}
//			else  //不只有一个节点
//			{
//				if (p_temp->data == val)
//				{
//					LinkNode p = pHead->head;
//					while (p->next != p_temp)
//					{
//						p = p->next;
//					}
//					p->next = NULL;
//					free(p_temp);
//					p_temp = NULL;
//				}
//			}
//		return;
//		}
//	}
//}

//双指针法
void Deleted_val_Link(Node_head pHead, Datatype val)
{
	assert(pHead != NULL);

	LinkNode prev = NULL;
	LinkNode cur = pHead->head;

	while (pHead->head->data == val)
	{
		pHead->head = pHead->head->next;
	}

	while (cur)
	{
		if (cur->data == val)
		{
			LinkNode  p_temp = cur->next;
			if (prev != NULL)
			{
				prev->next = p_temp;
			}
			free(cur);
			cur = p_temp;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

}

//逆置单链表
LinkNode Reverse_Link(Node_head pHead)
{
	if (!pHead)
		return NULL;

	LinkNode prev, cur, next;
	prev = NULL;
	cur = pHead->head;
	next = pHead->head->next;
	
	while (cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if(next!= NULL)
			next = next->next;
	}
	
	pHead->head = prev;
	return prev;
}

//返回中间的节点
Node_head MIddle_Link(Node_head pHead)
{
	if (!pHead)
		return NULL;

	LinkNode slow = pHead->head;
	LinkNode fast = pHead->head;

	while (fast)
	{
		if (fast->next != NULL)
			fast = fast->next->next;
		else
			break;
		slow = slow->next;
	}
	pHead->head = slow;

	return pHead;
}

//返回倒数第k个节点
LinkNode FindKthToTail(Node_head pHead, size_t  k)
{
	if (!pHead)
		return NULL;

	LinkNode slow = pHead->head;
	LinkNode fast = pHead->head;

	//先走k步
	while (k--)
	{
		if (fast == NULL)
			return NULL;
		else
			fast = fast->next;//证明没有倒数第k个数
		
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

void chkPalindrome(Node_head pHead)
{
	if (!pHead)
		return NULL;

	LinkNode B = Reverse_Link(MIddle_Link(pHead));
	LinkNode B1 = B;
	LinkNode  A = pHead->head;
	while (B)
	{
		if (A->data != B->data)
		{
			printf("不是回文链表！\n");
			return;
		}
		A = A->next;
		B = B->next;
	}
	
	printf("回文链表！\n");
	pHead->head = B1;
	Reverse_Link(pHead);
}

//删除重复节点
Node_head deleteDuplication(Node_head pHead)
{
	if (!pHead)
		return NULL;
	if (!pHead->head)		
		return NULL;

	LinkNode prev = NULL;
	LinkNode cur = pHead->head;
	LinkNode next = pHead->head->next;

	while (next)
	{
		if (cur->data == next->data)
		{
			LinkNode p_temp = NULL;

			while (next->data == cur->data)
			{
				p_temp = next->next;
				free(next);
				next = p_temp;
				if (next == NULL)
					break;
			}

			if (prev == NULL)
			{
				pHead->head = next;
			}
			else
			{
				prev->next = next;
			}
			free(cur);
			cur = next;
			if (cur != NULL)
			{
				next = cur->next;
			}
			else
			{
				break;
			}
		}
		else
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	return pHead;
}
