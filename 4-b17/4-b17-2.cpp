//1850059 ��1�� ��־Զ

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
		cout << "�����뺺ŵ���Ĳ���(1-16):" << endl;
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
		cout << "��������ʼ��(A-C):" << endl;
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
		cout << "������Ŀ����(A-C):" << endl;
		cin >> end;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (!(end >= 'A' && end <= 'C' || end >= 'a' && end <= 'c'))
		{
			continue;
		}
		if (start == end)
		{
			cout << "Ŀ����(" << end << ")��������ʼ��(" << start << ")��ͬ" << endl;
			continue;
		}
		end = (end >= 'a' && end <= 'c') ? end - ('a' - 'A') : end;
		break;
	}
	cout << "�ƶ�����Ϊ:" << endl;
	Hanoi(layer, start, end);
	return 0;
}
