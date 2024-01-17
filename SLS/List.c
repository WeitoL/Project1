#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
//void LTInit(LTNode** pphead)
//{
//	*pphead = (LTNode*)mallo(sizeof(LTNode));
//	if (*pphead ==NULL)
//	{
//		perror("malloc error");
//		return;
//	}
//	(*pphead)->data = -1;// 哨兵位
//	//循环
//	(*pphead)->next = (*pphead)->prev = *pphead;
//}
LTNode* LTInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if(phead==NULL)	
	{
		perror("maolloc error");
		return;
	}
	phead->data = -1;
	phead->next = phead->prev = NULL;
	return phead;
}

LTNode* ListBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)mallo(sizeof(LTNode));
	node->data = x;
	node->next = node->prev = NULL;
	return node;
}

//插入操作
void LTPushBack(LTNode* phead,LTDataType x)
{
	assert(phead);
	LTNode* node = ListBuyNode(x);
	node->prev = phead ->prev;
	node->next = phead;

	phead->prev->next = node;
	phead->prev = node;
}
void LTPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* node = ListBuyNode(x);
	node->prev = phead;
	node->next = phead->next;
	phead->next->prev = node;
	phead->next = node;
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next!=phead);
	LTNode* del = phead->next;
	phead->next = del->next;
	free(del);
	del = NULL;
}
//pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* node = ListBuyNode(x);
	node->next = pos->next;
	node->prev = pos;
	pos->next = node;
	node->next->prev = node;
}
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data==x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur !=phead)
	{
		LTNode* next = phead->next;
		free(cur);
		cur = next;
	}
	//除了循环之后，哨兵位还没有释放
	free(phead);
	phead = NULL;
}

//方法2
//void LTDestroy(LTNode** pphead) {
//	assert(pphead && *pphead);
//	LTNode* cur = (*pphead)->next;
//	while ( cur!=*pphead )
//	{
//		LTNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	free(*pphead);
//	*pphead = NULL;
//}