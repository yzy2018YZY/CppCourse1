//1850059 计1班 杨志远

#include <iostream>
using namespace std;

int main()
{
	int num, original = 1;
	cout << "请输入第几天桃子数为1" << endl;
	cin >> num;
	for (int i = 1; i < num; i++)
	{
		original = 2 * (original + 1);
	}
	cout << "第" << num << "天的桃子数=" << original << endl;
	return 0;
}