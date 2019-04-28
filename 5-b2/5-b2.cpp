//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
using namespace std;

const int SIZE = 100;

int main()
{
	int a[SIZE + 1] = { 0 };
	for (int i = 1; i <= SIZE; i++)
	{
		for (int j = 1; j <= SIZE / i; j++)
		{
			a[i * j] = bool(a[i * j] - 1);
		}
	}
	for (int i = 1; i <= SIZE; i++)
	{
		if (a[i])
		{
			cout << i << "  ";
		}
	}
	cout << endl;
	return 0;
}