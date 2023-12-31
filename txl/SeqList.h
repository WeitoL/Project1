#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"Contach.h"

//动态顺序表
//
//typedef  CInfo SLDataType；
typedef struct ContactInfo SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//顺序表初始化
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//头部/尾部 插入/删除
void SLPushBack(SL* ps ,SLDataType x);
void SLPushFront(SL* ps,SLDataType x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

void SLPrint(SL* ps);
bool SLIsEmpty(SL* ps);

//在任意位置插入删除
//在指定的位置之前插入数据
void SLInsert(SL* ps ,int pos,SLDataType x);
//删除指定位置的数据
void SLErase(SL* ps,int pos);

bool SLFind(SL* ps,SLDataType x);

