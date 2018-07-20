#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
const int MOD = 998244353;
int ncr[MAXN][MAXN]{ };
int dp[MAXN]{ };
int a[MAXN], n;

void init()
{
	for(int i = 0; i <= n; ++i)
		ncr[i][0] = 1;
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= i; ++j)
		ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
}

int main()
{
	scanf("%d", &n);
	init();
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	dp[n] = 1;
	for(int i = n-1; i >= 0; --i)
		if((0 < a[i]) && (a[i] < n-i))
			for(int j = i+a[i]+1; j <= n; ++j)	// Choose subsequence and augment
				dp[i] = (1LL * ncr[j-i-1][a[i]] * dp[j] % MOD + dp[i]) % MOD;
	int ret = 0;
	for(int i = 0; i < n; ++i)
		ret = (dp[i] + ret) % MOD;
	printf("%d\n", ret);
    return 0;
}