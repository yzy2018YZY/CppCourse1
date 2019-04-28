//1850059 º∆1∞‡ —Ó÷æ‘∂

#include<iostream>
using namespace std;

void daxie(int num, int flag)
{
	if (num && !flag)
	{
		cout << "¡„";
	}
	if (!num && flag == 99)
	{
		cout << "¡„";
	}
	switch (num)
	{
		case 1:
			cout << "“º";
			break;
		case 2:
			cout << "∑°";
			break;
		case 3:
			cout << "»˛";
			break;
		case 4:
			cout << "À¡";
			break;
		case 5:
			cout << "ŒÈ";
			break;
		case 6:
			cout << "¬Ω";
			break;
		case 7:
			cout << "∆‚";
			break;
		case 8:
			cout << "∞∆";
			break;
		case 9:
			cout << "æ¡";
			break;
	}
}

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	bool zero = false, top = true;
	cout << "«Î ‰»Î“ª∏ˆ[0.01-100“⁄)º‰µƒ ˝◊÷: " << endl;
	cin >> num;
	cout << "¥Û–¥Ω·π˚ «:" << endl;
	n1 = (int)(num / 1000000000);
	n2 = (int)(num / 100000000) % 10;
	n3 = (int)(num / 10000000) % 10;
	n4 = (int)(num / 1000000) % 10;
	n5 = (int)(num / 100000) % 10;
	n6 = (int)(num / 10000) % 10;
	n7 = (int)(num / 1000) % 10;
	n8 = (int)(num / 100) % 10;
	n9 = (int)(num / 10) % 10;
	num = num - ((double)(int)(num / 1000000000) * 1000000000);
	n10 = (int)(num) % 10;
	num = num - ((double)(int)(num / 100000000) * 100000000);
	n11 = (int)(num * 10 + 0.05) % 10;
	num = num - ((double)(int)(num / 10000000) * 10000000);
	n12 = (int)(num * 100 + 0.05) % 10;

	daxie(n1, 1);
	if (n1 != 0)
	{
		top = false;
		cout << " ∞";
	}

	daxie(n2, 1);
	if (n2 != 0)
	{
		top = false;
	}

	if (n1 != 0 || n2 != 0)
	{
		cout << "“⁄";
		//top = true;
	}

	daxie(n3, 1);
	if (n3 != 0)
	{
		top = false;
		cout << "«™";
	}

	daxie(n4, top ? 1 : n3);
	if (n4 != 0)
	{
		top = false;
		cout << "∞€";
	}

	daxie(n5, top ? 1 : n4);
	if (n5 != 0)
	{
		top = false;
		cout << " ∞";
	}

	daxie(n6, top ? 1 : n5);
	if (n6 != 0)
	{
		top = false;
	}

	if (n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0)
	{
		cout << "ÕÚ";
	}

	daxie(n7, 1);
	if (n7 != 0)
	{
		top = false;
		cout << "«™";
	}

	daxie(n8, top ? 1 : n7);
	if (n8 != 0)
	{
		top = false;
		cout << "∞€";
	}

	daxie(n9, top ? 1 : n8);
	if (n9 != 0)
	{
		top = false;
		cout << " ∞";
	}

	daxie(n10, top ? 1 : n9);

	if (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0 || n7 != 0 || n8 != 0 || n9 != 0 || n10 != 0)
	{
		cout << "‘≤";
	}
	if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 && n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 && n11 == 0 && n12 == 0)
	{
		daxie(0, 99);
		cout << "‘≤";
	}

	daxie(n11, 1);
	if (n11 != 0)
	{
		cout << "Ω«";
	}

	if (n12 == 0)
	{
		cout << "’˚";
	}
	else
	{
		if (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0
			|| n5 != 0 || n6 != 0 || n7 != 0 || n8 != 0 || n9 != 0 || n10 != 0)
		{
			daxie(n12, n11);
		}
		else
		{
			daxie(n12, 1);
		}
		cout << "∑÷";
	}
	cout << endl;
	return 0;
}
