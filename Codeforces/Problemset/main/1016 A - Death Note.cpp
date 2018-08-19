#include <cstdio>
int a, m, n;

int main()
{
	scanf(" %d%d", &n, &m);
	int r = m; // Remaining page space
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		int t = 0;
		if(a >= r)
		{
			a -= r;
			r = m;
			++t;
		}
		t += a / m;
		r -= a % m;
		if(r <= 0)
		{
			r += m;
			++t;
		}
		printf("%d%c", t, (i==n)?'\n':' ');
	}
	return 0;
}
