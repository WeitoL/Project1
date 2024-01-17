#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//����˫����ڵ�Ľṹ
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;//val==data
	struct ListNode* next;
	struct ListNode* prev;

}LTNode;

//����ĳ�ʼ��������
//void LTInit(LTNode** pphead);
LTNode* LTInit();
void LTDestroy(LTNode* phead);
void LTPrint(LTNode* phead);
//bool LTEmpty(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);
void LTPopFront(LTNode* phead);
//��posλ��֮���������
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
LTNode* LTFind(LTNode* phead, LTDataType x);
