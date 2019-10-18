#pragma once

#include<stdio.h>
#include<stdlib.h>
//#include<vld.h>
#include<assert.h>

/*
	不带头的单链表
*/

typedef int Datatype;

typedef struct Node
{
	Datatype data;
	struct Node *next;
}*LinkNode, Node;

//仅仅为了定义头节点
typedef struct   Node_head
{	
	struct Node *head;
}*Node_head, head;

void InitNode(Node_head pHead);		//我不想带头节点
void DestoryNode(Node_head pHead);

void ListPushFront(Node_head pHead, Datatype value);
void ListPopFront(Node_head pHead);
void ListPushBack(Node_head pHead, Datatype value);
void ListPopBack(Node_head pHead);

void Print_Link(Node_head pHead);		
void Deleted_val_Link(Node_head pHead, Datatype val);	//删除val的元素

LinkNode Reverse_Link(Node_head pHead);		//逆置单链表
Node_head MIddle_Link(Node_head pHead);		//返回中间节点

LinkNode FindKthToTail(Node_head pHead, size_t  k);		//返回倒数第k个节点
void chkPalindrome(Node_head pHead);		//判断是否为回文链表
Node_head deleteDuplication(Node_head pHead);		//删除重复节点
