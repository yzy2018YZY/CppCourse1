//1850059 ��1�� ��־Զ

#include "90-b2.h"

static void print_map(int map[][MaxCol + 1], int row, int col, int printMode = 0, int tempArray[][MaxCol + 1] = NULL);

void mode_2(int map[][MaxCol + 1], int row, int col)
{
	int pathX[MaxPath], pathY[MaxPath], steps = 0, sX = -1, sY = -1, eX = -1, eY = -1, ballsColor[BallsEachStep];
	set_balls_color(ballsColor, BallsEachStep);
	create_balls(map, row, col, BallsEachStep, ballsColor);
	print_balls_color(ballsColor, BallsEachStep);
	input_instruction(2, map, &sX, &sY, &eX, &eY, row, col);
	steps = find_path(row, col, sX, sY, eX, eY, map, pathX, pathY); 
	if (steps == 0)
		cout << "�޷��ҵ�·��              " << endl;
	else
	{
		cout << endl << endl; 
		draw_path(map, row, col, pathX, pathY, steps);
		cout << endl;
		print_map_path(map, row, col, pathX, pathY, steps);
	}
}

void mode_3(int map[][MaxCol + 1], int row, int col)
{
	int pathX[MaxPath], pathY[MaxPath], ballsColor[BallsEachStep], steps = 0, sX = -1, sY = -1, eX = -1, eY = -1, scoreAll = 0, score = 0, ballsX[MaxColors], ballsY[MaxColors];
	char instructionA[5] = "", instructionB[5] = "";
	set_balls_color(ballsColor, BallsEachStep);
	while (!game_over(map, row, col))
	{
		input_instruction(3, map, &sX, &sY, &eX, &eY, row, col);
		steps = find_path(row, col, sX, sY, eX, eY, map, pathX, pathY);
		if (steps == 0)
			cout << "�޷��ҵ�·��              " << endl;
		else
		{
			move_map(map, eX, eY, sX, sY);
			if (check_map(map, row, col, eX, eY, &score, &scoreAll) == 0)
			{
				set_balls_color(ballsColor, BallsEachStep);
				create_balls(map, row, col, BallsEachStep, ballsColor, ballsX, ballsY);
				for(int i = 0; i < BallsEachStep; i++)
					check_map(map, row, col, ballsX[i], ballsY[i], &score, &scoreAll);
			}
		}
		print_map_update(map, row, col, 0);
		cout << "���ε÷�: " << score << "  �ܵ÷�: " << scoreAll << endl;
		print_map_update(map, row, col, 1);
		print_balls_color(ballsColor, BallsEachStep);
	
	}
	cout << endl << "��Ϸ����" << endl;
}

//printMode  0:��ɫ  1:·��*  2:��ɫ+·��
static void print_map(int map[][MaxCol + 1], int row, int col, int printMode, int tempArray[][MaxCol + 1])
{
	if (printMode == 1 && tempArray == NULL)
		return;
	cout << "  |";
	for (int i = 0; i < col; i++)
		cout << "  " << i + 1;
	cout << endl << "--+";
	for (int i = 0; i < col; i++)
		cout << "---";
	cout << "-" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << char('A' + i) << " |";
		for (int j = 0; j < col; j++)
		{
			if (printMode == 1)
				cout << ((tempArray[i][j] == -1) ? "  *" : "  0");
			else
			{
				cout << "  ";
				if (printMode == 0 && map[i][j] || printMode == 2 && tempArray[i][j])
					setcolor(14, (printMode == 0 ? map[i][j] : 1));
				cout << map[i][j];
				setcolor();
			}
		}
		cout << endl;
	}
	cout << endl;
}

void print_map_base(int map[][MaxCol + 1], int row, int col)
{
	cout << "��ʼ����:" << endl;
	print_map(map, row, col);
}

void print_map_update(int map[][MaxCol + 1], int row, int col, int printMode)
{
	cout << (printMode == 1 ? "��ǰ����:" : "�ƶ��������:") << endl;
	print_map(map, row, col);
}

void draw_path(int map[][MaxCol + 1], int row, int col, int pathX[], int pathY[], int steps)
{
	int temp[MaxRow + 1][MaxCol + 1] = { 0 };
	for (int k = 0; k < steps; k++)
		temp[pathY[k]][pathX[k]] = -1;
	cout << "���ҽ�����飺" << endl;
	print_map(map, row, col, 1, temp);
}

void print_map_path(int map[][MaxCol + 1], int row, int col, int pathX[], int pathY[], int steps)
{
	int temp[MaxRow + 1][MaxCol + 1] = { 0 };
	for (int k = 0; k < steps; k++)
		temp[pathY[k]][pathX[k]] = -1;
	cout << "�ƶ�·��(��ͬɫ��ʶ)��" << endl;
	print_map(map, row, col, 2, temp);
}

void print_balls_color(int ballsColor[], int colors)
{
	cout << "֮��" << BallsEachStep << "�������ɫ:";
	for (int i = 0; i < colors; i++)
		cout << " " << ballsColor[i];
	cout << endl;
}
