//1850059 计1班 杨志远

#include <iostream>
using namespace std;

const int maxSize = 20;

void merge(int *list_a, int *list_b, int *list_c)
{
	int x = 0, y = 0, z = 0;
	while (*(list_a + x) != -1 && *(list_b + y) != -1)
	{
		if (*(list_a + x) < *(list_b + y))
		{
			*(list_c + z) = *(list_a + x);
			z++;
			x++;
		}
		else
		{
			*(list_c + z) = *(list_b + y);
			z++;
			y++;
		}
	}
	while (*(list_a + x) != -1)
	{
		*(list_c + z) = *(list_a + x);
		z++;
		x++;
	}
	while (*(list_b + y) != -1)
	{
		*(list_c + z) = *(list_b + y);
		z++;
		y++;
	}
	*(list_c + z) = -1;
}

int main()
{
	int a[maxSize + 1] = { 0 }, b[maxSize + 1] = { 0 }, c[2 * maxSize + 1] = { 0 };
	cout << "请输入第1个数组，升序序列(最多" << maxSize << ") , 以-1结束(-1不计入内)" << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cin >> *(a + i);
		if (*(a + i) == -1)
		{
			break;
		}
	}
	cout << "请输入第2个数组，升序序列(最多" << maxSize << ") , 以-1结束(-1不计入内)" << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cin >> *(b + i);
		if (*(b + i) == -1)
		{
			break;
		}
	}

	merge(a, b, c);

	cout << "第1个数组的内容为:" << endl;
	for (int i = 0; *(a + i) != -1; i++)
	{
		cout << *(a + i) << " ";
	}
	cout << endl << "第2个数组的内容为:" << endl;
	for (int i = 0; *(b + i) != -1; i++)
	{
		cout << *(b + i) << " ";
	}
	cout << endl << "合并后的数组的内容为:" << endl;
	for (int i = 0; *(c + i) != -1; i++)
	{
		cout << *(c + i) << " ";
	}
	cout << endl;
	return 0;
}
