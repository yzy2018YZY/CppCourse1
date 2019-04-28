#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;

/* 静态全局，只在本源程序文件中有效（为防止同名，静态全局一般建议加__做为变量名开始） */
static const HANDLE __hout = GetStdHandle(STD_OUTPUT_HANDLE);		//取标准输出设备对应的句柄
static const HANDLE __hin = GetStdHandle(STD_INPUT_HANDLE);		//取标准输入设备对应的句柄

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(void)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(__hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(__hout, (TCHAR) ' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(__hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(__hout, coord);
	return;
}

/***************************************************************************
  函数名称：
  功    能：设置指定的颜色
  输入参数：const int bg_color ：背景色（0-15）
			const int fg_color ：前景色（0-15）
  返 回 值：
  说    明：颜色的取值由背景色+前景色组成，各16种
			fg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
					  8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
			bg_color：0-7    黑   蓝   绿   青   红   粉   黄   白
					  8-15 亮黑 亮蓝 亮绿 亮青 亮红 亮粉 亮黄 亮白
			最终的颜色为 背景色*16+前景色
***************************************************************************/
void setcolor(const int bg_color, const int fg_color)
{
	SetConsoleTextAttribute(__hout, bg_color * 16 + fg_color);
}

/***************************************************************************
  函数名称：
  功    能：将光标移动到指定位置
  输入参数：const int X       ：X轴坐标（列）
			const int Y       ：Y轴坐标（行）
  返 回 值：
  说    明：屏幕左上角坐标为(0,0)，在cmd窗口的大小未被调整的情况下，Win10为：
			横向x轴，对应列(0-119)
			纵向y轴，对应行(0-29)
***************************************************************************/
void gotoxy(const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(__hout, coord);
}

/***************************************************************************
  函数名称：
  功    能：设置光标状态（显示/不显示/全高/半高/横线等）
  输入参数：const int option：要设置的光标状态
  返 回 值：
  说    明：
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
		default: //缺省显示光标，横线
			cursor_info.bVisible = 1;
			cursor_info.dwSize = 25;
			break;
	}
	SetConsoleCursorInfo(__hout, &cursor_info);
}

/***************************************************************************
  函数名称：
  功    能：在指定位置，用指定颜色，显示一个字符若干次
  输入参数：const int X       ：X轴坐标（列）
			const int Y       ：Y轴坐标（行）
			const char ch     ：要输出的字符值
			const int bg_color：背景色（缺省为COLOR_BLACK）
			const int fg_color：背景色（缺省为COLOR_WHITE）
			const int rpt     ：重复次数（缺省为1）
  返 回 值：
  说    明：X、Y的范围参见gotoxy函数的说明
***************************************************************************/
void showch(const int X, const int Y, const char ch, const int bg_color, const int fg_color, const int rpt)
{
	int i;

	gotoxy(X, Y);
	setcolor(bg_color, fg_color);

	/* 循环n次，打印字符ch */
	for (i = 0; i < rpt; i++)
		putchar(ch);
}

/***************************************************************************
  函数名称：
  功    能：改变cmd窗口的大小及缓冲区的大小
  输入参数：const int cols         ：新的列数
			const int lines        ：新的行数
			const int buffer_cols  ：新的缓冲区列数
			const int buffer_lines ：新的缓冲区行数
  返 回 值：
  说    明：必须先设置缓冲区，再设置窗口大小，
			否则若窗口大小大于当前缓冲区（未设置前）则设置失败
***************************************************************************/
void setconsoleborder(int set_cols, int set_lines, int set_buffer_cols, int set_buffer_lines)
{
	/* 去当前系统允许的窗口的行列最大值 */
	COORD max_coord;
	max_coord = GetLargestConsoleWindowSize(__hout); /* .X 和 .Y 分别是窗口的列和行的最大值 */

	/* 处理设置窗口的行列的非法值 */
	if (set_cols <= 0 || set_lines <= 0)
		return;
	if (set_cols > max_coord.X)
		set_cols = max_coord.X;
	if (set_lines > max_coord.Y)
		set_lines = max_coord.Y;

	/* 设置窗口的行列大小（从0开始，0 ~ lines-1, 0 ~ cols-1）*/
	SMALL_RECT rect;
	rect.Top = 0;
	rect.Bottom = set_lines - 1;
	rect.Left = 0;
	rect.Right = set_cols - 1;

	/* 设置缓冲区的行列大小(缺省或小于窗口值则与窗口值一样) */
	COORD cr;
	cr.X = (set_buffer_cols == -1 || set_buffer_cols < set_cols) ? set_cols : set_buffer_cols;		//未给出或给出的值小于set_cols则用set_cols，未控制上限
	cr.Y = (set_buffer_lines == -1 || set_buffer_lines < set_lines) ? set_lines : set_buffer_lines;	//未给出或给出的值小于set_lines则用set_lines，未控制上限

	/* 取当前窗口及缓冲区的大小(就是getconsoleborder) */
	int cur_cols, cur_lines, cur_buffer_cols, cur_buffer_lines;
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	GetConsoleScreenBufferInfo(__hout, &binfo);

	cur_cols = binfo.srWindow.Right - binfo.srWindow.Left + 1;	//可见窗口的列数
	cur_lines = binfo.srWindow.Bottom - binfo.srWindow.Top + 1;	//可见窗口的行数
	cur_buffer_cols = binfo.dwSize.X;							//缓冲区的列数
	cur_buffer_lines = binfo.dwSize.Y;							//缓冲区的行数

	cls();
	/* 设置顺序(保证设置窗口大小时，现缓冲区的列值>窗口值) */
	if (cr.X <= cur_buffer_cols) {
		if (cr.Y <= cur_buffer_lines) {
			SetConsoleWindowInfo(__hout, true, &rect);//设置窗口
			SetConsoleScreenBufferSize(__hout, cr);//设置缓冲区
		}
		else { //cr.Y > cur_buffer_lines，先要让缓冲区的行数变大
			COORD tmpcr;
			tmpcr.X = cur_buffer_cols;
			tmpcr.Y = cr.Y;
			SetConsoleScreenBufferSize(__hout, tmpcr);//设置缓冲区

			SetConsoleWindowInfo(__hout, true, &rect);//设置窗口
			SetConsoleScreenBufferSize(__hout, cr);//设置缓冲区
		}
	}
	else {//cr.X > cur_buffer_cols
		if (cr.Y >= cur_buffer_lines) {
			SetConsoleScreenBufferSize(__hout, cr);//设置缓冲区
			SetConsoleWindowInfo(__hout, true, &rect);//设置窗口
		}
		else {	//cr.Y < cur_buffer_lines
			COORD tmpcr;
			tmpcr.X = cr.X;
			tmpcr.Y = cur_buffer_lines;
			SetConsoleScreenBufferSize(__hout, tmpcr);//设置缓冲区

			SetConsoleWindowInfo(__hout, true, &rect);//设置窗口
			SetConsoleScreenBufferSize(__hout, cr);//设置缓冲区
		}
	}

	return;
}

