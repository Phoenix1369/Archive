#include <algorithm>
#include <cmath>
#include <cstdio>
const int MAXA = 1e9;
const int MAXN = 16;
const int MAXM = 1e4+5;
int	   a[MAXN][MAXM];
int   dp[MAXN][MAXN][1<<MAXN]{ };	// Zero-init
int edge[MAXN][MAXN];
int m, n;

void calc() {
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j) {
		int bt = (1<<i)|(1<<j);
		dp[i][j][bt] = edge[i][j] = MAXA;
		for (int k = 0; k < m; ++k) {
			if (k) edge[i][j] = std::min(std::abs(a[i][k]-a[j][k-1]), edge[i][j]);
			dp[i][j][bt] = std::min(std::abs(a[i][k]-a[j][k]), dp[i][j][bt]);
		}	// Base case of (n == 2)
	}
}

int solve() {
	if (n == 1) return edge[0][0];
	if (n == 2) {
		int pass = dp[0][1][(1<<0)|(1<<1)];
		return std::min(pass, std::max(edge[0][1], edge[1][0]));
	}
	int N = (1<<n)-1;
	for (int mask = 1; mask <=N; ++mask)
	for (int from = 0; from < n; ++from) if ((mask >> from) & 1)
	for (int last = 0; last < n; ++last) if ((mask >> last) & 1) {
		if (from == last) continue;
		for (int dest = 0; dest < n; ++dest) {
			if ((mask >> dest) & 1) continue;	// New row
			int D = 1<<dest;
			int prev = dp[from][last][mask];
			if ((mask|D) == N) {
				prev = std::min(edge[from][dest], prev);
			}
			int pass = dp[last][dest][(1<<last)|(1<<dest)];
			dp[from][dest][mask|D] = std::max(
				std::min(prev, pass), dp[from][dest][mask|D]
			);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j) if (i != j) {
		ret = std::max(dp[i][j][N], ret);
	}
	return ret;
}

int main() {
	scanf(" %d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j) {
		scanf("%d", &a[i][j]);
	}
	calc();
	printf("%d\n", solve());
	return 0;
}
