//1850059 ��1�� ��־Զ

#include <iostream>
#include <math.h>
using namespace std;

void aEqualZero();
void deltaOverZero(double a, double b, double delta);
void deltaEqualZero(double a, double b);
void deltaUnderZero(double a, double b, double delta);

int main()
{
	double a, b, c, delta;
	while (1)
	{
		cout << "������һԪ���η��̵�����ϵ��:" << endl;
		if (!(cin >> a >> b >> c))
		{
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	delta = b * b - 4 * a * c;
	if (a == 0)
	{
		aEqualZero();
	}
	else if (delta > 0)
	{
		deltaOverZero(a, b, delta);
	}
	else if (fabs(delta) < 1e-7)
	{
		deltaEqualZero(a, b);
	}
	else
	{
		deltaUnderZero(a, b, delta);
	}
	return 0;
}
