#include <iostream>
using namespace std;

//const int NUM = 478221848;
//const int NUM = 496123456;
const int NUM = 485000000;
//const int NUM = 5;

const int NUM2 = 255300;

//int global_a;
//int global_array[498861631];
int global_array[NUM];


int main()
{
	//int local_a;
	//int local_array[518016];
	//int local_array[519124];
	int local_array[NUM2];

	//static int local_static_a;
	//static int local_static_array[8];

	//cout << "ȫ�ֵ�������ַ       : " << &global_a << endl;				//��&��ʾȡ�����ĵ�ַ
	//cout << "ȫ�����������ַ     : " << global_array << endl;			//�����������׵�ַ������Ҫ&
	cout << "ȫ�����������ַ     : " << &global_array[0] << endl;
	cout << "ȫ�����������ַ     : " << &global_array[NUM] << endl;

	//cout << "�ֲ���������ַ       : " << &local_a << endl;				//��&��ʾȡ�����ĵ�ַ
	//cout << "�ֲ����������ַ     : " << local_array << endl;			//�����������׵�ַ������Ҫ&

	cout << "�ֲ����������ַ     : " << local_array << endl;
	cout << "�ֲ����������ַ     : " << &local_array[NUM2] << endl;

	//cout << "��̬�ֲ���������ַ   : " << &local_static_a << endl;		//��&��ʾȡ�����ĵ�ַ
	//cout << "��̬�ֲ����������ַ : " << local_static_array << endl;	//�����������׵�ַ������Ҫ&

	return 0;
}
