//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
using namespace std;

int A[10], B[10], C[10];
int top_A, top_B, top_C;

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

void Hanoi(int layer, char start, char end)
{
	static int steps = 0;
	if (layer == 1)
	{
		cout << "第" << setw(4) << ++steps << " 步(" << setw(2) << layer << "): " << start << "-->" << end;
		move_stack(start, end);
		print_stack(layer);
		return;
	}
	char middle;
	middle = 'A' + 'B' + 'C' - start - end;
	Hanoi(layer - 1, start, middle);
	cout << "第" << setw(4) << ++steps << " 步(" << setw(2) << layer << "): " << start << "-->" << end;
	move_stack(start, end);
	print_stack(layer);
	Hanoi(layer - 1, middle, end);
}

int main()
{
	int layer;
	char start, end;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10): " << endl;
		cin >> layer;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (layer <= 0 || layer > 10)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "请输入起始柱(A-C): " << endl;
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
		cout << "请输入目标柱(A-C): " << endl;
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
	cout << "初始:               ";
	print_stack(layer);
	Hanoi(layer, start, end);
	return 0;
}
