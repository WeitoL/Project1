#pragma once

//创建保存联系人数据的结构
#define NAME_MAX 100
#define SEX_MAX 10
#define TEL_MAX 15
#define ADDR_MAX 100

typedef struct ContactInfo
{
	char name[NAME_MAX];//定长数组
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
};
typedef struct ContactInfo CInfo;



//通讯录底层是顺序表来实现
typedef struct SeqList contact;

//通讯录的初始化和销毁
void ContactInit(contact* con);
void ContactDestroy(contact* con);

//添加联系人
void ContactAdd(contact* pcon);
//删除联系人
void ContactDel(contact* pcon);
//修改联系人
void ContactModify(contact* pcon);
//查看通讯录
void ContactShow(contact* pcon);
//查找指定联系人
void ContactFind(contact* pcon);