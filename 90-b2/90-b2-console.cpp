//1850059 计1班 杨志远

#include "90-b2.h"

static void draw_framework_no_gap(int row, int col);
static void draw_framework_with_gap(int row, int col);
static void draw_point_movement(int map[][MaxCol + 1], int preX, int preY, int X, int Y, int color);
static int draw_score(int map[][MaxCol + 1], int row, int col, int eX, int eY, int *score, int *scoreAll, int ballsRemoved[]);
static void draw_next_balls(int map[][MaxCol + 1], int row, int col, int ballsColor[]);
static void draw_statistics(int map[][MaxCol + 1], int row, int col, int ballsRemoved[]);
static void draw_help(int sX, int sY, int eX, int eY, int row);
static bool is_point_xy(int X, int Y, int row, int col);
static bool get_point_xy(int X, int Y, int &mapX, int &mapY, int row, int col);
static bool move_in_console_left_button_or_enter(int map[][MaxCol + 1], int row, int col, int &X, int &Y, int &mapX, int &mapY, int &mapXselected, int &mapYselected, int &eX, int &eY);
static bool move_in_console_esc(int map[][MaxCol + 1], int row, int col, int &mapXselected, int &mapYselected);
static bool move_in_console_arraw_pressed(int keycode, int map[][MaxCol + 1], int row, int col, int &X, int &Y, int &mapX, int &mapY);
static bool move_in_console(int map[][MaxCol + 1], int row, int col, int &eX, int &eY, int &keyX, int &keyY, bool keyboard = false);

//printMode=4:无间隔 printMode=5:有间隔
void draw_framework(int row, int col, int printMode)
{
	if (printMode == 4)
		draw_framework_no_gap(row, col);
	else
		draw_framework_with_gap(row, col);
	setcolor();
	//cout << endl << endl;
}

static void draw_framework_no_gap(int row, int col)
{
	showstr(0, 1, "┏", 15, 0);
	showstr(2, 1, "━", 15, 0, col);
	showstr(2 * (col + 1), 1, "┓", 15, 0);
	for (int i = 0; i < row; i++)
	{
		showstr(0, i + 2, "┃", 15, 0);
		showstr(2 * (col + 1), i + 2, "┃", 15, 0);
	}
	showstr(0, row + 2, "┗", 15, 0);
	showstr(2, row + 2, "━", 15, 0, col);
	showstr(2 * (col + 1), row + 2, "┛", 15, 0);
}

static void draw_framework_with_gap(int row, int col)
{
	showstr(0, 1, "┏", 15, 0);
	for (int j = 0; j < col; j++)
	{
		showstr(2 + 4 * j, 1, "━", 15, 0);
		showstr(2 + 4 * j + 2, 1, "┳", 15, 0);
	}
	showstr(4 * col, 1, "┓", 15, 0);
	for (int i = 0; i < row; i++)
	{
		showstr(0, 2 * i + 2, "┃", 15, 0);
		for (int j = 0; j < col; j++)
		{
			showstr(2 + 4 * j, 2 * i + 2, "  ", 15, 0);
			showstr(2 + 4 * j + 2, 2 * i + 2, "┃", 15, 0);
		}
		showstr(4 * col, 2 * i + 2, "┃", 15, 0);
		showstr(0, 2 * i + 3, "┣", 15, 0);
		for (int j = 0; j < col; j++)
		{
			showstr(2 + 4 * j, 2 * i + 3, "━", 15, 0);
			showstr(2 + 4 * j + 2, 2 * i + 3, "╋", 15, 0);
		}
		showstr(4 * col, 2 * i + 3, "┫", 15, 0);
	}
	showstr(0, 2 * row + 1, "┗", 15, 0);
	for (int j = 0; j < col; j++)
	{
		showstr(2 + 4 * j, 2 * row + 1, "━", 15, 0);
		showstr(2 + 4 * j + 2, 2 * row + 1, "┻", 15, 0);
	}
	showstr(4 * col, 2 * row + 1, "┛", 15, 0);
}

