#pragma once

//����������ϵ�����ݵĽṹ
#define NAME_MAX 100
#define SEX_MAX 10
#define TEL_MAX 15
#define ADDR_MAX 100

typedef struct ContactInfo
{
	char name[NAME_MAX];//��������
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
};
typedef struct ContactInfo CInfo;



//ͨѶ¼�ײ���˳�����ʵ��
typedef struct SeqList contact;

//ͨѶ¼�ĳ�ʼ��������
void ContactInit(contact* con);
void ContactDestroy(contact* con);

//������ϵ��
void ContactAdd(contact* pcon);
//ɾ����ϵ��
void ContactDel(contact* pcon);
//�޸���ϵ��
void ContactModify(contact* pcon);
//�鿴ͨѶ¼
void ContactShow(contact* pcon);
//����ָ����ϵ��
void ContactFind(contact* pcon);