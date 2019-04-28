//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
#include <string.h>
using namespace std;

const int maxStudents = 100;
const int maxLength = 40;

void input_data(char name[][maxLength], char number[][maxLength], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "input name and NO. of student " << i + 1 << " :";
		cin >> name[i] >> number[i];
	}
}

void scarch(char find_name[], char name[][maxLength], char number[][maxLength], int n)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name[i], find_name) == 0)
		{
			cout << name[i] << " has been found, his number is " << number[i] << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "can't find this name" << endl;
}

int main()
{
	char name[maxStudents][maxLength];
	char number[maxStudents][maxLength];
	char find_name[maxLength];
	int n = 0;
	cout << "please input number of this class:";
	cin >> n;
	input_data(name, number, n);
	cout << "please input name you want find:"; // ???
	cin >> find_name;
	scarch(find_name, name, number, n);
	return 0;
}
