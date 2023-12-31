#define _CRT_SECURE_NO_WARNINGS
#include"Contach.h"
#include"SeqList.h"
void ContactInit(contact* pcon)
{
	SLInit(pcon);
}
void ContactDestroy(contact* pcon)
{
	SLDestroy(pcon);
}

//添加联系人
void ContactAdd(contact* pcon) 
{
	CInfo info;
	printf("请输入联系人姓名\n");
	scanf("%s",info.name);
	printf("请输入联系人性别\n");
	scanf("%s",info.sex);
	printf("请输入联系人年龄\n");
	scanf("%d",&info.age);
	printf("请输入联系人电话\n");
	scanf("%s", info.tel);
	printf("请输入联系人住址\n");
	scanf("%s", info.addr);
	//联系人数据都获取到了，并保存到结构体info中
	//往通讯录（顺序表）中插入数据
	SLPushBack(pcon, info);
}

int FindByName(contact* pcon,char name[])
{
	for (int i =0;i< pcon->size;i++)
	{
		if (strcmp(pcon->a[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void ContactDel(contact* pcon)
{
	//直接强制要求用户使用联系人名称来查找
	printf("请输入删除用户名的名称\n");
	char name[NAME_MAX];
	scanf("%s",name);
	int findidex = FindByName(pcon, name);
	if (findidex<0)
	{
		printf("要删除的用户不存在\n");
		return 0;
	}
	//找到了，要删除的findidx位置的数据
	SLErase(pcon, findidex);
}
//修改联系人
void ContactModify(contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要修改的用户名称");
	scanf("%s",name);
	//获取到的通讯录（顺序表）下标的位置
	int find = FindByName(pcon, name);
	if (find<0)
	{
		printf("要修改的用户不存在\n");
		return 0;
	}
	printf("请输入新的用户名称：\n");
	scanf("%s",pcon->a[find].name);
	printf("请输入新的用户性别：\n");
	scanf("%s",pcon->a[find].sex);
	printf("请输入新的用户年龄：\n");
	scanf("%d",&pcon->a[find].age);
	printf("请输入新的用户电话：\n");
	scanf("%s",pcon->a[find].tel);
	printf("请输入新的用户地址：\n");
	scanf("%s",pcon->a[find].addr);

	printf("修改成功\n");
}
//查看通讯录
void ContactShow(contact* pcon) 
{
	printf("%s %s %s %s %s \n","姓名","性别","年龄","电话","住址");
	for (int i =0;i<pcon->size;i++)
	{
		printf("%-6s %-6s %-6d %-6s %-6s \n",
			pcon->a[i].name,
			pcon->a[i].sex,
			pcon->a[i].age,
			pcon->a[i].tel,
			pcon->a[i].addr
			);
	}

}
//查找指定联系人
void ContactFind(contact* pcon)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户名称\n");
	scanf("%s",name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("没有该联系人不存在\n");
		return 0;
	}
	//打印该联系人
	printf("%s %s %s %s %s \n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%-6s %-6s %-6d %-6s %-6s \n",
		pcon->a[find].name,
		pcon->a[find].sex,
		pcon->a[find].age,
		pcon->a[find].tel,
		pcon->a[find].addr);


}