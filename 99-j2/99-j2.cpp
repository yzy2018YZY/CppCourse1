//1850059 计1班 杨志远

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>	//srand/rand函数
#include <time.h>	//time函数
#include <iomanip>
using namespace std;

int main()
{
	int people, maxMoneyIndex = 0;
	double totalMoney, maxMoney = 200, currentMoney = 0, nowTotalMoney, r = 0;
	srand((unsigned int)time(0));
	while (1) {
		cout << "请输入人数(1-50)：";
		if (!(cin >> people))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误" << endl;
			continue;
		}
		if (people >= 1 && people <= 50)
			break;
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误" << endl;
		}
	}
	while (1) {
		cout << "请输入红包金额(0.01-200)：";
		if (!(cin >> totalMoney))
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误" << endl;
			continue;
		}
		if (totalMoney >= 0.01 && totalMoney <= 200 && totalMoney >= 0.01 * people)
			break;
		else
		{
			while (getchar() != '\n')
			{
				;
			}
			cin.clear();
			cout << "输入错误" << endl;
		}
	}
	for (int tr = 0; tr < 5; tr++)
	{
		rand();
	}
	nowTotalMoney = totalMoney;
	cout << endl;
	cout << setiosflags(ios::fixed);
	if (people >= 3 &&(r = (double)rand() / 32767) < 0.75 && r < nowTotalMoney - 0.01 * people)
	{
		double money = ((double)rand() / 32767) * 0.5 + 0.3;
		if (money < nowTotalMoney - 0.01 * people)
		{
			maxMoneyIndex = rand() % people + 1;
			maxMoney = nowTotalMoney * money;
			maxMoney = (double)((int)(maxMoney * 100 + 0.5)) / 100;
			nowTotalMoney -= maxMoney;
		}
	}

	for (int i = 1; i < people; i++)
	{
		if (maxMoneyIndex == i)
		{
			cout << "第" << setw(2) << i << "个 : " << setprecision(2) << maxMoney << endl;
			continue;
		}
		if ((double)rand() / 32767 < 0.05 + (double)i / people * 0.05 ) // 有大约5%到10%的概率出现运气王
		{
			double money = ((double)rand() / 32767) * 0.2 + (double)i / people * 0.2; // 每个大红包是总红包的20%到40%
			if (money > nowTotalMoney - nowTotalMoney * money - 0.01 * (people - i)
				&& fabs(nowTotalMoney - nowTotalMoney * money - 0.01 * (people - i) - money) > 10e-6)
			{
				i--;
				continue;
			}
			currentMoney = nowTotalMoney * money;
			currentMoney = (double)((int)(currentMoney * 100 + 0.5)) / 100;
			nowTotalMoney -= currentMoney;
			cout << "第" << setw(2) << i << "个 : " << setprecision(2) << currentMoney << endl;
			continue;
		}
		do
		{
			currentMoney = (double)rand() / 32767 * (nowTotalMoney / (people - i + 1) * 2);
			currentMoney = (double)((int)(currentMoney * 100 + 0.5)) / 100;
			if (currentMoney < 0.01)
			{
				currentMoney = 0.01;
			}
		} while (currentMoney > totalMoney * 0.8 || currentMoney > nowTotalMoney - 0.01 * (people - i)
			&& fabs(currentMoney - nowTotalMoney + 0.01 * (people - i)) > 10e-6);

		nowTotalMoney -= currentMoney;
		cout << "第" << setw(2) << i << "个 : " << setprecision(2) << currentMoney << endl;
	}
	if (maxMoneyIndex != people)
	{
		currentMoney = nowTotalMoney;
	}
	else
	{
		currentMoney = maxMoney;
	}
	cout << "第" << setw(2) << people << "个 : " << setprecision(2) << currentMoney << endl;
	return 0;
}