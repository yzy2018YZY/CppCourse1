//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	int a[1005] = { 0 }, size = 0, rank = 1;
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	while (1)
	{
		cin >> a[size++];
		if (a[size - 1] == -1)
		{
			size--;
			break;
		}
	}
	cout << "输入的数组为:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl << "分数与名次的对应关系为:" << endl;
	int min, minIndex;
	for (int i = size - 1; i >= 0; i--)
	{
		min = a[i];
		minIndex = i;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				minIndex = j;
			}
		}
		int temp = a[minIndex];
		a[minIndex] = a[i];
		a[i] = temp;
	}
	int maxCount = 1;
	cout << a[0] << " " << rank << endl;
	for (int i = 1; i < size; i++)
	{
		if (a[i] == a[i - 1])
		{

			maxCount++;
		}
		else
		{
			rank += maxCount;
			maxCount = 1;
		}
		cout << a[i] << " " << rank << endl;
	}
	return 0;
}