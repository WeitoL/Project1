#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"

//���ù�������
void SetPos(short x, short y)
{
	COORD pos = { x,y };
	HANDLE hOutput = NULL;
	//��ñ�׼����ľ����������ʶ��ͬ�豸����ֵ��
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ñ�׼����Ϲ���λ��Ϊpos
	SetConsoleCursorPosition(hOutput,pos);
}

void WelComeToGame()
{
	//��λ���
	SetPos(40,14);
	printf("��ӭ����̰������Ϸ");
	SetPos(40, 25);
	system("pause");//pause����ͣ
	system("cls");//������Ļ
	SetPos(20, 14);
	printf("ʹ�á����������������ֱ�����ߵ��ƶ���F3�Ǽ��٣�F4�Ǽ���");
	SetPos(40, 25);
	system("pause");
	system("cls");
}

void CreateMap()
{
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i <= 56; i += 2)//��
	{
		wprintf(L"%lc", WALL);
	}
	SetPos(0, 26);
	for (i = 0; i <= 56; i += 2)//��
	{
		wprintf(L"%lc", WALL);
	}
	for (i = 0; i <= 25; i++)//��
	{
		SetPos(0,i);
		wprintf(L"%lc",WALL);
	}
	for (i=1;i<=25;i++)//��
	{
		SetPos(56,i);
		wprintf(L"%lc",WALL);
	}
}

void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cur =(pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->x = POS_X + 2*i;
		cur->y = POS_Y;
		cur->next = NULL;
		//ͷ��
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}

	}
	//��ӡ����
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x,cur->y);
		wprintf(L"%lc",BODY);
		cur = cur->next;
	}
	ps->_Status = OK;
	ps->_Score = 0;
	ps->_pFood = NULL;
	ps->_SleepTime = 200;
	ps->_FoodWeight = 10;
	ps->_Dir = RIGHT;
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);//x���������2�ı���
	//������ߵ������ͻ
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{ 
		//�Ƚ�����
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}
	//
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood==NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	ps->_pFood = pFood;
	//��ӡʳ��
	SetPos(x,y);
	wprintf(L"%lc",FOOD);
}

void GameStart(pSnake ps)
{
	//����̨���ڵ�����
	system("mode con cols=100 lines=30");
	system("title ̰����");
	//�������
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput,&CursorInfo);//��ÿ���̨�����Ϣ
	CursorInfo.bVisible = false;//���ؿ���̨���
	SetConsoleCursorInfo(hOutput,&CursorInfo);//���ÿ���̨���״̬
	//��ӡ��ӭ����
	WelComeToGame();
	//������ͼ
	CreateMap();
	//��ʼ��̰����
	InitSnake(ps);
	//����ʳ��
	CreateFood(ps);
}
//��Ϸ��������
void PrintHelpInfo()
{
	SetPos(64, 15);
	printf("1.���ܴ�ǽ������ҧ�Լ�");
	SetPos(64, 16);
	printf("2.ʹ�á�,��,��,��,�ֱ�����ߵ��ƶ�");
	SetPos(64, 17);
	printf("3.F3����,F4����");
	SetPos(64, 18);
	printf("4.ESC-�˳�,�ո���ͣ��Ϸ");
	SetPos(64, 20);
	printf("��Ϸ��Ȩ��@WEI");

}

void Pause()
{
	while (1)
	{
		Sleep(100);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

int NextIsFood(pSnake ps,pSnakeNode pnext)
{
	if (ps->_pFood->x == pnext->x && ps->_pFood->y == pnext->y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//�Ե�ʳ��
void EatFood(pSnake ps, pSnakeNode pnext)
{
	//ͷ��
	pnext->next = ps->_pSnake;
	ps->_pSnake = pnext;

	//��ӡ��
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc",BODY);
		cur = cur->next;
	}
	free(ps->_pFood);
	ps->_Score += ps->_FoodWeight;

	CreateFood(ps);//�´���ʳ��
}

//����ʳ��
void NoFood(pSnake ps, pSnakeNode pnext)
{
	//ͷ��
	pnext->next = ps->_pSnake;
	ps->_pSnake = pnext;

	//��ӡ��
	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
     
}

//���Ƿ�ײǽ
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 ||
		ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 ||
		ps->_pSnake->y == 26)
		ps->_Status = KILL_BY_WALL;
}
//���Ƿ���ɱ
void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (ps->_pSnake->x == cur->x && ps->_pSnake->y == cur->y)
			ps->_Status = KILL_BY_SELF;
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps)
{
	pSnakeNode pNext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNext == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}
	pNext->next = NULL;
	switch (ps->_Dir)
	{
	case UP:
		pNext->x = ps->_pSnake->x;
		pNext->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNext->x = ps->_pSnake->x;
		pNext->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNext->x = ps->_pSnake->x - 2;
		pNext->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNext->x = ps->_pSnake->x + 2;
		pNext->y = ps->_pSnake->y;
		break;
	}
	//�ж���ͷ��������괦�Ƿ���ʳ��
	if (NextIsFood(ps,pNext))
	{
		//�Ե�ʳ��
		EatFood(ps, pNext);
	}
	else
	{
		//����ʳ��
		NoFood(ps, pNext);
	}

	//���Ƿ�ײǽ
	KillByWall(ps);
	//���Ƿ���ɱ
	KillBySelf(ps);

}
void GameRun(pSnake ps)
{
	PrintHelpInfo();
	do
	{
		SetPos(64,10);
		printf("�÷�:%04d",ps->_Score);
		SetPos(64,11);
		printf("ÿ��ʳ��:%2d",ps->_FoodWeight);

		if (KEY_PRESS(VK_UP) && ps->_Dir != DOWN)
		{
			ps->_Dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_Dir != UP)
		{
			ps->_Dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_Dir != RIGHT)
		{
			ps->_Dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_Dir != LEFT)
		{
			ps->_Dir = RIGHT;
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->_Status = END_NORMAL;
			break;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_F3))//����
		{
			if (ps->_SleepTime >= 80)
			{
				ps->_SleepTime -= 30;
				ps->_FoodWeight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))//����
		{
			if (ps->_SleepTime < 320)
			{
				ps->_SleepTime += 30;
				ps->_FoodWeight -= 2;
			}
		}
		Sleep(ps->_SleepTime);
		SnakeMove(ps);
	} while (ps->_Status == OK);

}
void GameEnd(pSnake ps)
{
	SetPos(20,12);
	switch (ps->_Status)
	{
	case END_NORMAL:
		printf("�������˳���Ϸ\n");
		break;
	case KILL_BY_SELF:
		printf("��Ϸ��ɱ,��Ϸ����\n");
		break;
	case KILL_BY_WALL:
		printf("ײǽ�ˣ���Ϸ����\n");
		break;
	}
	//�ͷ�����Ľ��
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
	ps->_pSnake = NULL;
}

