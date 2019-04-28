//1850059 º∆1∞‡ —Ó÷æ‘∂

#include<iostream>
using namespace std;

int main()
{
	double num;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
	bool zero, top = true;
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
	if (n1 == 0)
	{
		zero = true;
	}
	else
	{
		zero = false;
		top = false;
		switch (n1)
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
		cout << " ∞";
	}
	if (n2 == 0)
	{
		zero = true;
	}
	else
	{
		zero = false;
		top = false;
		switch (n2)
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
	if (n1 != 0 || n2 != 0)
	{
		cout << "“⁄";
	}
	if (n3 == 0)
	{
		zero = true;
	}
	else
	{
		zero = false;
		top = false;
		switch (n3)
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
		cout << "«™";
	}
	if (n4 == 0)
	{
		zero = true;
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n4)
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
		cout << "∞€";
	}
	if (n5 == 0)
	{
		zero = true;
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n5)
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
		cout << " ∞";
	}
	if (n6 == 0)
	{
		zero = true;
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n6)
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
	if (n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0)
	{
		cout << "ÕÚ";
	}
	if (n7 == 0)
	{
		zero = true;
	}
	else
	{
		zero = false;
		top = false;
		switch (n7)
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
		cout << "«™";
	}
	if (n8 == 0)
	{
		zero = true;
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n8)
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
		cout << "∞€";
	}
	if (n9 == 0)
	{
		zero = true;
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n9)
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
		cout << " ∞";
	}
	if (n10 == 0)
	{
		zero = true;
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n10)
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
	if (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0 || n7 != 0 || n8 != 0 || n9 != 0 || n10 != 0)
	{
		cout << "‘≤";
	}
	if (n11 == 0)
	{
		zero = true;
	}
	else
	{
		zero = false;
		top = false;
		switch (n11)
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
		cout << "Ω«";
	}
	if (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 + n11 + n12 == 0)
	{
		cout << "¡„‘≤";
	}
	if (n12 == 0)
	{
		zero = true;
		cout << "’˚";
	}
	else
	{
		if (zero && !top)
		{
			cout << "¡„";
		}
		zero = false;
		top = false;
		switch (n12)
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
		cout << "∑÷";
	}
	cout << endl;
	return 0;
}
