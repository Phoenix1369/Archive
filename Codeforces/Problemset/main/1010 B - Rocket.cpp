#include <cstdio>
const int MAXN = 30;
int p[MAXN];
int m, n, r;

void out(int x)
{
	printf("%d\n", x);
	fflush(stdout);
}

int main()
{
	scanf(" %d%d", &m, &n);
	for(int i = 0; i < n; ++i)
	{
		out(i+1);
		scanf("%d", &p[i]);
		if(!p[i]) return 0;
	}
	for(int lo=n+1, hi=m, k=0;; ++k)
	{
		int ce=(lo+hi)/2;
		out(ce);
		scanf("%d", &r);
		if(!r) break;
		if((r == 1) ^ (p[k%n] == 1))
			hi = ce;
		else
			lo = ce+1;
	}
	return 0;
}
