#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"Contach.h"

//��̬˳���
//
//typedef  CInfo SLDataType��
typedef struct ContactInfo SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

//˳����ʼ��
void SLInit(SL* ps);
void SLDestroy(SL* ps);

//ͷ��/β�� ����/ɾ��
void SLPushBack(SL* ps ,SLDataType x);
void SLPushFront(SL* ps,SLDataType x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

void SLPrint(SL* ps);
bool SLIsEmpty(SL* ps);

//������λ�ò���ɾ��
//��ָ����λ��֮ǰ��������
void SLInsert(SL* ps ,int pos,SLDataType x);
//ɾ��ָ��λ�õ�����
void SLErase(SL* ps,int pos);

bool SLFind(SL* ps,SLDataType x);

