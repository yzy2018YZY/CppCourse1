//1850059 ��1�� ��־Զ

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
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> ID[i] >> name[i] >> score[i];
	}
	cout << endl << "���������� : " << endl;
	for (int i = 0; i < maxStudents; i++)
	{
		if (score[i] < 60)
		{
			cout << name[i] << " " << ID[i] << " " << score[i] << endl;
		}
	}
	return 0;
}
