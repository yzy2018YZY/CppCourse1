//1850059 ��1�� ��־Զ

#include <iostream>
#include <math.h>
using namespace std;

const int maxNode = 7;

double f(double x[], double y[], int a, int b, int c)
{
	return (x[a] - x[c])*(y[b] - y[c]) - (x[b] - x[c])*(y[a] - y[c]);//��� 
}

double triangleArea(double x[], double y[], int i, int j, int k)
{
	return fabs(0.5 * (x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - x[i] * y[k] - x[j] * y[i] - x[k] * y[j]));//��������ʽ 
}

int main()
{
	int node;
	double x[maxNode + 1] = { 0 }, y[maxNode + 1] = {0};
	while (1)
	{
		cout << "���������εĶ�������(4-" << maxNode << ")" << endl;
		cin >> node;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (node < 4 || node > maxNode)
		{
			continue;
		}
		break;
	}
	cout << "�밴˳ʱ��/��ʱ�뷽������5�������x,y���꣺" << endl;
	for (int i = 1; i <= node; i++)
	{
		while (1)
		{
			cout << "�������" << i << "����������꣺" << endl;
			if (!(cin >> x[i] >> y[i]))
			{
				cin.clear();
				cin.ignore(999999999, '\n');
				continue;
			}
			break;
		}
	}
	double tempFx;
	double symbol = 1;
	int realNode = node;
	for (int i = 1; i <= node; i++)
	{
		tempFx = f(x, y, i, (i + 1) % node, (i + 2) % node);
		if (i == 1 && tempFx < 0)
		{
			symbol = -1;
		}
		if (fabs(tempFx) < 10e-7)
		{
			realNode--;
		}
		if (tempFx * symbol < 0)
		{
			break;
		}
	}
	if (tempFx * symbol >= 0 && realNode > 3)
	{
		double area = 0;
		cout << "͹" << node <<"���ε����=";
		for (int i = 2; i <= node - 1; i++)
		{
			area += triangleArea(x, y, 1, i, i + 1);
		}
		cout << area << endl;
	}
	else
	{
		cout << "����͹" << node << "����" << endl;
	}
	return 0;
}
