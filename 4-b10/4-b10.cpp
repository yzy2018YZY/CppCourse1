//1850059 ��1�� ��־Զ

#include <iostream>
#include <stdio.h>
using namespace std;

/* ���������Ҫ�ĺ���������������ӵĺ��������������ѭ�� */


/* �ǵݹ鷨����������ε�һ�У��βΰ������ */
void print_line1(char end_char, char ch1)
{
	/* ����������ѭ������ */
	for (char ch2 = end_char; ch2 > ch1; ch2--)
	{
		cout << " ";
	}
	for (char ch3 = ch1; ch3 > 'A'; ch3--)
	{
		cout << ch3;
	}
	for (char ch4 = 'A'; ch4 <= ch1; ch4++)
	{
		cout << ch4;
	}

}

/* �ݹ鷨����������ε�һ�У��βΰ������ */
void print_line2(char start_char, char end_char, char print_char, int space, int layer)
{
	/* �����ڲ������κη�ʽ��ѭ������ */
	if (layer == 0)
	{
		return;
	}
	if (space != 0)
	{
		cout << " ";
		print_line2(start_char, end_char, print_char, space - 1, layer);
		return;
	}
	if (print_char == start_char)
	{
		cout << print_char;
	}
	if (print_char != start_char)
	{
		cout << print_char;
		print_line2(start_char, end_char, print_char - 1, 0, layer);
		cout << print_char;
	}
	if (print_char == end_char - layer + 1)
	{
		cout << endl;
		print_line2(start_char, end_char, end_char - layer + 2, layer - 2, layer - 1);
	}
}
//
//void print_line2(char end_char, char space)
//{
//	/* �����ڲ������κη�ʽ��ѭ������ */
//	if (space != 0)
//	{
//		cout << " ";
//		print_line2(end_char, space - 1);
//		return;
//	}
//	if (end_char == 'A')
//	{
//		cout << end_char;
//		return;
//	}
//	cout << end_char;
//	print_line2(end_char - 1, 0);
//	cout << end_char;
//}

/* �ǵݹ鷨����������ε�һ�У��βΰ������ */
void print_line3(char end_char, char ch1)
{
	/* ����������ѭ������ */
	for (char ch2 = 'A'; ch2 < ch1; ch2++)
	{
		cout << " ";
	}

	for (char ch3 = ch1; ch3 <= end_char; ch3++)
	{
		cout << ch3;
	}
	for (char ch4 = end_char - 1; ch4 >= ch1; ch4--)
	{
		cout << ch4;
	}
}

void print_line4(char start_char, char end_char, char print_char, int space, int layer)
{
	/* �����ڲ������κη�ʽ��ѭ������ */
	if (layer == 0)
	{
		return;
	}
	if (space != 0)
	{
		cout << " ";
		print_line4(start_char, end_char, print_char, space - 1, layer);
		return;
	}
	if (print_char == end_char)
	{
		cout << print_char;
	}
	if (print_char != end_char)
	{
		cout << print_char;
		print_line4(start_char, end_char, print_char + 1, 0, layer);
		cout << print_char;
	}
	if (print_char == end_char - layer + 1)
	{
		cout << endl;
		print_line4(start_char, end_char, end_char - layer + 2, end_char - start_char - layer + 2, layer - 1);
	}
}

//
///* �ݹ鷨�䵹�����ε�һ�У��βΰ������ */
//void print_line4(char start_char, char end_char, char space)
//{
//	/* �����ڲ������κη�ʽ��ѭ������ */
//	if (space != 0)
//	{
//		cout << " ";
//		print_line4(start_char, end_char, space - 1);
//		return;
//	}
//	if (start_char == end_char)
//	{
//		cout << end_char;
//		return;
//	}
//	cout << start_char;
//	print_line4(start_char + 1, end_char, 0);
//	cout << start_char;
//}

int main()
{
	char ch, end_ch;
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();
		while (getchar() != '\n')
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	cout << "�ǵݹ鷨1" << endl;
	/* ѭ������������Σ�����  print_line1 ��ӡÿһ�� */

	//�˴�����Լ��Ĵ���

	for (ch = 'A'; ch <= end_ch; ch++)
	{
		print_line1(end_ch, ch);
		cout << endl;
	}

	/* --End-- */

	cout << endl;

	cout << "�ݹ鷨1" << endl;
	/* ѭ������������Σ�����  print_line2 ��ӡÿһ�� */

	//�˴�����Լ��Ĵ���

	/*for (ch = 'A'; ch <= end_ch; ch++)
	{
		print_line2(ch, end_ch - ch, end_ch - 'A');
		cout << endl;
	}*/
	print_line2('A', end_ch, 'A', end_ch - 'A', end_ch - 'A' + 1);

	/* --End-- */
	cout << endl;

	cout << "�ǵݹ鷨2" << endl;
	/* ѭ������������Σ�����  print_line3 ��ӡÿһ�� */

	//�˴�����Լ��Ĵ���

	for (ch = 'A'; ch <= end_ch; ch++)
	{
		print_line3(end_ch, ch);
		cout << endl;
	}

	/* --End-- */
	cout << endl;

	cout << "�ݹ鷨2" << endl;
	/* ѭ������������Σ�����  print_line4 ��ӡÿһ�� */


	/*for (ch = 'A'; ch <= end_ch; ch++)
	{
		print_line4(ch, end_ch, ch - 'A');
		cout << endl;
	}*/
	print_line4('A', end_ch, 'A', 0, end_ch - 'A' + 1);

	/* --End-- */
	cout << endl;

	return 0;
}
