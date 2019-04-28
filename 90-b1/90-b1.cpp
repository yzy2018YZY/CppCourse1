//1850059 ��1�� ��־Զ

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
using namespace std;

const int maxLayer = 10;
const int moveDown = 10;
const int moveDownGraphics = 5;
const int windowX = 100;
const int windowY = 30;
const int SPEED1 = 1000;
const int SPEED2 = 250;
const int SPEED3 = 70;
const int SPEED4 = 30;
const int SPEED5 = 0;

int stack[3][maxLayer];
int top[5];
int steps;

//���������ģʽ����ӳ�
int Speed(int speed)
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
		return -1;
}

//���ջ����Ϣ
void print_stack(int layer)
{
	cout << " A:";
	for (int i = 0; i < top[0]; i++)
		cout << setw(2) << stack[0][i];
	for (int i = top[0]; i < 10; i++)
		cout << "  ";
	cout << " B:";
	for (int i = 0; i < top[1]; i++)
		cout << setw(2) << stack[1][i];
	for (int i = top[1]; i < 10; i++)
		cout << "  ";
	cout << " C:";
	for (int i = 0; i < top[2]; i++)
		cout << setw(2) << stack[2][i];
	for (int i = top[2]; i < 10; i++)
		cout << "  ";
	cout << endl;
}

//�����ʽ
void print_array_vertical(int mode, int speed)
{
	for (int i = 0; i < top[0]; i++)
	{
		gotoxy(10, maxLayer + ((mode == 8 || mode == 9) ? moveDown + moveDownGraphics: 0) - i + 1);
		cout << setw(2) << stack[0][i];
	}
	gotoxy(10, maxLayer + ((mode == 8 || mode == 9) ? moveDown + moveDownGraphics: 0) - (top[0]) + 1);
	cout << "  ";
	for (int i = 0; i < top[1]; i++)
	{
		gotoxy(20, maxLayer + ((mode == 8 || mode == 9) ? moveDown + moveDownGraphics: 0) - i + 1);
		cout << setw(2) << stack[1][i];
	}
	gotoxy(20, maxLayer + ((mode == 8 || mode == 9) ? moveDown + moveDownGraphics: 0) - (top[1]) + 1);
	cout << "  ";
	for (int i = 0; i < top[2]; i++)
	{
		gotoxy(30, maxLayer + ((mode == 8 || mode == 9) ? moveDown + moveDownGraphics: 0) - i + 1);
		cout << setw(2) << stack[2][i];
	}
	gotoxy(30, maxLayer + ((mode == 8 || mode == 9) ? moveDown + moveDownGraphics: 0) - (top[2]) + 1);
	cout << "  ";
	if (Speed(speed) == -1 && (mode == 4))
		while (_getch() != '\r')
			;
}

