#include <cstdio>
const int MAXN = 5005;
short	A[MAXN]{ };
bool   dp[MAXN][MAXN]{ };
// dp[i][j]: Whether i-th animal wins if `i-1` said number `j`.
int  S[2][MAXN][2]{ }; // S[i][j][k]: [cur,nxt][idx][loss,wins]
int K, M, N;

int main()
{
	scanf(" %d%d%d", &N, &M, &K);
	for(int i = 0; i < N; ++i)
		scanf("%hd", &A[i]);
	for(int i = 0; i < N; ++i)
	{
		dp[i][M-1] = 0;
		int h = (M-2) & 1;
		S[h][i][0] = M-1;
		S[h][i][1] = MAXN*2;
	}
	for(int j = M-2; j >= 0; --j)
	{
		int h = (j & 1);
		for(int i = 0; i < N; ++i)
		for(int k = 0; k < 2; ++k)
			S[h^1][i][k] = S[h][i][k];
		for(int i = 0; i < N; ++i)
		{
			int nxt = (i+1) % N;
			dp[i][j] = (j+K >= S[h][nxt][A[i] == A[nxt]]);
			S[h^1][i][dp[i][j]] = j;
		}
	}
	for(int i = 0; i < N; ++i)
		printf("%hd ", A[i] ^ !dp[i][0]);
	putchar('\n');
	return 0;
}