//1850059 计1班 杨志远

#include <iostream>
#include <math.h>
using namespace std;

const int maxNode = 7;

double f(double x[], double y[], int a, int b, int c)
{
	return (x[a] - x[c])*(y[b] - y[c]) - (x[b] - x[c])*(y[a] - y[c]);//叉乘 
}

double triangleArea(double x[], double y[], int i, int j, int k)
{
	return fabs(0.5 * (x[i] * y[j] + x[j] * y[k] + x[k] * y[i] - x[i] * y[k] - x[j] * y[i] - x[k] * y[j]));//三阶行列式 
}

int main()
{
	int node;
	double x[maxNode + 1] = { 0 }, y[maxNode + 1] = {0};
	while (1)
	{
		cout << "请输入多边形的顶点数量(4-" << maxNode << ")" << endl;
		cin >> node;
		cin.clear();
		cin.ignore(999999999, '\n');
		if (node < 4 || node > maxNode)
		{
			continue;
		}
		break;
	}
	cout << "请按顺时针/逆时针方向输入5个顶点的x,y坐标：" << endl;
	for (int i = 1; i <= node; i++)
	{
		while (1)
		{
			cout << "请输入第" << i << "个顶点的坐标：" << endl;
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
		cout << "凸" << node <<"边形的面积=";
		for (int i = 2; i <= node - 1; i++)
		{
			area += triangleArea(x, y, 1, i, i + 1);
		}
		cout << area << endl;
	}
	else
	{
		cout << "不是凸" << node << "边形" << endl;
	}
	return 0;
}
