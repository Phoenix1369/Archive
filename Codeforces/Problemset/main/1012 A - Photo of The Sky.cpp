#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1e6+5;
int a[MAXN];
int n, nn;

int main()
{
	scanf("%d", &n); nn=n*2;
	for(int i = 0; i < nn; ++i)
		scanf("%d", &a[i]);
	std::sort(a, a+nn);
	lld ret = 1LL * (a[n-1]-a[0]) * (a[nn-1]-a[n]);
	for(int i = 1; i < n; ++i)
		ret = std::min(1LL * (a[n-1+i]-a[i]) * (a[nn-1]-a[0]), ret);
	printf("%lld\n", ret);
	return 0;
}
