#include <cstdio>
const int MAXN = 1E5+5;
const int MOD = 1E9+7;
int    dp[MAXN][2]{ }; // dp[i][0,1]: Length [i], ends with [1,X]
int K, N, X;

int main()
{
	scanf(" %d%d%d", &N, &K, &X);
	dp[1][0] = 1;
	for(int i = 2; i <= N; ++i)
	{
		dp[i][0] =  1LL*(K-1)*dp[i-1][1] % MOD;
		dp[i][1] = (1LL*(K-2)*dp[i-1][1] + dp[i-1][0]) % MOD;
	}
	printf("%d\n", dp[N][X != 1]);
	return 0;
}
