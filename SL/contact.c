#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include"SList.h"

void LoadContact(contact** con)
{
	FILE* pf = fopen("conttact.txt","rb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}

	//循环读取文件数据
	PeoInfo info;
	while (fread(&info,sizeof(info),1,pf))
	{
		SLTPushBack(con, info);
	}
	printf("历史数据导入成功！\n");

}

void InitContact(contact** con)
{
	LoadContact(con);
}

void AddContact(contact** con)
{
	PeoInfo info;
	printf("请输入姓名：\n");
	scanf("%s",&info.name);
	printf("请输入性别：\n");
	scanf("%s", &info.sex);
	printf("请输入年龄：\n");
	scanf("%s", &info.age);
	printf("请输入联系电话：\n");
	scanf("%s", &info.tel);
	printf("请输入地址：\n");
	scanf("%s", &info.addr);
	SLTPushBack(con,info);
	printf("插入成功\n");

}

contact* FindByName(contact* con, char name[])
{
	contact* cur = con;
	while (cur)
	{
		if (strcmp(cur->data.name,name)==0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;

}

void DelContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入删除的用户名姓名\n");
	scanf("%s",name);

	contact* pos = FindByName(*con, name);
	if(pos==NULL)
	{
		printf("用户不存在\n");
		return;
	}
	SLTErase(con, pos);
	printf("删除成功\n");
}

void ShowContact(contact** con)
{
	printf("%-10s %-4s %-4s %15s %-20s\n","姓名","性别","年龄","联系电话","地址");
	contact* cur = con;
	while (cur)
	{
		printf("%-10s %-4s %-4d %15s %-20s\n",
			cur->data.name,
			cur->data.sex,
			cur->data.age,
			cur->data.tel,
			cur->data.addr);
		cur = cur->next;
	}

}

void FindContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入要查找的用户姓名\n");
	scanf("%s",&name);

	contact* pos = FindByName(con, name);
	if (pos == NULL)
	{
		printf("用户不存在\n");
		return;
	}
	printf("查找成功\n");
	printf("%-10s %-4s %-4d %15s %-20s\n",
		pos->data.name,
		pos->data.sex,
		pos->data.age,
		pos->data.tel,
		pos->data.addr);
}

void ModifyContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入要修改的用户名称\n");
	scanf("%s", &name);
	contact* pos = FindByName(*con, name);
	if (pos == NULL)
	{
		printf("要查找的用户不存在，修改失败\n");
		return;
	}
	printf("请输入要修改的姓名\n");
	scanf("%s",pos->data.name);
	printf("请输入要修改的性别\n");
	scanf("%s", pos->data.sex); 
	printf("请输入要修改的年龄\n");
	scanf("%d", pos->data.age);
	printf("请输入要修改的联系电话\n");
	scanf("%s", pos->data.tel);
	printf("请输入要修改的地址\n");
	scanf("%s", pos->data.addr);
	printf("修改成功\n");

}

void SaveContact(contact** con)
{
	FILE* pf = fopen("conttact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen error!\n");
		return;
	}
	contact* cur = con;
	while (cur)
	{
		fwrite(&(cur->data),sizeof(cur->data),1,pf);
		cur = cur->next;
	}

	printf("通讯录数据保存成功！\n");
}

void DestroyContact(contact** con)
{
	SaveContact(*con);
	SLTistDesTroy(con);
}