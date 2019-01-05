#include <algorithm>
#include <cstdio>
const int MAXN = 2018;
const int MOD = 998244353;
int dp[2][MAXN];
int k, m, n;

int main() {
	scanf(" %d%d%d", &n, &m, &k);
	for (int h = 1; h <= n; ++h) {
		int i = (h & 1);
		int J = std::min(h-1, k);
		dp[i][0] = m;
		for (int j = 1; j <= J; ++j) {
			dp[i][j] = (1LL * dp[i^1][j-1] * (m-1) % MOD + dp[i^1][j]) % MOD;
		}
	}
	printf("%d\n", dp[n&1][k]);
	return 0;
}
