#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
int cnt[MAXN<<1]{ };
int pre[MAXN]{ };
bool yes=false;
int m, n, p;
lld ret=0LL;

int main()
{
	scanf(" %d%d", &n, &m);
	++cnt[n];
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &p);
		int a = (p < m) ? -1 : (m < p) ? +1 : 0;
		pre[i] = pre[i-1] + a;
		int dex = pre[i]+n;
		if(yes |= !a)
			ret += cnt[dex] + cnt[dex-1];
		else
			++cnt[dex];
	}
	printf("%lld\n", ret);
	return 0;
}