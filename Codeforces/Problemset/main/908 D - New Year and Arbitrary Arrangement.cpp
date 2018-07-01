#include <cstdio>
#define MMI(n) dfs_mmi(0, 1, MOD, (n))
const int MAXK = 1005;
const int MOD = 1E9+7;
int    dp[MAXK][MAXK]{ };
int A, B, Eab, K, Mab;

int dfs_mmi(int a, int b, int m, int n)
{
	return (m && n) ? dfs_mmi(b, a - b * (m / n), n, m % n) : (a < 0) ? (a + MOD) : a;
}

int dfs(int a, int b)
{
	if(dp[a][b])
		return dp[a][b];
	if(a+b >= K)
		return dp[a][b] = (a + b + Eab) % MOD;
	return dp[a][b] = (1LL*A*dfs(a+1, b) % MOD + 1LL*B*dfs(a, b+a) % MOD) * Mab % MOD;
}

int main()
{
	scanf("%d%d%d", &K, &A, &B);
	Mab = MMI(A+B); Eab = 1LL*A*MMI(B) % MOD;
	printf("%d\n", dfs(1, 0));
	return 0;
}