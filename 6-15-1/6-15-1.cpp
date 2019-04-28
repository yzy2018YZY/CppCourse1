//1850059 计1班 杨志远

#include <iostream>
#include <iomanip>
using namespace std;

/* 求第一门课的平均分 */
void average(int(*a)[5])
{
	double sum = 0;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		sum = sum + *(*p);
	}
	cout << sum / 4;
}

/* 找出有两门以上课程不及格的学生 */
void fail(int(*a)[5])
{
	int count = 0;
	double sum = 0;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		count = 0;
		sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum += *(*p + i);
			if (*(*p + i) < 60)
			{
				count++;
			}
		}
		if (count >= 2)
		{
			cout << "No: " << p - a + 1 << " ";
			for (int k = 0; k < 5; k++)
			{
				cout << *(*p + k) << " ";
			}
			cout << "平均: " << sum / 5 << endl;
		}
	}
}

/* 找出平均成绩在90分以上或全部成绩在85分以上的学生 */
void good(int(*a)[5])
{
	int count = 0;
	double sum = 0;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		count = 0;
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += *(*p + j);
			if (*(*p + j) >= 85)
			{
				count++;
			}
		}
		if (count == 5 || sum / 5 >= 90)
		{
			cout << "No: " << p - a + 1 << " ";
			for (int k = 0; k < 5; k++)
			{
				cout << *(*p + k) << " ";
			}
			cout << "平均: " << sum / 5 << endl;
		}
	}
}

int main()
{
	int a[4][5] = { {91, 81, 71, 61, 51},	//第1个学生的1-5门课的成绩
		{92, 82, 72, 32, 52},   //第2个学生的1-5门课的成绩
		{93, 83, 99, 80, 95},   //第3个学生的1-5门课的成绩
		{97, 85, 87, 91, 88} }; //第4个学生的1-5门课的成绩
	cout << "初始信息:" << endl;
	for (int(*p)[5] = a; p != a + 4; p++)
	{
		cout << "No." << p - a + 1 << "的1-5门课成绩: ";
		for (int j = 0; j < 5; j++)
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