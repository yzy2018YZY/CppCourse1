//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	double profit;
	cout << "请输入当月利润:" << endl;
	cin >> profit;
	cout << "应发奖金数:" << endl;
	switch ((int)(profit / 100000))
	{
		case 0:
			cout << (int)(profit * 0.1) << endl;
			break;
		case 1:
			cout << (int)((profit - 100000) * 0.075 + 10000) << endl;
			break;
		case 2:
		case 3:
			cout << (int)((profit - 200000) * 0.05 + 17500) << endl;
			break;
		case 4:
		case 5:
			cout << (int)((profit - 400000) * 0.03 + 27500) << endl;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			cout << (int)((profit - 600000) * 0.015 + 33500) << endl;
			break;
		default:
			cout << (int)((profit - 1000000) * 0.01 + 39500) << endl;
			break;
	}
	return 0;
}