//1850059 ��1�� ��־Զ

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

const int MinRow = 7;        //������С��
const int MinCol = 7;        //������С��
const int MaxRow = 9;        //���������
const int MaxCol = 9;        //���������
const int MaxColors = 7;     //��ɫ���ֵ
const int FontSize1 = 16;    //ģʽ1-3�����С
const int FontSize2 = 36;    //ģʽ4-8�����С
const int WindowXSize1 = 80; //��ʼ���ں����С
const int WindowYSize1 = 26; //��ʼ���������С
const int WindowXSize2 = 35; //ģʽ4���ں����С
const int WindowYSize2 = 13; //ģʽ4���������С
const int WindowXSize3 = 39; //ģʽ5���ں����С
const int WindowYSize3 = 19; //ģʽ5���������С
const int MaxPath = 200;     //Ѱ·�㷨���洢�ĵ�
const int BallsEachStep = 3; //ÿ�غ����ӵĲ�����
const int MinBallsCount = 5; //�����ߵ���С������
const int Delay1 = 25;       //�����ӳ�

const char helpInformation[6][80] = {
	"�����������������", 
	"����������(7-9): ", 
	"����������(7-9): ", 
	"����End����: ", 
	"������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺", 
	"������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺"
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
