//1850059 计1班 杨志远

#include "90-b2.h"

void welcome_mode()
{
	cout << "---------------------------------------------" << endl;
	cout << "1.内部数组，随机生成初始5个球" << endl;
	cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
	cout << "3.内部数组，完整版" << endl;
	cout << "4.画出n*n的框架（无分隔线），随机显示5个球" << endl;
	cout << "5.画出n*n的框架（有分隔线），随机显示5个球" << endl;
	cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
	cout << "7.cmd图形界面完整版" << endl;
	cout << "8.cmd图形界面完整版 - 支持同时读键" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "[请选择0 - 8] ";
}

int select_mode()
{
	char ch = 0;
	while (1)
	{
		ch = _getch();
		if (ch >= '0' && ch <= '8')
		{
			cout << ch;
			break;
		}
	}
	if (ch == '0')
		exit(0);
	return ch - '0';
}

void choose_mode(int mode, int map[][MaxCol + 1], int row, int col)
{
	memset(map, 0, sizeof(int) * (MaxRow + 1) * (MaxCol + 1));
	create_balls(map, row, col, (mode == 2 || mode == 6) ? int(row * col * 0.6) : 5);
	if (mode != 6 && mode != 7)
		print_map_base(map, row, col);
	if (mode == 2)
		mode_2(map, row, col);
	if (mode == 3)
		mode_3(map, row, col);
	if (mode >= 4 && mode <= 8)
	{
		if (mode == 4 || mode == 5)
		{
			cout << "按回车继续: ";
			while (_getch() != '\r')
				;
			setconsoleborder((mode == 4) ? WindowXSize2 : WindowXSize3, (mode == 4) ? WindowYSize2  +  row - 7: WindowYSize3 + (row - 7) * 2);
		}
		else
			setconsoleborder(((mode == 6) ? 3 + col * 4 : 70), 5 + row * 2);
		cls();
		setfontsize("新宋体", FontSize2);
		draw_framework(row, col, mode);
		draw_points(map, row, col, mode);
		print_console_border(mode);
	}
	if (mode == 6)
		mode_6(map, row, col);
	if (mode >= 7 && mode <= 8)
		mode_7_and_8(map, row, col, mode);
}

int main()
{
	int mode, row, col, winX, winY, winBufferX, winBufferY;
	int map[MaxRow + 1][MaxCol + 1] = {0 };
	srand(unsigned int(time(0)));
	setconsoletitle("彩球游戏-1850059-计1班-杨志远");
	while (1)
	{
		setconsoleborder(WindowXSize1, WindowYSize1, WindowXSize1, 5000);
		setfontsize("新宋体", FontSize1);
		cls();
		gotoxy(0, 0);
		welcome_mode();
		mode = select_mode();
		cls();
		input_information(strlen(helpInformation[2]), 2, 0, &row, &col);
		choose_mode(mode, map, row, col);
		getconsoleborder(winX, winY, winBufferX, winBufferY);
		if (mode >= 4 && mode <= 8)
			gotoxy(0, winY - 2);
		input_information(strlen(helpInformation[3]), 3, 0);
	}
	return 0;
}
