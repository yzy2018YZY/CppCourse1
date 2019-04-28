//1850059 ��1�� ��־Զ

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������ļ����
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������ļ����
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������ļ����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

int chooseMode()
{
	char ch;
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0 - 6] ");
	while (1)
	{
		ch = _getch();
		if (ch == '0')
		{
			return 0;
		}
		if (ch == '1')
		{
			return 1;
		}
		if (ch == '2')
		{
			return 2;
		}
		if (ch == '3')
		{
			return 3;
		}
		if (ch == '4')
		{
			return 4;
		}
	}
}

void move(int mode, const HANDLE hout)
{
	int arrowMode = (((mode - 1) / 2) == 1);
	int border = ((mode % 2) == 1);
	char ch;
	system("cls");
	init_border(hout);
	int x = (MAX_X + 1) / 2;
	int y = (MAX_Y + 1) / 2;
	gotoxy(hout, x, y);
	while (1)
	{
		ch = _getch();
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, MAX_Y + 6);
			printf("��Ϸ���������س������ز˵�.");
			while (1)
			{
				ch = _getch();
				//�س�
				if (ch == 13)
				{
					return;
				}

			}
		}
		if (ch == ' ')
		{
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
		if (arrowMode)
		{
			//�����ͷ
			if (ch == (char)0xE0)
			{
				ch = _getch();
				// 0x4800 �ϼ�ͷ
				if (ch == 0x48)
				{
					if (y > 1)
					{
						y--;
						gotoxy(hout, x, y);
					}
					else
					{
						if (!border)
						{
							y = MAX_Y;
							gotoxy(hout, x, MAX_Y);
						}
					}
				}
				//0x4b00 ���ͷ
				if (ch == 0x4b)
				{
					if (x > 1)
					{
						x--;
						gotoxy(hout, x, y);
					}
					else
					{
						if (!border)
						{
							x = MAX_X;
							gotoxy(hout, MAX_X, y);
						}
					}
				}
				//0x5000 �¼�ͷ
				if (ch == 0x50)
				{
					if (y < MAX_Y)
					{
						y++;
						gotoxy(hout, x, y);
					}
					else
					{
						if (!border)
						{
							y = 1;
							gotoxy(hout, x, y);
						}
					}
				}
				//0x4d00 �Ҽ�ͷ
				if (ch == 0x4d)
				{
					if (x < MAX_X)
					{
						x++;
						gotoxy(hout, x, y);
					}
					else
					{
						if (!border)
						{
							x = 1;
							gotoxy(hout, x, y);
						}
					}
				}
			}
		}
		else
		{
			//��
			if (ch == 'i' || ch == 'I')
			{
				if (y > 1)
				{
					y--;
					gotoxy(hout, x, y);
				}
				else
				{
					if (!border)
					{
						y = MAX_Y;
						gotoxy(hout, x, MAX_Y);
					}
				}
			}
			//��
			if (ch == 'j' || ch == 'J')
			{
				if (x > 1)
				{
					x--;
					gotoxy(hout, x, y);
				}
				else
				{
					if (!border)
					{
						x = MAX_X;
						gotoxy(hout, MAX_X, y);
					}
				}
			}
			//��
			if (ch == 'k' || ch == 'k')
			{
				if (y < MAX_Y)
				{
					y++;
					gotoxy(hout, x, y);
				}
				else
				{
					if (!border)
					{
						y = 1;
						gotoxy(hout, x, y);
					}
				}
			}
			//��
			if (ch == 'l' || ch == 'L')
			{
				if (x < MAX_X)
				{
					x++;
					gotoxy(hout, x, y);
				}
				else
				{
					if (!border)
					{
						x = 1;
						gotoxy(hout, x, y);
					}
				}
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	while (1)
	{
		system("cls");
		int mode = chooseMode();
		if (mode == 0)
		{
			break;
		}
		if (mode > 0 && mode <= 4)
		{
			move(mode, hout);
		}
	}
	return 0;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
