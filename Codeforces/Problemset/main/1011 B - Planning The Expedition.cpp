#include <cstdio>
const int MAXA = 101;
int cnt[MAXA];
int a, m, n;

bool f(int day)
{
	int guy = 0;
	for(int i = 1; i < MAXA; ++i)
		guy += cnt[i] / day;
	return (guy >= n);
}

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < m; ++i)
	{
		scanf("%d", &a);
		++cnt[a];
	}
	int lo=0, hi=m;
	while(lo < hi)
	{
		int ce=(lo+hi+1)/2;
		if(f(ce))
			lo = ce;
		else
			hi = ce-1;
	}
	printf("%d\n", lo);
	return 0;
}
