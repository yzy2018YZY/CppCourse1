#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

/* ��̬ȫ�֣�ֻ�ڱ�Դ�����ļ�����Ч��Ϊ��ֹͬ������̬ȫ��һ�㽨���__��Ϊ��������ʼ�� */
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//ȡ��׼����豸��Ӧ�ľ��
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//ȡ��׼�����豸��Ӧ�ľ��

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(void)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(__hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(__hout, (TCHAR) ' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(__hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(__hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ָ������ɫ
  ���������const int bg_color ������ɫ��0-15��
			const int fg_color ��ǰ��ɫ��0-15��
  �� �� ֵ��
  ˵    ������ɫ��ȡֵ�ɱ���ɫ+ǰ��ɫ��ɣ���16��
			fg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
					  8-15 ���� ���� ���� ���� ���� ���� ���� ����
			bg_color��0-7    ��   ��   ��   ��   ��   ��   ��   ��
					  8-15 ���� ���� ���� ���� ���� ���� ���� ����
			���յ���ɫΪ ����ɫ*16+ǰ��ɫ
***************************************************************************/
void setcolor(const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(__hout, bg_color * 16 + fg_color);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ƶ���ָ��λ��
  ���������const int X       ��X�����꣨�У�
			const int Y       ��Y�����꣨�У�
  �� �� ֵ��
  ˵    ������Ļ���Ͻ�����Ϊ(0,0)����cmd���ڵĴ�Сδ������������£�Win10Ϊ��
			����x�ᣬ��Ӧ��(0-119)
			����y�ᣬ��Ӧ��(0-29)
***************************************************************************/
void gotoxy(const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(__hout, coord);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ù��״̬����ʾ/����ʾ/ȫ��/���/���ߵȣ�
  ���������const int option��Ҫ���õĹ��״̬
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void setcursor(const int options)
{
	CONSOLE_CURSOR_INFO cursor_info;

	switch (options) {
		case CURSOR_VISIBLE_FULL:
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 100;
			break;
		case CURSOR_VISIBLE_HALF:
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 50;
			break;
		case CURSOR_INVISIBLE:
			cursor_info.bVisible = 0;
			cursor_info.dwSize = 1;
			break;
		case CURSOR_VISIBLE_NORMAL:
		default: //ȱʡ��ʾ��꣬����
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 25;
			break;
	}
	SetConsoleCursorInfo(__hout, &cursor_info);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ָ��λ�ã���ָ����ɫ����ʾһ���ַ����ɴ�
  ���������const int X       ��X�����꣨�У�
			const int Y       ��Y�����꣨�У�
			const char ch     ��Ҫ������ַ�ֵ
			const int bg_color������ɫ��ȱʡΪCOLOR_BLACK��
			const int fg_color������ɫ��ȱʡΪCOLOR_WHITE��
			const int rpt     ���ظ�������ȱʡΪ1��
  �� �� ֵ��
  ˵    ����X��Y�ķ�Χ�μ�gotoxy������˵��
***************************************************************************/
void showch(const int X, const int Y, const char ch, const int bg_color, const int fg_color, const int rpt)
{
	int i;

	gotoxy(X, Y);
	setcolor(bg_color, fg_color);

	/* ѭ��n�Σ���ӡ�ַ�ch */
	for (i = 0; i < rpt; i++)
		putchar(ch);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ı�cmd���ڵĴ�С���������Ĵ�С
  ���������const int cols         ���µ�����
			const int lines        ���µ�����
			const int buffer_cols  ���µĻ���������
			const int buffer_lines ���µĻ���������
  �� �� ֵ��
  ˵    �������������û������������ô��ڴ�С��
			���������ڴ�С���ڵ�ǰ��������δ����ǰ��������ʧ��
***************************************************************************/
void setconsoleborder(int set_cols, int set_lines, int set_buffer_cols, int set_buffer_lines)
{
	/* ȥ��ǰϵͳ����Ĵ��ڵ��������ֵ */
	COORD max_coord;
	max_coord = GetLargestConsoleWindowSize(__hout); /* .X �� .Y �ֱ��Ǵ��ڵ��к��е����ֵ */

	/* �������ô��ڵ����еķǷ�ֵ */
	if (set_cols <= 0 || set_lines <= 0)
		return;
	if (set_cols > max_coord.X)
		set_cols = max_coord.X;
	if (set_lines > max_coord.Y)
		set_lines = max_coord.Y;

	/* ���ô��ڵ����д�С����0��ʼ��0 ~ lines-1, 0 ~ cols-1��*/
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Bottom = set_lines - 1;
	rect.Left = 0;
	rect.Right = set_cols - 1;

	/* ���û����������д�С(ȱʡ��С�ڴ���ֵ���봰��ֵһ��) */
	COORD cr;
	cr.X = (set_buffer_cols == -1 || set_buffer_cols < set_cols) ? set_cols : set_buffer_cols;		//δ�����������ֵС��set_cols����set_cols��δ��������
	cr.Y = (set_buffer_lines == -1 || set_buffer_lines < set_lines) ? set_lines : set_buffer_lines;	//δ�����������ֵС��set_lines����set_lines��δ��������

	/* ȡ��ǰ���ڼ��������Ĵ�С(����getconsoleborder) */
	int cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines;
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(__hout, &binfo);

	cur_cols = binfo.srWindow.Right - binfo.srWindow.Left + 1;	//�ɼ����ڵ�����
	cur_lines = binfo.srWindow.Bottom - binfo.srWindow.Top + 1;	//�ɼ����ڵ�����
	cur_buffer_cols = binfo.dwSize.X;							//������������
	cur_buffer_lines = binfo.dwSize.Y;							//������������

	cls();
	/* ����˳��(��֤���ô��ڴ�Сʱ���ֻ���������ֵ>����ֵ) */
	if (cr.X <= cur_buffer_cols) {
		if (cr.Y <= cur_buffer_lines) {
			SetConsoleWindowInfo(__hout, true, &rect);//���ô���
			SetConsoleScreenBufferSize(__hout, cr);//���û�����
		}
		else { //cr.Y > cur_buffer_lines����Ҫ�û��������������
			COORD tmpcr;
			tmpcr.X = cur_buffer_cols;
			tmpcr.Y = cr.Y;
			SetConsoleScreenBufferSize(__hout, tmpcr);//���û�����

			SetConsoleWindowInfo(__hout, true, &rect);//���ô���
			SetConsoleScreenBufferSize(__hout, cr);//���û�����
		}
	}
	else {//cr.X > cur_buffer_cols
		if (cr.Y >= cur_buffer_lines) {
			SetConsoleScreenBufferSize(__hout, cr);//���û�����
			SetConsoleWindowInfo(__hout, true, &rect);//���ô���
		}
		else {	//cr.Y < cur_buffer_lines
			COORD tmpcr;
			tmpcr.X = cr.X;
			tmpcr.Y = cur_buffer_lines;
			SetConsoleScreenBufferSize(__hout, tmpcr);//���û�����

			SetConsoleWindowInfo(__hout, true, &rect);//���ô���
			SetConsoleScreenBufferSize(__hout, cr);//���û�����
		}
	}

	return;
}

