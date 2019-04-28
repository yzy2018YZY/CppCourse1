//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 2; i < 1000; i++)
	{
		sum = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		if (i == sum)
		{
			cout << i << ",its factors are 1";
			for (int j = 2; j <= i / 2; j++)
			{
				if (i % j == 0)
				{
					cout << "," << j;
				}
			}
			cout << endl;
		}
	}
	return 0;
}