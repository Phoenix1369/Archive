#include <cstdio>
typedef long long lld;
const int MOD = 1E9+7;
lld M, N;
int K;

int fPM(int bas, lld exp)
{
	int ret = 1;
	while(exp > 0LL)
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
	scanf(" %lld%lld%d", &N, &M, &K);
	if((K == 1) || ((K == -1) && ((N & 1LL) == (M & 1LL))))
		printf("%d\n", fPM(fPM(2, M-1), N-1));
	else
		puts("0");
	return 0;
}
