//1850059 计1班 杨志远
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&fc_begin);	//获得初始硬件定时器计数

	/* 此处是你的程序开始 */

	int a, b, c, d, e, f, g, h, i, count = 0;
	for (int x = 123; x <= 598; x++)
	{
	    b = x / 10 % 10;
	    if(b == 0)
	    {
	    	continue;
		}
	    c = x % 10;
	    if(c == 0 || b == c)
	    {
	    	continue;
		}
	    a = x / 100;
		if (a == b || a == c)
		{
			continue;
		}
		for (int y = x + 14; y <= 876; y++)//612 - 598 = 14, 512 - 492 = 14 ...x与y至少相差14
		{
			if(x + y < 966)
			{
				continue;
			}
			e = y / 10 % 10;
			if(e == 0 || e == a || e == b || e == c)
	        {
	    	    continue;
	  	    }
			f = y % 10;
			if(f == 0 || f == a || f == b || f == c || f == e)
	        {
	    	    continue;
	  	    }
			d = y / 100;
			if (d == e || d == f)
			{
				continue;
			}
			for (int z = y + 14; z <= 987; z++)
			{
				if(x + y + z != 1953)
				{
					continue;
				}
				h = z / 10 % 10;
				if (h == 0 || h == a || h == b || h == c || h == d || h == e || h == f)
				{
					continue;
				}
				i = z % 10;
				if (i == 0 || i == a || i == b || i == c || i == d || i == e || i == f || i == h)
				{
					continue;
				}
				g = z / 100;
				if (g == h || g == i || g == a || g == b || g == c || g == d || g == e || g == f)
				{
					continue;
				}
				count++;
				cout << "No." << setw(3) << count << " : " << x << "+" << y << "+" << z << "=" << 1953 << endl;
			}
		}
	}
	cout << "total=" << count << endl;

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&fc_end);//获得终止硬件定时器计数
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "时钟频率 : " << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "时钟计数 : " << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "秒" << endl;

	return 0;
}
