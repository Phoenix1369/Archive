#include <algorithm>
#include <cstdio>
const int HASH = 999999001;
const int MAXN = 305;
const int MOD  = 1E9+7;
int fh[2][MAXN][MAXN]{ }; // Forward Hash [Static,Dynamic]
char grid[MAXN][MAXN]{ };
int rh[2][MAXN][MAXN]{ }; // Reverse Hash [Static,Dynamic]
int M, N;

int fPM(int bas, int exp)
{	// Fast Power Modulo Function
	int ret = 1;
	while(exp)
	{
		if(exp & 1)
			ret = (1LL * bas * ret) % MOD;
		bas = (1LL * bas * bas) % MOD;
		exp >>= 1;
	}
	return ret;
}

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
		scanf(" %s", grid[i]+1);
	for(int i = 1; i <= N; ++i)
	{	// Compute Fwd/Rev Hashes
		for(int j = 1; j <= M; ++j)
			fh[0][i][j] = (1LL * HASH * fh[0][i][j-1] % MOD + grid[i][j]) % MOD;
		for(int j = M; j >= 1; --j)
			rh[0][i][j] = (1LL * HASH * rh[0][i][j+1] % MOD + grid[i][j]) % MOD;
	}
	int ret = 1;
	int MN = std::min(M, N);
	for(int k = MN; k >= 2; --k)
	{	// Edge Length of a Square
		int hash_pow = fPM(HASH, k);
		int hash_ppw = fPM(hash_pow, k); // =HASH^(k^2)
		for(int j = k; j <= M; ++j)
		for(int i = 1; i <= N; ++i)
		{	// Add Current Row to Previous Sum
			fh[1][i][j] = (1LL * hash_pow * fh[1][i-1][j] % MOD + fh[0][i  ][j] + MOD - 1LL * hash_pow * fh[0][i  ][j-k] % MOD) % MOD;
			if(i <= k) continue; // Subtract Topmost Row
			fh[1][i][j] = (fh[1][i][j] + MOD - 1LL * hash_ppw * ((fh[0][i-k][j] + MOD - 1LL * hash_pow * fh[0][i-k][j-k] % MOD) % MOD) % MOD) % MOD;
		}
		for(int j = M-k+1; j >= 1; --j)
		for(int i = N; i >= 1; --i)
		{	// Add Current Row to Previous Sum
			rh[1][i][j] = (1LL * hash_pow * rh[1][i+1][j] % MOD + rh[0][i  ][j] + MOD - 1LL * hash_pow * rh[0][i  ][j+k] % MOD) % MOD;
			if(i >= N-k+1) continue; // Subtract "Bottommost" Row
			rh[1][i][j] = (rh[1][i][j] + MOD - 1LL * hash_ppw * ((rh[0][i+k][j] + MOD - 1LL * hash_pow * rh[0][i+k][j+k] % MOD) % MOD) % MOD) % MOD;
		}
		for(int j = k; j <= M; ++j)
		for(int i = k; i <= N; ++i)
			if(fh[1][i][j] == rh[1][i-k+1][j-k+1])
				ret = k, i=N, j=M, k=1; // Solution Found!
	}
	if(ret != 1)
		printf("%d\n", ret);
	else
		puts("-1");
	return 0;
}