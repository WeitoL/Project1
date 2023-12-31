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

//�����ϵ��
void ContactAdd(contact* pcon) 
{
	CInfo info;
	printf("��������ϵ������\n");
	scanf("%s",info.name);
	printf("��������ϵ���Ա�\n");
	scanf("%s",info.sex);
	printf("��������ϵ������\n");
	scanf("%d",&info.age);
	printf("��������ϵ�˵绰\n");
	scanf("%s", info.tel);
	printf("��������ϵ��סַ\n");
	scanf("%s", info.addr);
	//��ϵ�����ݶ���ȡ���ˣ������浽�ṹ��info��
	//��ͨѶ¼��˳����в�������
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

//ɾ����ϵ��
void ContactDel(contact* pcon)
{
	//ֱ��ǿ��Ҫ���û�ʹ����ϵ������������
	printf("������ɾ���û���������\n");
	char name[NAME_MAX];
	scanf("%s",name);
	int findidex = FindByName(pcon, name);
	if (findidex<0)
	{
		printf("Ҫɾ�����û�������\n");
		return 0;
	}
	//�ҵ��ˣ�Ҫɾ����findidxλ�õ�����
	SLErase(pcon, findidex);
}
//�޸���ϵ��
void ContactModify(contact* pcon)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ��û�����");
	scanf("%s",name);
	//��ȡ����ͨѶ¼��˳����±��λ��
	int find = FindByName(pcon, name);
	if (find<0)
	{
		printf("Ҫ�޸ĵ��û�������\n");
		return 0;
	}
	printf("�������µ��û����ƣ�\n");
	scanf("%s",pcon->a[find].name);
	printf("�������µ��û��Ա�\n");
	scanf("%s",pcon->a[find].sex);
	printf("�������µ��û����䣺\n");
	scanf("%d",&pcon->a[find].age);
	printf("�������µ��û��绰��\n");
	scanf("%s",pcon->a[find].tel);
	printf("�������µ��û���ַ��\n");
	scanf("%s",pcon->a[find].addr);

	printf("�޸ĳɹ�\n");
}
//�鿴ͨѶ¼
void ContactShow(contact* pcon) 
{
	printf("%s %s %s %s %s \n","����","�Ա�","����","�绰","סַ");
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
//����ָ����ϵ��
void ContactFind(contact* pcon)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ��û�����\n");
	scanf("%s",name);
	int find = FindByName(pcon, name);
	if (find < 0)
	{
		printf("û�и���ϵ�˲�����\n");
		return 0;
	}
	//��ӡ����ϵ��
	printf("%s %s %s %s %s \n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("%-6s %-6s %-6d %-6s %-6s \n",
		pcon->a[find].name,
		pcon->a[find].sex,
		pcon->a[find].age,
		pcon->a[find].tel,
		pcon->a[find].addr);


}