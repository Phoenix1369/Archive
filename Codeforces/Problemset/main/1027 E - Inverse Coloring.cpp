#include <algorithm>
#include <cstdio>
#include <cstring>
#define MMS(x, y) memset(x, y, sizeof(x))
const int MAXN = 505;
const int MOD = 998244353;
const int mod_inv_2 = (MOD+1)/2;
int dp[2][MAXN][MAXN]{ }; // dp[i][j][k]: len=i, max=j, last=k
int K, N, n, ret=0;

void add_eq(int& a, int b)
{
	a += b;
	if(a >= MOD)
		a -= MOD;
}

int main()
{
	scanf(" %d%d", &N, &K);
	n = (N & 1);
	dp[0][0][0] = 1;
	for(int h = 0; h < N; ++h)
	{
		int i = (h & 1);
		MMS(dp[i^1], 0);
		for(int j = 0; j <= h; ++j)
		for(int k = 0; k <= h; ++k)
		{
			add_eq(dp[i^1][std::max(j,k+1)][k+1], dp[i][j][k]); // Same
			add_eq(dp[i^1][std::max(j,1)][1], dp[i][j][k]);		// Diff
		}
	}
	for(int j = 1; (j <= N) && (j < K); ++j)
	for(int k = 1; k <= N; ++k)
		add_eq(dp[n][j][k], dp[n][j][k-1]);

	for(int j = 1; (j <= N) && (j < K); ++j)
	for(int k = 1; (k <= N) && (k < K) && (1LL*j*k < K); ++k)
		add_eq(ret, 1LL * dp[n][j][N] * dp[n][k][N] % MOD);
	ret = 1LL*ret*mod_inv_2 % MOD;
	printf("%d\n", ret);
	return 0;
}
