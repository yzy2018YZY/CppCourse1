//1850059 计1班 杨志远

#include <iostream>
using namespace std;

void Hanoi(int layer, char start, char end)
{
	if (layer == 1)
	{
		cout << layer << "# " << start << "-->" << end << endl;
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
	cout << layer << "# " << start << "-->" << end << endl;
	Hanoi(layer - 1, middle, end);
}

int main()
{
	int layer;
	char start, end;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-64):" << endl;
		if (!(cin >> layer))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
		}
		else if (layer <= 0 || layer > 64)
		{
			cin.clear();
			cin.ignore(999999999, '\n');
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		cout << "请输入起始柱(A-C):" << endl;
		cin >> start;
		if (!(start >= 'A' && start <= 'C' || start >= 'a' && start <= 'c'))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		start = (start >= 'a' && start <= 'c') ? start - ('a' - 'A') : start;
		break;
	}
	while (1)
	{
		cout << "请输入目标柱(A-C):" << endl;
		cin >> end;
		if (!(end >= 'A' && end <= 'C' || end >= 'a' && end <= 'c'))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (start == end)
		{
			cin.clear();
			cin.ignore(999999999, '\n');
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