//��ͼ�λ�����ֱ�ƶ�����һ��
void move_ring_horizonal(int x, int i, int color, int length, int speed)
{
	showch(x - length / 2, i, ' ', color, COLOR_WHITE, length);
	Sleep(Speed(speed) >= 0 ? Speed(speed) : 0);
	showch(x - length / 2, i, ' ', COLOR_BLACK, COLOR_WHITE, length);
	if (i >= moveDownGraphics - 2)
		showch(x, i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
}

//��ͼ�λ����ƶ���
void move_ring(int x1, int x2, int y1, int y2, int color, int length, int speed)
{
	setcursor(CURSOR_INVISIBLE);
	for (int i = y1; i != moveDownGraphics - 4; i--)
		move_ring_horizonal(x1, i, color, length, speed);
	for (int i = x1 - length / 2; i != x2 - length / 2; x1 < x2 ? i++ : i--)
	{
		showch(i, moveDownGraphics - 4, ' ', color, COLOR_WHITE, length);
		Sleep(Speed(speed) >= 0 ? Speed(speed) : 0);
		showch(i, moveDownGraphics - 4, ' ', COLOR_BLACK, COLOR_WHITE, length);
	}
	for (int i = moveDownGraphics - 4; i != y2; i++)
		move_ring_horizonal(x2, i, color, length, speed);
	showch(x2 - length / 2, y2, ' ', color, COLOR_WHITE, length);
	showch(0, windowY - 3, ' ', COLOR_BLACK, COLOR_WHITE, 1);
	if (Speed(speed) == -1)
		while (_getch() != '\r')
			;
}

//���������ŵ���ƶ���Ϣ
void print_Hanoi_one_line(int mode, int layer, char start, char end, int steps, int speed)
{
	if (mode == 4)
	{
		if (Speed(speed) != -1)
			Sleep(Speed(speed));
	}
	if (mode == 4 || mode == 8 || mode == 9)
		gotoxy(0, maxLayer + ((mode == 8 || mode == 9) ? moveDownGraphics + moveDown : 0) + 5);
	if (mode == 2 || mode == 3 || mode == 4 || mode == 8 || mode == 9)
		cout << "��" << setw(4) << steps << "��(" << setw(2) << layer << "#: " << start << "-->" << end << ")";
	if (mode == 1)
		cout << layer << "#: " << start << "-->" << end;
	if (mode == 1 || mode == 2)
		cout << endl;
	if (mode == 3 || mode == 4 || mode == 8 || mode == 9)
		print_stack(layer);
}

//�ƶ�������ܺ���
void move_stack_and_print_all_information(int mode, int layer, char start, char end, int steps, int speed)
{
	stack[end - 'A'][top[end - 'A']++] = stack[start - 'A'][--top[start - 'A']];
	print_Hanoi_one_line(mode, layer, start, end, steps, speed);
	if (mode == 4 || mode == 8 || mode == 9)
		print_array_vertical(mode, speed);
	if (mode == 8 || mode == 9)
		move_ring(12 + (start - 'A') * 32, 12 + (end - 'A') * 32, maxLayer + moveDownGraphics - top[start - 'A'] - 1, maxLayer + moveDownGraphics - top[end - 'A'], layer, layer * 2 + 1, speed);
}

//��ŵ�����ĺ���
void Hanoi(int mode, int layer, char start, char end, int speed)
{
	if (layer == 1)
	{
		move_stack_and_print_all_information(mode, layer, start, end, ++steps, speed);
		return;
	}
	char middle = 'A' + 'B' + 'C' - start - end;
	Hanoi(mode, layer - 1, start, middle, speed);
	move_stack_and_print_all_information(mode, layer, start, end, ++steps, speed);
	Hanoi(mode, layer - 1, middle, end, speed);
}

//������������ʾ
void welcome_information()
{
	cout << "---------------------------------" << endl;
	cout << "1.������" << endl;
	cout << "2.������(������¼)" << endl;
	cout << "3.�ڲ�������ʾ(����)" << endl;
	cout << "4.�ڲ�������ʾ(���� + ����)" << endl;
	cout << "5.ͼ�ν� - Ԥ�� - ������Բ��" << endl;
	cout << "6.ͼ�ν� - Ԥ�� - ����ʼ���ϻ�n������" << endl;
	cout << "7.ͼ�ν� - Ԥ�� - ��һ���ƶ�" << endl;
	cout << "8.ͼ�ν� - �Զ��ƶ��汾" << endl;
	cout << "9.ͼ�ν� - ��Ϸ��" << endl;
	cout << "0.�˳�" << endl;
	cout << "----------------------------------" << endl;
	cout << "[��ѡ��:]";
}

//ѡ��ģʽ
int select_mode()
{
	while (1)
	{
		char ch = _getch();
		if (ch >= '0' && ch <= '9')
			return ch - '1' + 1;
	}
}

//������뻺����
inline void clearCin()
{
	cin.clear();
	cin.ignore(999999999, '\n');
}

//���������ܺ���
int input_information(int mode, int *layer, char *start, char *end, int *speed)
{
	while (mode != 10)
	{
		cout << "�����뺺ŵ���Ĳ���(1-" << maxLayer << "): " << endl;
		cin >> *layer;
		clearCin();
		if (*layer <= 0 || *layer > maxLayer)
			continue;
		break;
	}
	while (mode != 10)
	{
		cout << "��������ʼ��(A-C): " << endl;
		cin >> *start;
		clearCin();
		(*start) = ((*start) >= 'a' && (*start) <= 'c') ? (*start) - ('a' - 'A') : (*start);
		if (!(((*start) >= 'A' && (*start) <= 'C')))
			continue;
		break;
	}
	while (mode != 10)
	{
		cout << "������Ŀ����(A-C): " << endl;
		cin >> *end;
		clearCin();
		(*end) = (*end >= 'a' && *end <= 'c') ? (*end) - ('a' - 'A') : (*end);
		if (!(((*end) >= 'A' && (*end) <= 'C')))
			continue;
		if (*start == *end)
		{
			cout << "Ŀ����(" << (*end) << ")��������ʼ��(" << (*start) << ")��ͬ" << endl;
			continue;
		}
		break;
	}
	while (mode == 4 || mode == 8)
	{
		cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���) : " << endl;
		if (!(cin >> *speed))
		{
			clearCin();
			continue;
		}
		clearCin();
		if (*speed < 0 || *speed > 5)
			continue;
		break;
	}
	while (mode == 10)
	{
		char str[20] = "*";  //���ⵥ���ַ��Կ�
		gotoxy(0, maxLayer + moveDown + moveDownGraphics + 6);
		cout << "�������ƶ�������(������ʽ��AC = A���˵������ƶ���C��Q = �˳�) ��";
		for (int i = 1; i <= 15; i++)  //�������15���ַ�
		{
			str[i] = _getch(); //���밴��
			if (str[i] == '\r')  //��������˻س������˳�ѭ��
				break;
			if (str[i] >= 33 && str[i] <= 126 && str[i - 1] >= 33 && str[i - 1] <= 126) //�ж��Ƿ�Ϊ������ַ�
				cout << str[i];
		}
		str[1] >= 'a' && str[1] <= 'z' ? str[1] = str[1] - 'a' + 'A' : 0 ;
		str[2] >= 'a' && str[1] <= 'z' ? str[2] = str[2] - 'a' + 'A' : 0 ;
		gotoxy(0, maxLayer + moveDown + moveDownGraphics + 6);
		for (int i = 0; i < windowX; i++)
			cout << "  ";
		if (strlen(str) == 3 && str[1] == 'Q')
			return 0;
		if(strlen(str) == 4 && str[1] >= 'A' && str[1] <= 'C' && str[2] >= 'A' && str[2] <= 'C' && str[1] != str[2])
			return (str[1] - 'A') * 10 + str[2] - 'A';
	}
	return -1;
}

