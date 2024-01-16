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

	//ѭ����ȡ�ļ�����
	PeoInfo info;
	while (fread(&info,sizeof(info),1,pf))
	{
		SLTPushBack(con, info);
	}
	printf("��ʷ���ݵ���ɹ���\n");

}

void InitContact(contact** con)
{
	LoadContact(con);
}

void AddContact(contact** con)
{
	PeoInfo info;
	printf("������������\n");
	scanf("%s",&info.name);
	printf("�������Ա�\n");
	scanf("%s", &info.sex);
	printf("���������䣺\n");
	scanf("%s", &info.age);
	printf("��������ϵ�绰��\n");
	scanf("%s", &info.tel);
	printf("�������ַ��\n");
	scanf("%s", &info.addr);
	SLTPushBack(con,info);
	printf("����ɹ�\n");

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
	printf("������ɾ�����û�������\n");
	scanf("%s",name);

	contact* pos = FindByName(*con, name);
	if(pos==NULL)
	{
		printf("�û�������\n");
		return;
	}
	SLTErase(con, pos);
	printf("ɾ���ɹ�\n");
}

void ShowContact(contact** con)
{
	printf("%-10s %-4s %-4s %15s %-20s\n","����","�Ա�","����","��ϵ�绰","��ַ");
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
	printf("������Ҫ���ҵ��û�����\n");
	scanf("%s",&name);

	contact* pos = FindByName(con, name);
	if (pos == NULL)
	{
		printf("�û�������\n");
		return;
	}
	printf("���ҳɹ�\n");
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
	printf("������Ҫ�޸ĵ��û�����\n");
	scanf("%s", &name);
	contact* pos = FindByName(*con, name);
	if (pos == NULL)
	{
		printf("Ҫ���ҵ��û������ڣ��޸�ʧ��\n");
		return;
	}
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s",pos->data.name);
	printf("������Ҫ�޸ĵ��Ա�\n");
	scanf("%s", pos->data.sex); 
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%d", pos->data.age);
	printf("������Ҫ�޸ĵ���ϵ�绰\n");
	scanf("%s", pos->data.tel);
	printf("������Ҫ�޸ĵĵ�ַ\n");
	scanf("%s", pos->data.addr);
	printf("�޸ĳɹ�\n");

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

	printf("ͨѶ¼���ݱ���ɹ���\n");
}

void DestroyContact(contact** con)
{
	SaveContact(*con);
	SLTistDesTroy(con);
}