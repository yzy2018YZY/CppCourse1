//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
using namespace std;

/* 求第一门课的平均分 */
void average(int(*a)[4])
{
	double sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum = sum + *(*a + i);
	}
	cout << sum / 4;
}

/* 找出有两门以上课程不及格的学生 */
void fail(int(*a)[4])
{
	int count = 0;
	double sum = 0;
	for (int j = 0; j < 4; j++)
	{
		count = 0;
		sum = 0;
		for (int(*p)[4] = a; p != a + 5; p++)
		{
			sum += *(*p + j);
			if (*(*p + j) < 60)
			{
				count++;
			}
		}
		if (count >= 2)
		{
			cout << "No: " << j + 1 << " ";
			for (int(*p)[4] = a; p != a + 5; p++)
			{
				cout << *(*p + j) << " ";
			}
			cout << "平均: " << sum / 5 << endl;
		}
	}
}

/* 找出平均成绩在90分以上或全部成绩在85分以上的学生 */
void good(int(*a)[4])
{
	int count = 0;
	double sum = 0;
	for (int j = 0; j < 4; j++)
	{
		count = 0;
		sum = 0;
		for (int(*p)[4] = a; p != a + 5; p++)
		{
			sum += *(*p + j);
			if (*(*p + j) >= 85)
			{
				count++;
			}
		}
		if (count == 5 || sum / 5 >= 90)
		{
			cout << "No: " << j + 1 << " ";
			for (int(*p)[4] = a; p != a + 5; p++)
			{
				cout << *(*p + j) << " ";
			}
			cout << "平均: " << sum / 5 << endl;
		}
	}
}

int main()
{
	int a[5][4] = { {91,92,93,97},  //第1-4个学生的第1门课成绩
		{81,82,83,85},  //第1-4个学生的第2门课成绩
		{71,72,99,87},  //第1-4个学生的第3门课成绩
		{61,32,80,91},  //第1-4个学生的第4门课成绩
		{51,52,95,88} };//第1-4个学生的第5门课成绩
	cout << "初始信息:" << endl;
	for (int(*p)[4] = a; p != a + 5; p++)
	{
		cout << "No.1-4学生的第" << p - a + 1 << "门课成绩: ";
		for (int j = 0; j < 4; j++)
		{
			cout << *(*p + j) << " ";
		}
		cout << endl;
	}
	cout << endl << "第1门课平均分: ";
	average(a);
	cout << endl << endl << "2门以上不及格的学生: " << endl;
	fail(a);
	cout << endl << "平均90以上或者全部85以上的学生: " << endl;
	good(a);
	return 0;
}