//printMode=4:顺序 printMode=5:跳跃
void draw_points(const int map[][MaxCol + 1], int row, int col, int printMode)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (printMode == 4)
			{
				if (map[i][j] != 0)
					showstr(2 * (j + 1), (i + 2), "〇", map[i][j], 15);
				else
					showstr(2 * (j + 1), (i + 2), "  ", 15, 0);
			}
			else
			{
				if (map[i][j] != 0)
					showstr(2 + 4 * j, 2 * i + 2, "〇", map[i][j], 15);
			}
		}
	}
	setcolor();
	cout << endl << endl;
}

static bool is_point_xy(int X, int Y, int row, int col)
{
	int mapX = (X - 2) / 4;
	int mapY = (Y - 2) / 2;
	if (mapX >= col || mapY >= row || (fabs(((double)X - 2) / 4 - mapX) > (0.25 + 1e-4)) || (fabs((double)Y - 2) / 2 - mapY) > 1e-4)
		return false;
	return true;
}

static bool get_point_xy(int X, int Y, int &mapX, int &mapY, int row, int col)
{
	mapX = (X - 2) / 4;
	mapY = (Y - 2) / 2;
	return is_point_xy(X, Y, row, col);
}

static void draw_point_movement(int map[][MaxCol + 1], int preX, int preY, int X, int Y, int color)
{
	if (X - preX != 0)
	{
		showstr(preX * 4 + 2, Y * 2 + 2, "  ", 15, 0);
		showstr(preX * 4 + 2 + (X - preX), Y * 2 + 2, "◎", color, 15);
		Sleep(Delay1);
		showstr(preX * 4 + 2 + (X - preX), Y * 2 + 2, "  ", 15, 0);
		showstr(preX * 4 + 2 + (X - preX) * 2, Y * 2 + 2, "◎", color, 15);
		Sleep(Delay1);
		showstr(preX * 4 + 2 + (X - preX) * 2, Y * 2 + 2, "  ", 15, 0);
		showstr(preX * 4 + 2 + (X - preX) * 3, Y * 2 + 2, "◎", color, 15);
		Sleep(Delay1);
		showstr(X * 4 + 2 - (X - preX) * 2, Y * 2 + 2, "┃", 15, 0);
		showstr(X * 4 + 2, Y * 2 + 2, "◎", color, 15);
		Sleep(Delay1);
	}
	else if (Y - preY != 0)
	{
		showstr(X * 4 + 2, preY * 2 + 2, "  ", 15, 0);
		showstr(X * 4 + 2, preY * 2 + 2 + (Y - preY), "◎", color, 15);
		Sleep(Delay1 * 2);
		showstr(X * 4 + 2, Y * 2 + 2 - (Y - preY), "━", 15, 0);
		showstr(X * 4 + 2, Y * 2 + 2 - (Y - preY) * 2, "  ", 15, 0);
		showstr(X * 4 + 2, Y * 2 + 2, "◎", color, 15);
		Sleep(Delay1 * 2);
	}
}

static bool move_in_console_left_button_or_enter(int map[][MaxCol + 1], int row, int col, int &X, int &Y, int &mapX, int &mapY, int &mapXselected, int &mapYselected, int &eX, int &eY)
{
	int pointListX[MaxPath], pointListY[MaxPath];
	if (get_point_xy(X, Y, mapX, mapY, row, col))
	{
		if (map[mapY][mapX] != 0 && mapXselected == -1) //选中某个小球
		{
			mapXselected = mapX;
			mapYselected = mapY;
			showstr(X - X % 2, Y, "◎", map[mapY][mapX], 15);
		}
		else if (map[mapY][mapX] == 0 && mapXselected != -1) //判断是否可移动
		{
			int steps = find_path(row, col, mapXselected, mapYselected, mapX, mapY, map, pointListX, pointListY);
			if (steps == 0)
			{
				gotoxy(0, 2 * row + 2);
				cout << "没有可行的路线" << endl;
				Sleep(150);
			}
			else
			{
				draw_help(mapXselected, mapYselected, mapX, mapY, row);
				for (int i = 1; i < steps; i++)
					draw_point_movement(map, pointListX[i - 1], pointListY[i - 1], pointListX[i], pointListY[i], map[mapYselected][mapXselected]);
				move_map(map, mapX, mapY, mapXselected, mapYselected);
				showstr(mapX * 4 + 2, mapY * 2 + 2, "〇", map[mapY][mapX], 15);
				mapXselected = -1;
				mapYselected = -1;
				eX = mapX;
				eY = mapY;
				return true;
			}
		}
		else if (map[mapY][mapX] != 0 && mapXselected != -1)//选中其他小球
		{
			showstr(mapXselected * 4 + 2, mapYselected * 2 + 2, "〇", map[mapYselected][mapXselected], 15);
			showstr(mapX * 4 + 2, mapY * 2 + 2, "◎", map[mapY][mapX], 15);
			mapXselected = mapX;
			mapYselected = mapY;
		}
	}
	return false;
}

