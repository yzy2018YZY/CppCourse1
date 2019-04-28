//1850059 计1班 杨志远

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出文件句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出文件句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出文件句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

int chooseMode()
{
	char ch;
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("0.退出\n");
	printf("[请选择0 - 6] ");
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
			printf("游戏结束，按回车键返回菜单.");
			while (1)
			{
				ch = _getch();
				//回车
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
			//输入箭头
			if (ch == (char)0xE0)
			{
				ch = _getch();
				// 0x4800 上箭头
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
				//0x4b00 左箭头
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
				//0x5000 下箭头
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
				//0x4d00 右箭头
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
			//上
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
			//左
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
			//下
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
			//右
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
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

/* -- 按需增加的若干函数可以放在此处 --*/
