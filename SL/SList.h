#pragma once  
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//#include"contact.h"
//
//定义链表节点的结构
//typedef int SLTDataType;
typedef struct SLTistNode {
	SLTDataType data;//要保存的数据
	struct SLTistNode* next;
}SLTNode;
//
////我来创建几个结点组成一个链表，并打印链表
//void SLPrint(SLNode* phead);
//
////尾插
//void SLTPushBack(SLNode** pphead, SLDataType x);
//void SLTPushFront(SLNode** pphead, SLDataType x);
////删除
//void SLTPopBack(SLNode** pphead);
//void SLPopFront(SLNode** pphead);
//
////找节点，这里的第一个参数写一级指针还是二级指针
////这里传一级实际上就可以了，因为不改变头结点
////但是这里要写二级指针，因为要保持接口一致性
//SLNode* SLFind(SLNode** pphead, SLDataType x);
//
////指定位置的插入删除
////在指定位置之前插入数据
//void SLInsert(SLNode** pphead, SLNode* pos, SLDataType x);
////在指定位置之后插入数据
//void SLInsertAfter(SLNode* pos, SLDataType x);
////删除pos节点
//void SLErase(SLNode** pphead, SLNode* pos);
////删除pos之后节点
//void SLEraseAfter(SLNode* pos);
//
////销毁链表
//void SLDesTroy(SLNode** pphead);

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"contact.h"
typedef struct PersonInfo SLTDataType;
typedef int SLTDataType;
void SLTPrint(SLTNode* phead);
//头部插⼊删除/尾部插⼊删除
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPopFront(SLTNode** pphead);
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//在指定位置之后插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos);
//销毁链表
void SLTistDesTroy(SLTNode** pphead);