//��ʼ��
void initialize(int mode, int layer, char start, char end, int speed)
{
	if (mode == 3 || mode == 4 || mode == 8 || mode == 9)
	{
		top[0] = top[1] = top[2] = 0;
		for (int i = 0; i < layer; i++)
			stack[start - 'A'][i] = layer - i;
		top[start - 'A'] = layer;
	}
	if (mode == 4 || mode == 8 || mode == 9)
	{
		cout << " �� " << start << " �ƶ��� " << end << "���� " << layer << " �㣬��ʱ����Ϊ " << speed << endl;
		gotoxy(9, maxLayer + ((mode == 8 || mode == 9) ? moveDownGraphics + moveDown : 0) + 2);
		cout << "=========================";
		gotoxy(9, maxLayer + ((mode == 8 || mode == 9) ? moveDownGraphics + moveDown : 0) + 3);
		cout << "  A         B         C";
		gotoxy(0, maxLayer + ((mode == 8 || mode == 9) ? moveDownGraphics + moveDown : 0) + 5);
		cout << "��ʼ:";
		print_stack(layer);
		Sleep(200);
		if (Speed(speed) == -1 && (mode == 4))
			while (_getch() != '\r')
				;
		gotoxy(0, maxLayer + ((mode == 8 || mode == 9) ? moveDownGraphics + moveDown : 0) + 5);
	}
	steps = 0;
	cout << endl;
}

