//1850059 ��1�� ��־Զ

#include "90-b2.h"

void welcome_mode()
{
	cout << "---------------------------------------------" << endl;
	cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "6.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
	cout << "7.cmdͼ�ν���������" << endl;
	cout << "8.cmdͼ�ν��������� - ֧��ͬʱ����" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "[��ѡ��0 - 8] ";
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
			cout << "���س�����: ";
			while (_getch() != '\r')
				;
			setconsoleborder((mode == 4) ? WindowXSize2 : WindowXSize3, (mode == 4) ? WindowYSize2  +  row - 7: WindowYSize3 + (row - 7) * 2);
		}
		else
			setconsoleborder(((mode == 6) ? 3 + col * 4 : 70), 5 + row * 2);
		cls();
		setfontsize("������", FontSize2);
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
	setconsoletitle("������Ϸ-1850059-��1��-��־Զ");
	while (1)
	{
		setconsoleborder(WindowXSize1, WindowYSize1, WindowXSize1, 5000);
		setfontsize("������", FontSize1);
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
