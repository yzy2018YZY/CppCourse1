//1850059 ��1�� ��־Զ
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&fc_begin);	//��ó�ʼӲ����ʱ������

	/* �˴�����ĳ���ʼ */

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
		for (y = x + 14; y <= 876; y++)//612 - 598 = 14, 512 - 492 = 14 ...x��y�������14
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

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&fc_end);//�����ֹӲ����ʱ������
	printf("ʱ��Ƶ�� : %.3fGHz\n", (double)( tick.QuadPart ) / 1024 / 1024);
	printf("ʱ�Ӽ��� : %.0f\n", (double)(fc_end.QuadPart - fc_begin.QuadPart));
	printf("%6f��\n", (double)(fc_end.QuadPart - fc_begin.QuadPart) / (double)(tick.QuadPart));

	return 0;
}
