#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
int d[MAXN];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	int head=1, tail=n;
	lld pref, ret, suff;
	pref = ret = suff = 0LL;
	while(head <= tail)
	{
		while((head <= tail) && (pref < suff))
			pref += d[head++];
		while((head <= tail) && (suff < pref))
			suff += d[tail--];
		if(pref == suff)
		{
			ret = pref;
			pref += d[head++];
		}
	}
	printf("%lld\n", ret);
    return 0;
}
