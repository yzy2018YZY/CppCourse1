//1850059 计1班 杨志远

#include "90-b2.h"

static int FindPointInList(int *theListX, int *theListY, int start, int end, int x, int y);
static void PushPointFromListToList(int *dX, int *dY, int *dFX, int *dFY, int *dLength, int *sX, int *sY, int *sFX, int *sFY, int index);
static void DeletePointInOpenList(int *openListX, int *openListY, int *openListFatherX, int *openListFatherY, int *Length, int index);
static bool DeletePointFromCloseList(int *surroundX, int *surroundY, int surroundIndex, int *closeListX, int *closeListY, int closeListLength);
static int getSurroundPoints(int map[][MaxCol + 1], int row, int col, int tempPointIndex, int *surroundX, int *surroundY, int *surroundFatherX, int *surroundFatherY, int *openListX, int *openListY);
static int find_path_output(int endX, int endY, int pointListX[], int pointListY[], int allListX[], int allListY[], int allListFatherX[], int allListFatherY[], int allListLength);
static bool check_input_information(int inputMode, char tempStr[], int realRow, int realCol);
static bool in_map(int map[][MaxCol + 1], int row, int col, int x, int y);
static int check_map_find_i_start(int map[][MaxCol + 1], int row, int col, const int direction[][2], int d, int value, int maxRange, int x, int y);

//行数和列数 2   End 3   起点 4   终点 5
void input_information(int winX, int inputMode, int mode, int *row, int *col, char *instruction, int realRow, int realCol)
{
	char tempStr[200] = "";
	bool secondInput = false;
	int x, y;
	getxy(x, y);
	x += winX;
	while (1)
	{
		gotoxy(0, y + secondInput);
		cout << helpInformation[inputMode];
		cout << "                        ";
		gotoxy(x, y + secondInput);
		cin >> tempStr;
		cin.ignore(99999, '\n');
		_strlwr(tempStr);
		if (!check_input_information(inputMode, tempStr, realRow, realCol))
		{
			gotoxy(0, y + 1 + secondInput);
			cout << helpInformation[0] << endl;
			continue;
		}
		if (inputMode == 2)
		{
			inputMode--;
			secondInput = true;
			*row = tempStr[0] - '0';
			continue;
		}
		if (inputMode == 1)
			*col = tempStr[0] - '0';
		if (inputMode == 4 || inputMode == 5)
			strcpy(instruction, tempStr);
		break;
	}
}

void input_instruction(int mode, int map[][MaxCol + 1], int *sX, int *sY, int *eX, int *eY ,int row ,int col)
{
	char instructionA[5] = "", instructionB[5] = "";
	while (1)
	{
		input_information(strlen(helpInformation[4]), 4, mode, 0, 0, instructionA, row, col);
		*sX = instructionA[1] - '1';
		*sY = instructionA[0] - 'a';
		if (map[*sY][*sX] == 0)
		{
			cout << "起点错误，请重新输入    " << endl;
			continue;
		}
		else
			cout << "输入为" << char(*sY + 'A') << "行" << (*sX) + 1 << "列          " << endl;
		break;
	}
	while (1)
	{
		input_information(strlen(helpInformation[5]), 5, mode, 0, 0, instructionB, row, col);
		*eX = instructionB[1] - '1';
		*eY = instructionB[0] - 'a';
		if (map[*eY][*eX] != 0)
		{
			cout << "终点错误，请重新输入    " << endl;
			continue;
		}
		else
			cout << "输入为" << char(*eY + 'A') << "行" << (*eX) + 1 << "列          " << endl;
		break;
	}
}

static bool check_input_information(int inputMode, char tempStr[], int realRow, int realCol)
{
	if (inputMode == 1 || inputMode == 2)
	{
		if (strlen(tempStr) != 1 || tempStr[0] < MinRow + '0' || tempStr[0] > MaxRow + '0')
			return false;
	}
	if (inputMode == 3)
	{
		if (strlen(tempStr) != 3 || strcmp(tempStr, "end") != 0)
			return false;
	}
	if (inputMode == 4 || inputMode == 5)
	{
		if (strlen(tempStr) != 2 || tempStr[0] < 'a' || tempStr[0] > 'a' + realRow - 1 || tempStr[1] < '1' || tempStr[1] > '1' + realCol - 1)
			return false;
	}
	return true;
}

