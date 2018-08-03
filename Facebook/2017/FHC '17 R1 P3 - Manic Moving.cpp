#include <algorithm>
#include <cstdio>
#define CODE "manic_moving"
const int INFN = 2e7+7; // 2*N*N*G
const int MAXK = 5005;
const int MAXN = 105;
int D[MAXK], S[MAXK];
int dp[MAXK][2];		// dp[i][j] = Min. fuel to process i-th family, carrying j extra packages
int g[MAXN][MAXN];
int K, M, N, T;

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d%d", &N, &M, &K);
		for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= N; ++j)
			g[i][j] = (i == j) ? 0 : INFN;
		for(int i = 0; i < M; ++i)
		{
			int A, B, G;
			scanf(" %d%d%d", &A, &B, &G);
			if(A > B) std::swap(A, B);
			g[A][B] = g[B][A] = std::min(G, g[A][B]);
		}
		for(int i = 1; i <= K; ++i)
			scanf(" %d%d", &S[i], &D[i]);
		// Floyd-Warshall
		for(int k = 1; k <= N; ++k)
		for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= N; ++j)
			g[i][j] = std::min(g[i][k]+g[k][j], g[i][j]);
		// Dynamic Programming
		D[0] = 1;
		dp[0][0] = 0;
		dp[0][1] = INFN;
		for(int i = 1; i <= K; ++i)
		{	// Only current package
			dp[i][0] = INFN;
			dp[i][0] = std::min(dp[i-1][0] + g[D[i-1]][S[i]] + g[S[i]][D[i]], dp[i][0]);
			dp[i][0] = std::min(dp[i-1][1] + g[D[i-1]][D[i]], dp[i][0]);
			if(i == K) break;
			// Carrying next package
			dp[i][1] = INFN;
			dp[i][1] = std::min(dp[i-1][0] + g[D[i-1]][S[i]] + g[S[i]][S[i+1]] + g[S[i+1]][D[i]], dp[i][1]);
			dp[i][1] = std::min(dp[i-1][1] + g[D[i-1]][S[i+1]] + g[S[i+1]][D[i]], dp[i][1]);
		}
		if(dp[K][0] == INFN)
			dp[K][0] = -1;
		printf("Case #%d: %d\n", t, dp[K][0]);
	}
	return 0;
}
