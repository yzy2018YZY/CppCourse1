//1850059 计1班 杨志远

#include <iostream>
#include <string>
using namespace std;

const int maxStudents = 10;
const int maxNameLength = 10;
const int maxIDLength = 7;

int main()
{
	string name[maxStudents];
	string ID[maxStudents];
	int score[maxStudents];
	for (int i = 0; i < maxStudents; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> ID[i] >> name[i] >> score[i];
	}
	cout << endl << "不及格名单 : " << endl;
	for (int i = 0; i < maxStudents; i++)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << ID[i] << " " << score[i] << endl;
		}
	}
	return 0;
}
