#define _CRT_SECURE_NO_WARNINGS
#include"Contach.h"
#include"SeqList.h"

//ͨѶ¼����
void menu()
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("^                                           ^\n");
	printf("^                  ͨѶ¼                   ^\n");
	printf("^    1�������ϵ��         2��ɾ����ϵ��    ^\n");
	printf("^    3���޸���ϵ��         4��������ϵ��    ^\n");
	printf("^    5���鿴ͨѶ¼         6���˳�          ^\n");
	printf("^                                           ^\n");
	printf("^                                           ^\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");


}
int main()
{
	int op = -1;
	//
	contact con;
	ContactInit(&con);
	do {
		menu();
		printf("��ѡ����Ĳ���\n");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				ContactAdd(&con);
				break;
			case 2:
				ContactDel(&con);
				break;
			case 3:
				ContactModify(&con);
				break;
			case 4:
				//ContactFind(&con);
				ContactFind(&con);
				break;
			case 5:
				ContactShow(&con);
				break;
			case 0:
				printf("goodbye~~~\n");
				break;
			default:
				printf("�����������������");
				break;
		}
	} while (op != 0);
	ContactDestroy(&con);

}
