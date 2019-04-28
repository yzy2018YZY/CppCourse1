#pragma once

#include <Windows.h>

/* ������ɫ���ú궨��ȡ�����֣�������䣩 */
#define COLOR_BLACK		0	//��
#define COLOR_BLUE		1	//��
#define COLOR_GREEN		2	//��
#define COLOR_CYAN		3	//��
#define COLOR_RED		4	//��
#define COLOR_PINK		5	//��
#define COLOR_YELLOW	6	//��
#define COLOR_WHITE		7	//��
#define COLOR_HBLACK	8	//����
#define COLOR_HBLUE		9	//����
#define COLOR_HGREEN	10	//����
#define COLOR_HCYAN		11	//����
#define COLOR_HRED		12	//����
#define COLOR_HPINK		13	//����
#define COLOR_HYELLOW	14	//����
#define COLOR_HWHITE	15	//����

/* ���������̬ */
#define CURSOR_VISIBLE_FULL			0	//�����ʾ��ȫ��ɫ��
#define CURSOR_VISIBLE_HALF			1	//�����ʾ�����ɫ��
#define CURSOR_VISIBLE_NORMAL		2	//�����ʾ�����ߣ�ȱʡΪ�˷�ʽ��
#define CURSOR_INVISIBLE			3	//��겻��ʾ

/* cmd_console_tools�µĺ������� */

/* ��������ɫ���á�������á��ַ�/�ַ�����ʾ */
void cls      (void);
void setcolor (const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE);
void gotoxy   (const int X, const int Y);
void setcursor(const int options);
void showch   (const int X, const int Y, const char ch, const int bg_color = COLOR_BLACK, const int fg_color = COLOR_WHITE, const int rpt = 1);

/* �봰�ڴ�С�йصĺ��� */
void setconsoleborder(int set_cols, int set_lines, int set_buffer_cols = -1, int set_buffer_lines = -1);