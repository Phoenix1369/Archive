#include <algorithm>
#include <cstdio>
const int MAXC = 1e5+5;
const int MAXK = 11;
const int MAXN = 505;
int card[MAXC]{ };		// Count
int dp[MAXN][MAXK * MAXN]{ };	// dp[i][j]: i people with j cards [fixed num]
int fave[MAXC]{ };		// Count
int h[MAXK]{ };
int c, f, K, N;

int main()
{
	scanf(" %d%d", &N, &K);
	int KN = K*N;
	for(int i = 0; i < KN; ++i)
	{
		scanf("%d", &c);
		++card[c];
	}
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &f);
		++fave[f];
	}
	for(int i = 1; i <= K; ++i)
		scanf("%d", &h[i]);
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < KN; ++j)
	for(int k = 1; (k <= K) && (j+k <= KN); ++k)
		dp[i+1][j+k] = std::max(dp[i][j] + h[k], dp[i+1][j+k]);
	int ret = 0;
	for(int i = 1; i < MAXC; ++i)
		ret += dp[fave[i]][card[i]];
	printf("%d\n", ret);
    return 0;
}