#include <cstdio>
typedef long long lld;
lld ret=0LL;
int m, n;

lld sum(int k) { return 1LL * k * (k+1) / 2; }

int main()
{
	scanf(" %d%d", &n, &m);
	lld join = sum(n-1);
	lld split = sum(n/2) + sum(n-n/2-1);
	for(int i = 0; i < m; ++i)
	{
		int d, x;
		scanf(" %d%d", &x, &d);
		ret += 1LL*x*n;
		if(d < 0)
			ret += split * d;
		else
			ret += join * d;
	}
	printf("%.9f\n", 1.0 * ret / n);
    return 0;
}