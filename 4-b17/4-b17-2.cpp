//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
using namespace std;

void Hanoi(int layer, char start, char end)
{
	static int steps = 0;
	if (layer == 1)
	{
		cout << setw(5) << ++steps << " : " << layer << "# " << start << "-->" << end << endl;
		return;
	}
	char middle;
	if (start == 'A' && end == 'C' || start == 'C' && end == 'A')
		middle = 'B';
	if (start == 'B' && end == 'C' || start == 'C' && end == 'B')
		middle = 'A';
	if (start == 'A' && end == 'B' || start == 'B' && end == 'A')
		middle = 'C';
	Hanoi(layer - 1, start, middle);
	cout << setw(5) << ++steps << " : " << layer << "# " << start << "-->" << end << endl;
	Hanoi(layer - 1, middle, end);
}

int main()
{
	int layer;
	char start, end;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-16):" << endl;
		if (!(cin >> layer))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
		}
		else if (layer <= 0 || layer > 16)
		{
			cin.clear();
			cin.ignore(999999999, '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			break;
		}
	}
	while (1)
	{
		cout << "请输入起始柱(A-C):" << endl;
		cin >> start;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (!(start >= 'A' && start <= 'C' || start >= 'a' && start <= 'c'))
			continue;
		start = (start >= 'a' && start <= 'c') ? start - ('a' - 'A') : start;
		break;
	}
	while (1)
	{
		cout << "请输入目标柱(A-C):" << endl;
		cin >> end;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (!(end >= 'A' && end <= 'C' || end >= 'a' && end <= 'c'))
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
	cout << "移动步骤为:" << endl;
	Hanoi(layer, start, end);
	return 0;
}