static bool move_in_console_esc(int map[][MaxCol + 1], int row, int col, int &mapXselected, int &mapYselected)
{
	if (mapXselected != -1)
	{
		showstr(mapXselected * 4 + 2, mapYselected * 2 + 2, "〇", map[mapYselected][mapXselected], 15);
		mapXselected = -1;
		mapYselected = -1;
		return true;
	}
	return false;
}

static bool move_in_console_arraw_pressed(int keycode, int map[][MaxCol + 1], int row, int col, int &X, int &Y, int &mapX, int &mapY)
{
	if (keycode == KB_ARROW_DOWN)
	{
		if (((Y - 2) / 2) >= row - 1)
			return false;
		mapY++;
		Y += 2;
	}
	else if (keycode == KB_ARROW_UP)
	{
		if (((Y - 2) / 2) <= 0)
			return false;
		mapY--;
		Y -= 2;
	}
	else if (keycode == KB_ARROW_LEFT)
	{
		if (((X - 2) / 4) <= 0)
			return false;
		mapX--;
		X -= 4;
	}
	else if (keycode == KB_ARROW_RIGHT)
	{
		if (((X - 2) / 4) >= col - 1)
			return false;
		mapX++;
		X += 4;
	}
	return true;
}

static bool move_in_console(int map[][MaxCol + 1], int row, int col, int &eX, int &eY, int &keyX, int &keyY, bool keyboard)
{
	int X = -1, Y = -1, ret, maction, keycode1, keycode2, mapX = 0, mapY = 0, mapXselected = -1, mapYselected = -1;
	while (1) 
	{
		ret = read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		setcolor();
		if (ret == CCT_MOUSE_EVENT) 
		{
			setcursor(CURSOR_INVISIBLE);
			switch (maction) {
				case MOUSE_ONLY_MOVED:
					if (is_point_xy(X, Y, row, col))
					{
						gotoxy(0, 2 * row + 2);
						cout << "[当前光标]" << char((Y - 2) / 2 + 'A') << "行" << (X - 2) / 4 + 1 << "列       " << endl;
					}
					break;
				case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
					get_point_xy(X, Y, mapX, mapY, row, col);
					if (move_in_console_left_button_or_enter(map, row, col, X, Y, mapX, mapY, mapXselected, mapYselected, eX, eY))
						return true;
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
					return false;
			}
		}
		else if (keyboard && ret == CCT_KEYBOARD_EVENT)
		{
			setcursor(CURSOR_VISIBLE_NORMAL);
			switch (keycode1) 
			{
				case 27: //ESC键
					move_in_console_esc(map, row, col, mapXselected, mapYselected);
					break;
				case 13: //ENTER键
					if (move_in_console_left_button_or_enter(map, row, col, keyX, keyY, mapX, mapY, mapXselected, mapYselected, eX, eY))
						return true;
					break;
				case 224: //方向键
					move_in_console_arraw_pressed(keycode2, map, row, col, keyX, keyY, mapX, mapY);
					gotoxy(0, 2 * row + 2);
					cout << "[当前位置]" << char((keyY - 2) / 2 + 'A') << "行" << (keyX - 2) / 4 + 1 << "列       " << endl;
					gotoxy(keyX, keyY);
					break;
			}
		}
	}
	setcursor(CURSOR_INVISIBLE);
	return false;
}

static int draw_score(int map[][MaxCol + 1], int row, int col, int eX, int eY, int *score, int *scoreAll, int ballsRemoved[])
{
	int x, y, result;
	result = check_map(map, row, col, eX, eY, score, scoreAll, true, ballsRemoved);
	setcolor(15, 0);
	getxy(x, y);
	gotoxy(40, 1);
	cout << "┏━━━━━┓" << endl;
	gotoxy(40, 2);
	cout << "┃得分: " << setw(4) << *scoreAll <<  "┃" << endl;
	gotoxy(40, 3);
	cout << "┗━━━━━┛" << endl;
	gotoxy(x, y);
	setcolor();
	return result;
}

