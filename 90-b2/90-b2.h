//1850059 计1班 杨志远

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "cmd_console_tools.h"
using namespace std;

const int MinRow = 7;        //棋盘最小行
const int MinCol = 7;        //棋盘最小列
const int MaxRow = 9;        //棋盘最大行
const int MaxCol = 9;        //棋盘最大列
const int MaxColors = 7;     //颜色最大值
const int FontSize1 = 16;    //模式1-3字体大小
const int FontSize2 = 36;    //模式4-8字体大小
const int WindowXSize1 = 80; //初始窗口横向大小
const int WindowYSize1 = 26; //初始窗口纵向大小
const int WindowXSize2 = 35; //模式4窗口横向大小
const int WindowYSize2 = 13; //模式4窗口纵向大小
const int WindowXSize3 = 39; //模式5窗口横向大小
const int WindowYSize3 = 19; //模式5窗口纵向大小
const int MaxPath = 200;     //寻路算法最多存储的点
const int BallsEachStep = 3; //每回合增加的彩球数
const int MinBallsCount = 5; //连成线的最小彩球数
const int Delay1 = 25;       //动画延迟

const char helpInformation[6][80] = {
	"输入错误，请重新输入", 
	"请输入列数(7-9): ", 
	"请输入行数(7-9): ", 
	"输入End结束: ", 
	"请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：", 
	"请以字母+数字形式[例：c2]输入要移动球的目的坐标："
};

//90-b2-tools
void exchange(int &x, int &y);
void input_information(int winX, int inputMode, int mode, int *row = NULL, int *col = NULL, char *instruction = NULL ,int realRow = -1, int realCol = -1);
void input_instruction(int mode, int map[][MaxCol + 1], int *sX, int *sY, int *eX, int *eY, int row, int col);
void create_balls(int map[][MaxCol + 1], int row, int col, int balls, int ballsColor[] = NULL, int ballsX[] = NULL, int ballsY[] = NULL);
void set_balls_color(int ballsColor[], int colors);
int find_path(int row, int col, int startX, int startY, int endX, int endY, int map[][MaxCol + 1], int *pointListX, int *pointListY);
void move_map(int map[][MaxCol + 1], int dX, int dY, int sX, int sY);
bool game_over(int map[][MaxCol + 1], int row, int col);
int check_map(int map[][MaxCol + 1], int row, int col, int x, int y, int *score, int *scoreAll, bool consoleMode = false, int ballsRemoved[] = NULL);
void print_console_border(int mode);
int statistics_balls(int map[][MaxCol + 1], int row, int col, int color);

//90-b2-base
void print_map_base(int map[][MaxCol + 1], int row, int col);
void print_map_update(int map[][MaxCol + 1], int row, int col, int printMode);
void draw_path(int map[][MaxCol + 1], int row, int col, int pathX[], int pathY[], int steps);
void print_map_path(int map[][MaxCol + 1], int row, int col, int pathX[], int pathY[], int steps);
void mode_2(int map[][MaxCol + 1], int row, int col);
void mode_3(int map[][MaxCol + 1], int row, int col);
void print_balls_color(int ballsColor[], int colors);

//90-b2-console
void draw_framework(int row, int col, int printMode);
void draw_points(const int map[][MaxCol + 1], int row, int col, int printMode);
void mode_6(int map[][MaxCol + 1], int row, int col);
void mode_7_and_8(int map[][MaxCol + 1], int row, int col, int mode);
