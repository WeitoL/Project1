#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"

void test()
{
	int ch = 0;
	do 
	{
		Snake snake = { 0 };//������̰����
		//1����Ϸ��ʼ������ʼ����Ϸ
		GameStart(&snake);
		//2����Ϸ���С�����Ϸ���������й���
		GameRun(&snake);
		//3����Ϸ����������Ϸ�ƺ��ͷ���Դ��
		GameEnd(&snake);
		SetPos(20, 15);
		printf("����һ����?(X/T)");
		ch = getchar();
		getchar();//�����\n

	} while (ch=='x'||ch=='X');
	SetPos(0,27);
}
int main()
{
    //���ó�����Ӧ���ػ���
	setlocale(LC_ALL,"");
	srand((unsigned int )time(NULL));
	test();
	return 0;
}