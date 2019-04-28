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

	//cout << "全局单变量地址       : " << &global_a << endl;				//加&表示取变量的地址
	//cout << "全局数组变量地址     : " << global_array << endl;			//数组名代表首地址，不需要&
	cout << "全局数组变量地址     : " << &global_array[0] << endl;
	cout << "全局数组变量地址     : " << &global_array[NUM] << endl;

	//cout << "局部单变量地址       : " << &local_a << endl;				//加&表示取变量的地址
	//cout << "局部数组变量地址     : " << local_array << endl;			//数组名代表首地址，不需要&

	cout << "局部数组变量地址     : " << local_array << endl;
	cout << "局部数组变量地址     : " << &local_array[NUM2] << endl;

	//cout << "静态局部单变量地址   : " << &local_static_a << endl;		//加&表示取变量的地址
	//cout << "静态局部数组变量地址 : " << local_static_array << endl;	//数组名代表首地址，不需要&

	return 0;
}
