#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
//#include"contact.h"

void SLTPrint(SLTNode* phead) {
	//循环打印
	//可以用phead直接来访问，但是注意，当代码走到
	//第14行的时候，此时phead已经变成NULL了
	//若代码没写完，我还要继续使用指向第一个节点的地址时，这时我就
	//找不到第一个节点的地址
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d ->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
SLTNode* SLBuyNode(SLTDataType x) {
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* node = SLBuyNode(x);
	if (*pphead == NULL) {
		*pphead = node;
		return;
	}
	//说明链表不为空,找尾
	SLTNode* pcur = *pphead;
	while (pcur->next)
	{
		pcur = pcur->next;
	}
	pcur->next = node;
}
void SLTPushFront(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* node = SLBuyNode(x);
	//新节点跟头结点连接起来
	node->next = *pphead;//plist
	//让新的节点成为头结点
	*pphead = node;
}
void SLTPopBack(SLTNode** pphead) {
	assert(pphead);
	//第一个节点不能为空
	assert(*pphead);
	//只有一个节点的情况
	if ((*pphead)->next == NULL) {
		//直接把头结点删除
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//有多个节点的情况
		//找尾结点和尾结点的前一个节点
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//prev的next指针不再指向ptail，而是指向ptail的下一个节点
		prev->next = ptail->next;
		free(ptail);
		//为什么必须要置为空？代码后面明明没有再使用ptail？打印链表方法里有判断节点的地址是否为空
		ptail = NULL;
	}
}
void SLTPopFront(SLTNode** pphead) {
	assert(pphead);
	assert(*pphead);
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;//出于代码规范
}

//查找第一个为X的节点
SLTNode* SLTFind(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}


//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead);
	//约定链表不能为空，pos也不能为空
	assert(pos);
	assert(*pphead);
	SLTNode* node = SLBuyNode(x);
	//pos刚好是头结点，头插
	if (pos == *pphead) {
		node->next = *pphead;
		*pphead = node;
		return;
	}
	//找pos的前一个节点
	SLTNode* prev = *pphead;
	while (prev->next != pos)//第一次循环的时候（缺少pos刚好是第一个节点的判断）
	{
		prev = prev->next;
	}
	//prev node  pos
	node->next = pos;
	prev->next = node;
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* node = SLBuyNode(x);
	//pos  node  pos->next
	node->next = pos->next;
	pos->next = node;
}
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (pos == *pphead) {
		*pphead = (*pphead)->next;
		free(pos);
		return;
	}
	//找pos的前一个节点
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev pos pos->next
	prev->next = pos->next;
	free(pos);
	pos = NULL;//只是规范
}
//删除pos之后节点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
}
//销毁链表
void SLTDesTroy(SLTNode** pphead) {
	assert(pphead);
	SLTNode* pcur = *pphead;
	//循环删除
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}


