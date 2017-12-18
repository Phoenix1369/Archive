#include <cstdio>
const int MAXN = 1E6+5;
const int MOD  = 1E9+7;
int   col[MAXN]{ };
int   row[MAXN]{ };
int K, M, N;

int main()
{
	scanf(" %d%d%d", &N, &M, &K);
	for(int i = 1; i <= M; ++i)
		col[i] = 1;
	for(int i = 1; i <= N; ++i)
		row[i] = 1;
	for(int _ = 0; _ < K; ++_)
	{
		char cmd; int X, Y;
		scanf(" %c%d%d", &cmd, &X, &Y);
		switch(cmd)
		{
		case 'R': row[X] = 1LL*row[X]*Y % MOD; break;
		case 'S': col[X] = 1LL*col[X]*Y % MOD; break;
		}
	}
	int csum=0, psum=0, rsum=0;
	for(int i = 1; i <= M; ++i)
	{
		csum = (1LL*col[i]*i % MOD + csum) % MOD;
		psum = (1LL*col[i]*M % MOD + psum) % MOD;
	}
	for(int i = 1; i <= N; ++i)
		rsum = ((1LL*(i-1)*psum % MOD + csum) % MOD * row[i] % MOD + rsum) % MOD;
	printf("%d\n", rsum);
	return 0;
}