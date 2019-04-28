//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

const int maxLayer = 10;
const int SPEED1 = 1000;
const int SPEED2 = 500;
const int SPEED3 = 200;
const int SPEED4 = 20;
const int SPEED5 = 1;
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

int A[maxLayer], B[maxLayer], C[maxLayer];
int top_A, top_B, top_C, speed, showArray;

int Speed()
{
	if (speed == 1)
		return SPEED1;
	else if (speed == 2)
		return SPEED2;
	else if (speed == 3)
		return SPEED3;
	else if (speed == 4)
		return SPEED4;
	else if (speed == 5)
		return SPEED5;
	else
		return 0;
}

void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

void print_stack(int layer)
{
	cout << " A:";
	for (int i = 0; i < top_A; i++)
	{
		cout << setw(2) << A[i];
	}
	for (int i = top_A; i < 10; i++)
	{
		cout << "  ";
	}
	cout << " B:";
	for (int i = 0; i < top_B; i++)
	{
		cout << setw(2) << B[i];
	}
	for (int i = top_B; i < 10; i++)
	{
		cout << "  ";
	}
	cout << " C:";
	for (int i = 0; i < top_C; i++)
	{
		cout << setw(2) << C[i];
	}
	for (int i = top_C; i < 10; i++)
	{
		cout << "  ";
	}
	cout << endl;
}

void print_array()
{
	for (int i = 0; i < top_A; i++)
	{
		gotoxy(hout, 10, maxLayer - i + 3);
		cout << setw(2) << A[i];
	}
	gotoxy(hout, 10, maxLayer - (top_A) + 3);
	cout << "  ";
	for (int i = 0; i < top_B; i++)
	{
		gotoxy(hout, 20, maxLayer - i + 3);
		cout << setw(2) << B[i];
	}
	gotoxy(hout, 20, maxLayer - (top_B) + 3);
	cout << "  ";
	for (int i = 0; i < top_C; i++)
	{
		gotoxy(hout, 30, maxLayer - i + 3);
		cout << setw(2) << C[i];
	}
	gotoxy(hout, 30, maxLayer - (top_C) + 3);
	cout << "  ";
	if (!Speed() && showArray)
	{
		while (_getch() != 13)
			;
	}
}

void move_stack(char start, char end)
{
	if (end == 'A')
	{
		if (start == 'B')
		{
			A[top_A++] = B[--top_B];
		}
		if (start == 'C')
		{
			A[top_A++] = C[--top_C];
		}
	}
	if (end == 'B')
	{
		if (start == 'A')
		{
			B[top_B++] = A[--top_A];
		}
		if (start == 'C')
		{
			B[top_B++] = C[--top_C];
		}
	}
	if (end == 'C')
	{
		if (start == 'A')
		{
			C[top_C++] = A[--top_A];
		}
		if (start == 'B')
		{
			C[top_C++] = B[--top_B];
		}
	}
}

void print_Hanoi(int layer, char start, char end, int steps)
{
	if (Speed())
	{
		Sleep(Speed());
	}
	else
	{
		while (_getch() != 13)
			;
	}
	print_array();
	gotoxy(hout, 0, maxLayer + 10);
	cout << "第" << setw(4) << steps << "步(" << layer << "#: " << start << "-->" << end << ")  ";
	if (showArray)
	{
		print_stack(layer);
	}
}

void Hanoi(int layer, char start, char end)
{
	static int steps = 0;
	if (layer == 1)
	{
		steps++;
		print_Hanoi(layer, start, end, steps);
		move_stack(start, end);
		return;
	}
	char middle;
	middle = 'A' + 'B' + 'C' - start - end;
	Hanoi(layer - 1, start, middle);
	steps++;
	print_Hanoi(layer, start, end, steps);
	move_stack(start, end);
	Hanoi(layer - 1, middle, end);
}

int main()
{
	int layer;
	char start, end;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-" << maxLayer << "): ";
		cin >> layer;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (layer <= 0 || layer > maxLayer)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "请输入起始柱(A-C): ";
		cin >> start;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (!((start >= 'A' && start <= 'C') || (start >= 'a' && start <= 'c')))
		{
			continue;
		}
		start = (start >= 'a' && start <= 'c') ? start - ('a' - 'A') : start;
		break;
	}
	while (1)
	{
		cout << "请输入目标柱(A-C): ";
		cin >> end;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (!((end >= 'A' && end <= 'C') || (end >= 'a' && end <= 'c')))
		{
			continue;
		}
		if (start == end)
		{
			cout << "目标柱(" << end << ")不能与起始柱(" << start << ")相同" << endl;
			continue;
		}
		end = (end >= 'a' && end <= 'c') ? end - ('a' - 'A') : end;
		break;
	}
	while (1)
	{
		cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短) : ";
		cin >> speed;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (speed < 0 || speed > 5)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示): ";
		cin >> showArray;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (showArray < 0 || showArray > 1)
		{
			continue;
		}
		break;
	}
	
	if (start == 'A')
	{
		for (int i = 0; i < layer; i++)
		{
			A[i] = layer - i;
		}
		top_A = layer;
	}
	else if (start == 'B')
	{
		for (int i = 0; i < layer; i++)
		{
			B[i] = layer - i;
		}
		top_B = layer;
	}
	else
	{
		for (int i = 0; i < layer; i++)
		{
			C[i] = layer - i;
		}
		top_C = layer;
	}

	system("cls");
	cout << "从 " << start << " 移动到 " << end << "，共 " << layer
		<< " 层，延时设置为 " << speed << "，" << (showArray ? "" : "不") << "显示内部数组值" << endl;
	
	gotoxy(hout, 9, maxLayer + 4);
	cout << "=========================";
	gotoxy(hout, 9, maxLayer + 5);
	cout << "  A         B         C";
	gotoxy(hout, 0, maxLayer + 10);
	cout << "初始:";
	if (showArray)
	{
		print_stack(layer);
	}
	Hanoi(layer, start, end);
	gotoxy(hout, 0, maxLayer + 12);
	return 0;
}
