//1850059 计1班 杨志远
#include <stdio.h>

int main()
{
	/* 此处是你的程序开始 */

	int a, b, c, d, e, f, g, h, i, count = 0;
	int x, y, z;
	for (x = 123; x <= 598; x++)
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
		for (y = x + 14; y <= 876; y++)//612 - 598 = 14, 512 - 492 = 14 ...x与y至少相差14
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
			for (z = y + 14; z <= 987; z++)
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
				printf("No.%3d : %d+%d+%d=1953\n", count, x, y, z);
			}
		}
	}
	printf("total=%d\n", count);

	/* 此处是你的程序结束 */

	return 0;
}
