//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <iomanip>
using namespace std;

const int row = 10;

int main()
{
	int num[row] = {1};
	cout << setw(6) << num[0] << endl;
	for (int i = 1; i < row; i++)
	{
		num[i - 1] = 1;
		for (int j = i; j > 0; j--)
		{
			num[j] = num[j] + num[j - 1];
		}
		num[0] = 1;
		for (int j = 0; j <= i; j++)
		{
			cout << setw(6) << num[j];
		}
		cout << endl;
	}
	return 0;
}