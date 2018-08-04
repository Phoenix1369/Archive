#include <cstdio>
typedef long long lld;
const int MAXK = 2e5+5;
int h[MAXK], k, n;
lld s;

bool solve()
{
	if(k > s)
		return false;
	if(1LL*(n-1)*k < s)
		return false;
	int c = 1;
	lld q = s/k, r = s%k;
	for(int i = 1; i <= k; ++i)
	{
		int d = q + (i <= r);
		if((i & 1) == 0)
			d *= -1;
		h[i] = (c += d);
	}
	return true;
}

int main()
{
	scanf(" %d%d%lld", &n, &k, &s);
	bool ret = solve();
	puts(ret ? "YES" : "NO");
	if(ret)
		for(int i = 1; i <= k; ++i)
			printf("%d%c", h[i], (i==k)?'\n':' ');
	return 0;
}
