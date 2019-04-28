//1850059 计1班 杨志远

#include<iostream>
using namespace std;

int main()
{
	int num, digit = 0;
	cout << "请输入一个[0..99999]间的整数:" << endl;
	cin >> num;
	if (num / 10000) digit = 5;
	else if (num / 1000) digit = 4;
	else if (num / 100) digit = 3;
	else if (num / 10) digit = 2;
	else digit = 1;
	cout << digit << "位数" << endl;
	cout << "每位数字分别是:" << endl;
	switch (digit)
	{
		case 5:
			cout << num / 10000 << " " << (num / 1000) % 10 << " " << (num / 100) % 10 
				<< " " << (num / 10) % 10 << " " << num % 10 << endl;
			break;
		case 4:
			cout << (num / 1000) % 10 << " " << (num / 100) % 10
				<< " " << (num / 10) % 10 << " " << num % 10 << endl;
			break;
		case 3:
			cout << (num / 100) % 10 << " " << (num / 10) % 10 << " " << num % 10 << endl;
			break;
		case 2:
			cout << (num / 10) % 10 << " " << num % 10 << endl;
			break;
		case 1:
			cout << num << endl;
			break;
	}
	cout << "逆序输出的每位数字分别是:" << endl;
	switch (digit)
	{
		case 5:
			cout << num % 10 << " " << (num / 10) % 10 << " " << (num / 100) % 10
				<< " " << (num / 1000) % 10 << " " << num / 10000 << endl;
			break;
		case 4:
			cout << num % 10 << " " << (num / 10) % 10 << " " << (num / 100) % 10
				<< " " << (num / 1000) % 10 << endl;
			break;
		case 3:
			cout << num % 10 << " " << (num / 10) % 10 << " " << (num / 100) % 10 << endl;
			break;
		case 2:
			cout << num % 10 << " " << (num / 10) % 10 << endl;
			break;
		case 1:
			cout << num % 10 << endl;
			break;
	}
	return 0;
}