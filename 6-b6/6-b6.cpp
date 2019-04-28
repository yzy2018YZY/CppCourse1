//1850059 º∆1∞‡ —Ó÷æ‘∂

#include <iostream>
using namespace std;

int main()
{
	const char *c[] = { "John learn C++ language",
			 "Be well!","You","Not very" };
	const char **p[] = { c + 3, c + 2, c + 1, c };
	const char ***pp = p + 2;
	cout << &c[0] << endl;
	cout << &c[1] << endl;
	cout << &c[2] << endl;
	cout << &c[3] << endl;
	/*int x[] = {1, 2, 3, 4, 5};
	int y[] = { 6, 7, 8, 9, 10 };
	int z[] = { 11, 12, 13, 14, 15 };
	int w[] = { 16, 17, 18, 19, 20 };
	int *p[] = {x, y, z, w};
	int **pp = p;*/
	/*cout << (**++pp);
	cout << (*--*++pp + 4);
	cout << (*pp[-2] + 3);
	cout << (pp[-1][-1] + 2);
	cout << endl;*/
	/*cout << pp << endl;
	cout << (**++pp) << endl;
	cout << *pp << endl;
	cout << *p[0] << endl;
	cout << *p[1] << endl;
	cout << *p[2] << endl;
	cout << *p[3] << endl;
	cout << (*--*++pp) << endl;
	cout << *pp << endl;
	cout << *p[0] << endl;
	cout << *p[1] << endl;
	cout << *p[2] << endl;
	cout << *p[3] << endl;*/
	//cout << p[-1] + 2;


	//cout << strlen("John learn C++ language");
	return 0;
}