//��ͼ�λ�����������
void draw_columns()
{
	showch(1 , maxLayer + moveDownGraphics, ' ', COLOR_HYELLOW, COLOR_WHITE, 23);
	showch(33, maxLayer + moveDownGraphics, ' ', COLOR_HYELLOW, COLOR_WHITE, 23);
	showch(65, maxLayer + moveDownGraphics, ' ', COLOR_HYELLOW, COLOR_WHITE, 23);
	Sleep(Speed(3));
	for (int i = maxLayer + moveDownGraphics; i >= moveDownGraphics - 2; i--)
	{
		showch(12, i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		showch(44, i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		showch(76, i, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		Sleep(Speed(3));
	}
	showch(0, windowY - 3, ' ', COLOR_BLACK, COLOR_WHITE, 1);
	Sleep(Speed(2));
}

//��ͼ�λ������ƻ�
void draw_ring(int layer, char start)
{
	for (int i = layer; i > 0; i--)
	{
		showch( - i + 12 + (start - 'A') * 32, maxLayer + moveDownGraphics + i - layer - 1, 
			' ', i, COLOR_WHITE, i * 2 + 1);
		Sleep(Speed(3));
	}
	showch(0, windowY - 3, ' ', COLOR_BLACK, COLOR_WHITE, 1);
	Sleep(Speed(2));
}

//�ж���Ϸ����
bool game_over(int layer, int end)
{
	return (top[end - 'A'] == layer);
}

//��Ϸģʽ�Ŀ��ƺ���
void game_mode(int layer, char start, char end)
{
	print_array_vertical(8, 1);
	while (1)
	{
		int move = input_information(10, 0, 0, 0, 0);
		char playerStart = 'A' + move / 10;
		char playerEnd = 'A' + move % 10;
		gotoxy(0, maxLayer + moveDown + moveDownGraphics + 6);
		if (top[playerStart - 'A'] == 0)
		{
			cout << endl << "������������Ϊ��      " << endl;
			Sleep(750);
			gotoxy(0, maxLayer + moveDown + moveDownGraphics + 6);
			cout << endl << "                          " << endl;
			continue;
		}
		if (top[playerEnd - 'A'] > 0 && stack[playerEnd - 'A'][top[playerEnd - 'A'] - 1] > 0 && stack[playerStart - 'A'][top[playerStart - 'A'] - 1] > stack[playerEnd - 'A'][top[playerEnd - 'A'] - 1])
		{
			cout << endl << "������󣺴󻷲�����С����" << endl;
			Sleep(750);
			gotoxy(0, maxLayer + moveDown + moveDownGraphics + 6);
			cout << endl << "                          " << endl;
			continue;
		}
		move_stack_and_print_all_information(8, stack[playerStart - 'A'][top[playerStart - 'A'] - 1], playerStart, playerEnd, ++steps, 5);
		if (move == 0 || game_over(layer, end))
		{
			gotoxy(0, windowY + 5 - 3);
			cout << "��Ϸ��ֹ!!!               " << endl;
			return;
		}
	}
}

//����ѡ���ģʽ���в���
void choose_mode(int mode)
{
	int layer, speed = 1;
	char start, end;
	if (mode == 0)
		exit(0);
	if (mode != 5)
		input_information(mode, &layer, &start, &end, &speed);
	if (mode == 4)
		cls();
	if (mode >= 4 && mode <= 9)
	{
		setcursor(CURSOR_INVISIBLE);
		setconsoleborder(windowX, (mode != 8 && mode != 9) ? windowY : windowY + 5);
	}
	if(mode >= 5 && mode <= 9)
		draw_columns();
	if (mode == 4 || mode == 8 || mode == 9)
		gotoxy(0, 0);
	if (mode >= 1 && mode <= 4 || mode == 8 || mode == 9)
		initialize(mode, layer, start, end, (mode != 9) ? speed : 5);
	if (mode >= 6 && mode <= 9)
		draw_ring(layer, start);
	if (mode == 7)
	{
		char middle = 'A' + 'B' + 'C' - start - end;
		move_ring(12 + (start - 'A') * 32, 12 + ((layer % 2 ? end : middle) - 'A') * 32, maxLayer + moveDownGraphics - layer, maxLayer + moveDownGraphics - 1, COLOR_BLUE, 3, 4);
	}
	if (mode >= 1 && mode <= 4 || mode == 8)
	{
		if (mode == 8 && Speed(speed) == -1)
			while (_getch() != '\r')
				;
		Hanoi(mode, layer, start, end, speed);
	}
	if (mode == 9)
		game_mode(layer, start, end);
	if(mode == 4 || mode == 5 || mode == 8 || mode == 9)
		gotoxy(0, ((mode != 8 && mode != 9) ? windowY : windowY + 5) - 3);
	cout << endl << "���س�����" << endl;
}

int main()
{
	while (1)
	{
		setconsoleborder(windowX, windowY, windowX, 5000);
		setcursor(CURSOR_VISIBLE_NORMAL);
		welcome_information();
		int mode = select_mode();
		cout << mode << endl << endl;
		Sleep(200);
		choose_mode(mode);
		while (_getch() != '\r')
			;
	}
	return 0;
}
