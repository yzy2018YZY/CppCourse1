//1850059 ��1�� ��־Զ

#include <iostream>
#include <string>
using namespace std;

const char chistr[] = "��Ҽ��������½��ƾ�";

string result;

void daxie(int num, int flag)
{
	if (num && !flag)
	{
		result = result + chistr[0] + chistr[1];
	}
	if (!num && flag == 99)
	{
		result = result + chistr[0] + chistr[1];
	}
	if (num)
		result = result + chistr[2 * num] + chistr[2 * num + 1];
}

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	bool top = true;
	cout << "������һ��[0.01-100��)�������: " << endl;
	while (1)
	{
		if (!(cin >> num))
		{
			cout << "��ʽ��������������" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (num < 0.01 || num > 1e10)
		{
			cout << "���ֲ�����Ҫ������������" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	cout << "��д�����:" << endl;
	n1 = (int)(num / 1000000000);
	n2 = (int)(num / 100000000) % 10;
	n3 = (int)(num / 10000000) % 10;
	n4 = (int)(num / 1000000) % 10;
	n5 = (int)(num / 100000) % 10;
	n6 = (int)(num / 10000) % 10;
	n7 = (int)(num / 1000) % 10;
	n8 = (int)(num / 100) % 10;
	n9 = (int)(num / 10) % 10;
	num = num - ((double)(int)(num / 1000000000) * 1000000000);
	n10 = (int)(num) % 10;
	num = num - ((double)(int)(num / 100000000) * 100000000);
	n11 = (int)(num * 10 + 0.05) % 10;
	num = num - ((double)(int)(num / 10000000) * 10000000);
	n12 = (int)(num * 100 + 0.05) % 10;

	daxie(n1, 1);
	if (n1 != 0)
	{
		top = false;
		result += "ʰ";
	}
	daxie(n2, 1);
	if (n2 != 0)
	{
		top = false;
	}
	if (n1 != 0 || n2 != 0)
	{
		result += "��";
	}

	daxie(n3, 1);
	if (n3 != 0)
	{
		top = false;
		result += "Ǫ";
	}
	daxie(n4, top ? 1 : n3);
	if (n4 != 0)
	{
		top = false;
		result += "��";
	}
	daxie(n5, top ? 1 : n4);
	if (n5 != 0)
	{
		top = false;
		result += "ʰ";
	}
	daxie(n6, top ? 1 : n5);
	if (n6 != 0)
	{
		top = false;
	}
	if (n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0)
	{
		result += "��";
	}

	daxie(n7, 1);
	if (n7 != 0)
	{
		top = false;
		result += "Ǫ";
	}
	daxie(n8, top ? 1 : n7);
	if (n8 != 0)
	{
		top = false;
		result += "��";
	}
	daxie(n9, top ? 1 : n8);
	if (n9 != 0)
	{
		top = false;
		result += "ʰ";
	}
	daxie(n10, top ? 1 : n9);
	if (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0 || n7 != 0 || n8 != 0 || n9 != 0 || n10 != 0)
	{
		result += "Բ";
	}
	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 && n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 && n11 == 0 && n12 == 0)
	{
		daxie(0, 99);
		result += "Բ";
	}

	daxie(n11, 1);
	if (n11 != 0)
	{
		result += "��";
	}
	if (n12 == 0)
	{
		result += "��";
	}
	else
	{
		if (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0
			|| n5 != 0 || n6 != 0 || n7 != 0 || n8 != 0 || n9 != 0 || n10 != 0)
		{
			daxie(n12, n11);
		}
		else
		{
			daxie(n12, 1);
		}
		result += "��";
	}
	cout << result << endl;
	return 0;
}