void set_balls_color(int ballsColor[], int colors)
{
	for (int i = 0; i < colors; i++)
		ballsColor[i] = rand() % MaxColors + 1;
}

//如果提供了ballsColor参数，那么可以用ballsColor中的信息修改map、保存多个随机的color信息，否则直接使用随机的color信息修改map
void create_balls(int map[][MaxCol + 1], int row, int col, int balls, int ballsColor[], int ballsX[], int ballsY[])
{
	int x, y;
	for (int i = 0; i < balls; i++)
	{
		do
		{
			y = rand() % row;
			x = rand() % col;
		} while (map[y][x] != 0 && !game_over(map, row, col));
		map[y][x] = (ballsColor != NULL) ? ballsColor[i] : rand() % MaxColors + 1;
		if (ballsY != NULL)
		{
			ballsX[i] = x;
			ballsY[i] = y;
		}
	}
}

void move_map(int map[][MaxCol + 1], int dX, int dY, int sX, int sY)
{
	map[dY][dX] = map[sY][sX];
	map[sY][sX] = 0;
}

bool game_over(int map[][MaxCol + 1], int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (map[i][j] == 0)
				return false;
	return true;
}

static bool in_map(int map[][MaxCol + 1], int row, int col, int x, int y)
{
	if (x < 0 || x >= col || y < 0 || y >= row)
		return false;
	else
		return true;
}

static int check_map_find_i_start(int map[][MaxCol + 1], int row, int col, const int direction[][2], int d, int value, int maxRange, int x, int y)
{
	int i = -maxRange;
	while (++i < 0)
		if (in_map(map, row, col, x + i * direction[d][0], y + i * direction[d][1]) && map[y + i * direction[d][1]][x + i * direction[d][0]] == value)
			break;
	return i;
}

