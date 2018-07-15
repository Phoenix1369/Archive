#include <cstdio>
int C[2], x;

void rep_char(char c, int r)
{
	for(int i = 0; i < r; ++i)
		putchar(c);
}

int main()
{
	scanf(" %d%d%d", &C[0], &C[1], &x);
	bool gt = (C[1] > C[0]);
	rep_char('0'+gt, C[gt]-(x>>1));
	if((x & 1) == 0)
	{
		rep_char('0'+(gt^1), C[gt^1]-(x>>1)+1);
		for(int i = 1; i < x; ++i)
			putchar('1'-(gt ^ (i & 1)));
	}
	else
	{
		for(int i = 1; i < x; ++i)
			putchar('0'+(gt ^ (i & 1)));
		rep_char('0'+(gt^1), C[gt^1]-(x>>1));
	}
	putchar('\n');
	return 0;
}
