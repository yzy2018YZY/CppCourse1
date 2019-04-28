//1850059 ��1�� ��־Զ

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int passwordCounts = 10;
const int maxPasswordLength = 16;
const int minPasswordLength = 12;

void calcPassword(int upperCh, int lowerCh, int numberCh, int otherCh, int passwordLength, int randNumbers[], char password[][maxPasswordLength + 1])
{
	for (int j = 0; j < passwordCounts; j++)
	{
		for (int i = 0; i < passwordLength + 1; i++)
		{
			randNumbers[i] = i;
		}
		for (int i = 0; i < passwordLength; i++)
		{
			int tempRand = rand() % (passwordLength - i) + i;
			int temp = randNumbers[i];
			randNumbers[i] = randNumbers[tempRand];
			randNumbers[tempRand] = temp;
		}
		for (int i = 0; i < upperCh; i++)
		{
			password[j][randNumbers[i]] = rand() % 26 + 'A';
		}
		for (int i = upperCh; i < upperCh + lowerCh; i++)
		{
			password[j][randNumbers[i]] = rand() % 26 + 'a';
		}
		for (int i = upperCh + lowerCh; i < upperCh + lowerCh + numberCh; i++)
		{
			password[j][randNumbers[i]] = rand() % 10 + '0';
		}
		for (int i = upperCh + lowerCh + numberCh; i < upperCh + lowerCh + numberCh + otherCh; i++)
		{
			char tempCh;
			do
			{
				tempCh = rand() % 94 + 33;
			} while (tempCh >= '0' && tempCh <= '9' || tempCh >= 'A'&& tempCh <= 'Z' || tempCh >= 'a' && tempCh <= 'z');
			password[j][randNumbers[i]] = tempCh;
		}
		for (int i = upperCh + lowerCh + numberCh + otherCh; i < passwordLength; i++)
		{
			password[j][randNumbers[i]] = rand() % 94 + 33;
		}
	}
}

int main()
{
	int passwordLength, upperCh, lowerCh, numberCh, otherCh;
	char password[passwordCounts][maxPasswordLength + 1];
	int randNumbers[maxPasswordLength + 1] = { 0 };
	char otherCharacters[100] = { 0 };
	srand((unsigned int)time(0));
	cout << "���������볤��(��" << minPasswordLength <<")" << endl;
	while (1)
	{
		if (!(cin >> passwordLength))
		{
			cout << "�����ʽ����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (passwordLength < minPasswordLength || passwordLength > maxPasswordLength)
		{
			cout << "���ִ�С����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	cout << "�������д��ĸ����(��2)" << endl;
	while (1)
	{
		if (!(cin >> upperCh))
		{
			cout << "�����ʽ����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (upperCh < 2)
		{
			cout << "���ִ�С����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	cout << "������Сд��ĸ����(��2)" << endl;
	while (1)
	{
		if (!(cin >> lowerCh))
		{
			cout << "�����ʽ����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (lowerCh < 2)
		{
			cout << "���ִ�С����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	cout << "���������ָ���(��2)" << endl;
	while (1)
	{
		if (!(cin >> numberCh))
		{
			cout << "�����ʽ����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (numberCh < 2)
		{
			cout << "���ִ�С����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	cout << "�����������ַ�����(��2)" << endl;
	while (1)
	{
		if (!(cin >> otherCh))
		{
			cout << "�����ʽ����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		if (otherCh < 2)
		{
			cout << "���ִ�С����" << endl;
			cin.clear();
			cin.ignore(999999999, '\n');
			continue;
		}
		break;
	}
	if (upperCh + lowerCh + numberCh + otherCh > passwordLength)
	{
		cout << "��������֮�ʹ���ָ�������볤��" << endl;
		return 0;
	}
	cout << passwordLength << " " << upperCh << " " << lowerCh << " " << numberCh << " " << otherCh << endl;
	calcPassword(upperCh, lowerCh, numberCh, otherCh, passwordLength, randNumbers, password);
	for (int j = 0; j < passwordCounts; j++)
	{
		password[j][passwordLength] = '\0';
		cout << password[j] << endl;
	}
	return 0;
}
