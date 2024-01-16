#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
//#include"contact.h"

void SLTPrint(SLTNode* phead) {
	//ѭ����ӡ
	//������pheadֱ�������ʣ�����ע�⣬�������ߵ�
	//��14�е�ʱ�򣬴�ʱphead�Ѿ����NULL��
	//������ûд�꣬�һ�Ҫ����ʹ��ָ���һ���ڵ�ĵ�ַʱ����ʱ�Ҿ�
	//�Ҳ�����һ���ڵ�ĵ�ַ
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
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
	assert(pphead);
	SLTNode* node = SLBuyNode(x);
	if (*pphead == NULL) {
		*pphead = node;
		return;
	}
	//˵������Ϊ��,��β
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
	//�½ڵ��ͷ�����������
	node->next = *pphead;//plist
	//���µĽڵ��Ϊͷ���
	*pphead = node;
}
void SLTPopBack(SLTNode** pphead) {
	assert(pphead);
	//��һ���ڵ㲻��Ϊ��
	assert(*pphead);
	//ֻ��һ���ڵ�����
	if ((*pphead)->next == NULL) {
		//ֱ�Ӱ�ͷ���ɾ��
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//�ж���ڵ�����
		//��β����β����ǰһ���ڵ�
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//prev��nextָ�벻��ָ��ptail������ָ��ptail����һ���ڵ�
		prev->next = ptail->next;
		free(ptail);
		//Ϊʲô����Ҫ��Ϊ�գ������������û����ʹ��ptail����ӡ�����������жϽڵ�ĵ�ַ�Ƿ�Ϊ��
		ptail = NULL;
	}
}
void SLTPopFront(SLTNode** pphead) {
	assert(pphead);
	assert(*pphead);
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;//���ڴ���淶
}

//���ҵ�һ��ΪX�Ľڵ�
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


//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
	assert(pphead);
	//Լ��������Ϊ�գ�posҲ����Ϊ��
	assert(pos);
	assert(*pphead);
	SLTNode* node = SLBuyNode(x);
	//pos�պ���ͷ��㣬ͷ��
	if (pos == *pphead) {
		node->next = *pphead;
		*pphead = node;
		return;
	}
	//��pos��ǰһ���ڵ�
	SLTNode* prev = *pphead;
	while (prev->next != pos)//��һ��ѭ����ʱ��ȱ��pos�պ��ǵ�һ���ڵ���жϣ�
	{
		prev = prev->next;
	}
	//prev node  pos
	node->next = pos;
	prev->next = node;
}
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* node = SLBuyNode(x);
	//pos  node  pos->next
	node->next = pos->next;
	pos->next = node;
}
//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (pos == *pphead) {
		*pphead = (*pphead)->next;
		free(pos);
		return;
	}
	//��pos��ǰһ���ڵ�
	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	//prev pos pos->next
	prev->next = pos->next;
	free(pos);
	pos = NULL;//ֻ�ǹ淶
}
//ɾ��pos֮��ڵ�
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
}
//��������
void SLTDesTroy(SLTNode** pphead) {
	assert(pphead);
	SLTNode* pcur = *pphead;
	//ѭ��ɾ��
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}


