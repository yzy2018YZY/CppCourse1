//1850059 ��1�� ��־Զ

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int x, i = 1, step = 1;
	double a = 1, t = 1;
	while (1) {
		cout << "������x��ֵ(-10 ~ +65)��";
		if (!(cin >> x))
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "�������" << endl;
			continue;
		}
		if (x >= -10 && x <= 65)
			break;
		else
		{
			while (getchar() != '\n')
				;
			cin.clear();
			cout << "�������" << endl;
		}
	}
	i = 1;
	while (fabs(t) > 1e-6)
	{
		t = t * (double)x / (double)i;
		a += t;
		i++;
	}
	cout << "e^" << x << "=" << a << endl;

	return 0;
}
