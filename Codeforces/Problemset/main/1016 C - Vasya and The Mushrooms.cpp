#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 3e5+5;
lld chain[2]{ };
lld base, sum;
int a[2][MAXN];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < 2; ++i)
	for(int j = 0; j < n; ++j)
		scanf("%d", &a[i][j]);
	base = sum = 0LL;
	for(int i = 0; i < n; ++i)
	{
		chain[0] += 1LL*i*a[0][i] + (2LL*n-i-1)*a[1][i]; // Top->Bot
		chain[1] += 1LL*i*a[1][i] + (2LL*n-i-1)*a[0][i]; // Bot->Top
		sum += a[0][i] + a[1][i];
	}
	lld ret = chain[0];
	for(int i = 0; i < n; ++i)
	{
		int b = (i & 1);
		ret = std::max(base + chain[b], ret);
		// Skip current column henceforth
		sum -= a[0][i] + a[1][i];
		// Brute-force coefficients of column to subtract
		chain[0] += sum - (2LL*i*a[0][i] + (2LL*n-1)*a[1][i]);
		chain[1] += sum - (2LL*i*a[1][i] + (2LL*n-1)*a[0][i]);
		base += (2LL*i)*a[b][i] + (2LL*i+1)*a[b^1][i];
	}
	printf("%lld\n", ret);
	return 0;
}
