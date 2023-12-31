#define _CRT_SECURE_NO_WARNINGS
#include"Contach.h"
#include"SeqList.h"

//通讯录界面
void menu()
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("^                                           ^\n");
	printf("^                  通讯录                   ^\n");
	printf("^    1，添加联系人         2，删除联系人    ^\n");
	printf("^    3，修改联系人         4，查找联系人    ^\n");
	printf("^    5，查看通讯录         6，退出          ^\n");
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
		printf("请选择你的操作\n");
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
				printf("输入错误，请重新输入");
				break;
		}
	} while (op != 0);
	ContactDestroy(&con);

}
