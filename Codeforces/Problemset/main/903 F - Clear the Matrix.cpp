#include <algorithm>
#include <cstdio>
#include <cstring>
#define MMS(x, y) memset((x), (y), sizeof (x))
const int K = 4;
const int P = K*3;
const int INFN = 0x3F3F3F3F;
const int MAXN = 1005;
const int MAXP = 1<<P;
int	A[K]{ };
char buff[K][MAXN]{ };
int dp[MAXN][K][MAXP]{ };
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < K; ++i)
		scanf("%d", &A[i]);
	for(int i = 0; i < K; ++i)
		scanf(" %s", buff[i]);
	MMS(dp, 0x3F); dp[0][0][0] = 0;
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < K; ++j)
	for(int mask = 0; mask < MAXP; ++mask)
	{
		for(int k = 0; k <= j; ++k)
		{	// Submatrix Transition
			if(k+1 == K) break;
			int one = (1<<(k+1))-1, S = 0;
			for(int l = 0; l <= k; ++l)
				S |= one<<(P-(k+K*l)-1);
			dp[i][j][mask | S] = std::min(dp[i][j][mask] + A[k], dp[i][j][mask | S]);
		}
		bool  B = (j+1 == K);
		int nxt = (j+1) % K , prv = (B) ? 2 : 3;
		if((mask & 1) || (i < prv) || (buff[nxt][i-prv] != '*'))
			dp[i+B][nxt][mask>>1] = std::min(dp[i][j][mask], dp[i+B][nxt][mask>>1]);
		if(B)	dp[i+1][j][MAXP-1] = std::min(dp[i][j][mask] + A[K-1], dp[i+1][j][MAXP-1]); // 4x4
	}
	int sub=0, ret=INFN;
	for(int j = 1; j < K; ++j)
	for(int i = K-1; i >= 0; --i)
		sub = (sub<<1) | (buff[i][N-j] == '*');
	for(int mask = 0; mask < MAXP; ++mask) if((mask & sub) == sub)
		ret = std::min(dp[N-1][K-1][mask], ret);
	printf("%d\n", ret);
	return 0;
}