//1850059 ��1�� ��־Զ

#include <iostream>
using namespace std;

int main()
{
	int a[1005] = { 0 }, size = 0, rank = 1;
	cout << "������ɼ������1000��������-1����" << endl;
	while (1)
	{
		cin >> a[size++];
		if (a[size - 1] == -1)
		{
			size--;
			break;
		}
	}
	cout << "���������Ϊ:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl << "���������εĶ�Ӧ��ϵΪ:" << endl;
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