int check_map(int map[][MaxCol + 1], int row, int col, int x, int y, int *score, int *scoreAll, bool consoleMode, int ballsRemoved[])
{
	const int direction[8][2] = { {0, 1}, {1, 1}, {1, 0}, {-1, 1} , {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
	int count = 0, result = 0, value = map[y][x], maxRange = max(MaxRow, MaxCol);
	*score = 0;
	for (int d = 0; d < 8; d++)
	{
		count = 0;
		int i = check_map_find_i_start(map, row, col, direction, d, value, maxRange, x, y);
		for (; i <= maxRange; i++)
		{
			if (in_map(map, row, col, x + direction[d][0], y + direction[d][1]) && map[y + i * direction[d][1]][x + i * direction[d][0]] == value)
				count++;
			else
				break;
		}
		if (count >= MinBallsCount)
		{
			if (ballsRemoved != NULL)
				ballsRemoved[map[y][x]] = count;
			result++;
			i = check_map_find_i_start(map, row, col, direction, d, value, maxRange, x, y);
			for (; i <= maxRange; i++)
			{
				if (i != 0 && in_map(map, row, col, x + direction[d][0], y + direction[d][1]) && map[y + i * direction[d][1]][x + i * direction[d][0]] == value)
				{
					map[y + i * direction[d][1]][x + i * direction[d][0]] = 0;
					if (consoleMode)
						showstr((x + i * direction[d][0]) * 4 + 2, (y + i * direction[d][1]) * 2 + 2, "  ", 15, 0);
				}
				else if(i != 0)
					break;
			}
			*score += result * (count - 1) * (count - 2);
		}
	}
	if (result > 0)
	{
		map[y][x] = 0;
		if (consoleMode)
			showstr(x * 4 + 2, y * 2 + 2, "  ", 15, 0);
	}
	*scoreAll += *score;
	return result;
}

void print_console_border(int mode)
{
	int winX, winY, winBufferX, winBufferY, x, y;
	getxy(x, y);
	getconsoleborder(winX, winY, winBufferX, winBufferY);
	gotoxy(0, 0);
	cout << "屏幕: " << winY << "行" << winX << "列" << ((mode >= 6)? "(鼠标右键退出)": "") << endl;
	gotoxy(x, y);
}

int statistics_balls(int map[][MaxCol + 1], int row, int col, int color)
{
	int result = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (color == map[i][j])
				result++;
	return result;
}

int find_path(int row, int col, int startX, int startY, int endX, int endY, int map[][MaxCol + 1], int *pointListX, int *pointListY)
{
	int startPoint = map[startY][startX];
	int index_of_myPoint = 0, openListStart = 0, openListEnd = 0, closeListLength = 0, allListLength = 0, surroundLength = 0;
	int openListX[MaxPath] = { startX }, openListY[MaxPath] = { startY }, openListFatherX[MaxPath] = { -1 }, openListFatherY[MaxPath] = { -1 };
	int closeListX[MaxPath], closeListY[MaxPath], closeListFatherX[MaxPath], closeListFatherY[MaxPath];
	int allListX[MaxPath] = { startX }, allListY[MaxPath] = { startY }, allListFatherX[MaxPath] = { -1 }, allListFatherY[MaxPath] = { -1 };
	map[startY][startX] = 0;
	openListEnd++;
	allListLength++;
	while (openListEnd - openListStart > 0 && allListLength < MaxPath - 5)
	{
		int surroundX[4] = { -1, -1, -1, -1 }, surroundY[4] = { -1, -1, -1, -1 }, surroundFatherX[4] = { -1, -1, -1, -1 }, surroundFatherY[4] = { -1, -1, -1, -1 };
		PushPointFromListToList(closeListX, closeListY, closeListFatherX, closeListFatherY, &closeListLength, openListX, openListY, openListFatherX, openListFatherY, openListStart);
		surroundLength = getSurroundPoints(map, row, col, openListStart, surroundX, surroundY, surroundFatherX, surroundFatherY, openListX, openListY);
		openListStart++;
		for (int i = 0; i < surroundLength; i++)
			DeletePointFromCloseList(surroundX, surroundY, i, closeListX, closeListY, closeListLength);
		for (int i = 0; i < surroundLength; i++)
		{
			if (surroundX[i] != -1)
			{
				if (FindPointInList(allListX, allListY, 0, allListLength, surroundX[i], surroundY[i]) == -1)
					PushPointFromListToList(openListX, openListY, openListFatherX, openListFatherY, &openListEnd, surroundX, surroundY, surroundFatherX, surroundFatherY, i);
				if (FindPointInList(allListX, allListY, 0, allListLength, surroundX[i], surroundY[i]) == -1)
					PushPointFromListToList(allListX, allListY, allListFatherX, allListFatherY, &allListLength, surroundX, surroundY, surroundFatherX, surroundFatherY, i);
			}
		}
		if (FindPointInList(openListX, openListY, openListStart, openListEnd, endX, endY) > -1)//判断何时退出
		{
			map[startY][startX] = startPoint;
			return find_path_output(endX, endY, pointListX, pointListY, allListX, allListY, allListFatherX, allListFatherY, allListLength);;
		}
	}
	map[startY][startX] = startPoint;
	return 0;
}

inline void exchange(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

static int FindPointInList(int *theListX, int *theListY, int start, int end, int x, int y)
{
	for (int i = start; i < end; i++)
	{
		if (theListX[i] == x && theListY[i] == y)
		{
			return i;
		}
	}
	return -1;
}

static void PushPointFromListToList(int *dX, int *dY, int *dFX, int *dFY, int *dLength, int *sX, int *sY, int *sFX, int *sFY, int index)
{
	dX[(*dLength)] = sX[index];
	dY[(*dLength)] = sY[index];
	dFX[(*dLength)] = sFX[index];
	dFY[(*dLength)] = sFY[index];
	(*dLength)++;
}

static void DeletePointInOpenList(int *openListX, int *openListY, int *openListFatherX, int *openListFatherY, int *Length, int index)
{
	for (int i = index; i < *Length; i++)
	{
		openListX[i] = openListX[i + 1];
		openListY[i] = openListY[i + 1];
		openListFatherX[i] = openListFatherX[i + 1];
		openListFatherY[i] = openListFatherY[i + 1];
	}
	(*Length)--;
}

static bool DeletePointFromCloseList(int *surroundX, int *surroundY, int surroundIndex, int *closeListX, int *closeListY, int closeListLength)
{
	bool result = false;
	for (int i = 0; i < closeListLength; i++)
	{
		if (closeListX[i] == surroundX[surroundIndex] && closeListY[i] == surroundY[surroundIndex])
		{
			surroundX[surroundIndex] = -1;
			surroundY[surroundIndex] = -1;
			result = true;
		}
	}
	return result;
}

static int getSurroundPoints(int map[][MaxCol + 1], int row, int col, int tempPointIndex, int *surroundX, int *surroundY, int *surroundFatherX, int *surroundFatherY, int *openListX, int *openListY)
{
	int tempPointsX[4] = { -1, -1, -1, -1 }, tempPointsY[4] = { -1, -1, -1, -1 };
	bool tempPointsIsWall[4] = {false};
	int tempPointsLength = 0;
	if (openListY[tempPointIndex] < row - 1)
	{
		tempPointsX[1] = openListX[tempPointIndex];
		tempPointsY[1] = openListY[tempPointIndex] + 1;
		tempPointsIsWall[1] = map[openListY[tempPointIndex]][openListX[tempPointIndex]];
	}
	if (openListY[tempPointIndex] > 0)
	{
		tempPointsX[0] = openListX[tempPointIndex];
		tempPointsY[0] = openListY[tempPointIndex] - 1;
		tempPointsIsWall[0] = map[openListY[tempPointIndex]][openListX[tempPointIndex]];
	}
	if (openListX[tempPointIndex] > 0)
	{
		tempPointsX[2] = openListX[tempPointIndex] - 1;
		tempPointsY[2] = openListY[tempPointIndex];
		tempPointsIsWall[2] = map[openListY[tempPointIndex]][openListX[tempPointIndex]];
	}
	if (openListX[tempPointIndex] < col - 1)
	{
		tempPointsX[3] = openListX[tempPointIndex] + 1;
		tempPointsY[3] = openListY[tempPointIndex];
		tempPointsIsWall[3] = map[openListY[tempPointIndex]][openListX[tempPointIndex]];
	}

	for (int i = 0; i < 4; i++)
	{
		if (tempPointsIsWall[i] == false)
		{
			surroundX[i] = tempPointsX[i];
			surroundY[i] = tempPointsY[i];
			surroundFatherX[i] = openListX[tempPointIndex];
			surroundFatherY[i] = openListY[tempPointIndex];
			tempPointsLength++;
		}
	}
	return tempPointsLength;
}

static int find_path_output(int endX, int endY, int pointListX[], int pointListY[], int allListX[], int allListY[], int allListFatherX[], int allListFatherY[], int allListLength)
{
	int index_of_return = FindPointInList(allListX, allListY, 0, allListLength, endX, endY);
	int m_pointListSize = 0;
	for (; index_of_return != -1 && m_pointListSize <= allListLength; m_pointListSize++)
	{
		pointListX[m_pointListSize] = allListX[index_of_return];
		pointListY[m_pointListSize] = allListY[index_of_return];
		index_of_return = FindPointInList(allListX, allListY, 0, allListLength, allListFatherX[index_of_return],
			allListFatherY[index_of_return]);
	}
	for (int i = 0; i < m_pointListSize / 2; i++)
	{
		exchange(pointListX[m_pointListSize - i - 1], pointListX[i]);
		exchange(pointListY[m_pointListSize - i - 1], pointListY[i]);
	}
	return m_pointListSize;
}