static void draw_next_balls(int map[][MaxCol + 1], int row, int col, int ballsColor[])
{
	int x, y;
	setcolor(15, 0);
	getxy(x, y);
	gotoxy(40, 5);
	cout << "┏━━━━━┓" << endl;
	gotoxy(40, 6);
	cout << "┃";
	for (int i = 0; i < BallsEachStep; i++)
	{
		showstr(42 + i * 4, 6, "〇", ballsColor[i], 15);
		setcolor(15, 0);
		cout << "┃";
	}
	cout << endl;
	gotoxy(40, 7);
	cout << "┗━━━━━┛" << endl;
	gotoxy(x, y);
}

static void draw_help(int sX, int sY, int eX, int eY, int row)
{
	int x, y, score = 0, scoreAll = 0;
	setcolor();
	getxy(x, y);
	gotoxy(0, row * 2 + 2);
	cout << "[提示]从" << char(sY + 'A') << sX + 1 << "移动到" << char(eY + 'A') << eX + 1;
	gotoxy(x, y);
}

static void draw_statistics(int map[][MaxCol + 1], int row, int col, int ballsRemoved[])
{
	int x, y;
	setcolor(15, 0);
	getxy(x, y);
	gotoxy(40, 9);
	cout << "┏━━━━━━━━━━━┓";
	for (int i = 0; i < MaxColors + 1; i++)
	{
		gotoxy(40, 9 + i + 1);
		cout << "┃                      ┃";
	}
	for (int i = 0; i < MaxColors + 1; i++)
	{
		int balls = statistics_balls(map, row, col, i);
		gotoxy(40, 9 + i + 1);
		cout << "┃";
		showstr(42, 9 + i + 1, "〇", ((i == 0) ? 15 : i), 15);
		setcolor(15, 0);
		cout << ":" << setfill('0') << setw(2) << balls << "/(" << setw(4) << setiosflags(ios::fixed) << setprecision(2) << (double)balls / row / col * 100 <<  "%) del-" << ballsRemoved[i];
	}
	gotoxy(40, 9 + MaxColors + 2);
	cout << "┗━━━━━━━━━━━┛";
	setcolor();
	gotoxy(x, y);
}

void mode_7_and_8(int map[][MaxCol + 1], int row, int col, int mode)
{
	int eX = -1, eY = -1, keyX = 2, keyY = 2, ballsColor[BallsEachStep], score = 0, scoreAll = 0, ballsX[BallsEachStep], ballsY[BallsEachStep], ballsRemoved[MaxColors + 1] = { 0 };
	enable_mouse();
	setcursor(CURSOR_INVISIBLE);
	draw_score(map, row, col, eX, eY, &score, &scoreAll, ballsRemoved);
	set_balls_color(ballsColor, BallsEachStep);
	draw_next_balls(map, row, col, ballsColor);
	draw_statistics(map, row, col, ballsRemoved);
	while (!game_over(map, row, col))
	{
		gotoxy(keyX, keyY);
		draw_statistics(map, row, col, ballsRemoved);
		if (!move_in_console(map, row, col, eX, eY, keyX, keyY, mode - 7))
			break;
		if (draw_score(map, row, col, eX, eY, &score, &scoreAll, ballsRemoved) != 0)
			continue;
		create_balls(map, row, col, BallsEachStep, ballsColor, ballsX, ballsY);
		for (int i = 0; i < BallsEachStep; i++)
			draw_score(map, row, col, ballsX[i], ballsY[i], &score, &scoreAll, ballsRemoved);
		set_balls_color(ballsColor, BallsEachStep);
		draw_next_balls(map, row, col, ballsColor);
		draw_points(map, row, col, 7);
	}
	setcolor();
	setcursor(CURSOR_VISIBLE_NORMAL);
	disable_mouse();
}

void mode_6(int map[][MaxCol + 1], int row, int col)
{
	int eX, eY, temp;
	enable_mouse();
	setcursor(CURSOR_INVISIBLE);
	move_in_console(map, row, col, eX, eY, temp, temp);
	setcolor();
	setcursor(CURSOR_VISIBLE_NORMAL);
	disable_mouse();
}
