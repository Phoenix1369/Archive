#include <cstdio>
#include <cstring>
#define MMS(x, y) memset((x), (y), sizeof(x))
const int MAXB = 1005;
const int MOD  = 1E9+7;
int   dpC[MAXB][MAXB]{ };
int A[MAXB], P[MAXB];
int N, ret=1LL;

int main()
{
	MMS(dpC, 0);
	dpC[0][0] = 1;
	scanf("%d", &N);
	for(int i = 1; i <= 1000; ++i)
	{	// Binomial Coefficients
		dpC[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			dpC[i][j] = (1LL * dpC[i-1][j-1] + dpC[i-1][j]) % MOD;
	}
	A[0] = P[0] = 0;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		P[i] = A[i] + P[i-1];
	}
	for(int i = 1; i <= N; ++i)
		ret = 1LL * dpC[P[i]-1][A[i]-1] * ret % MOD;
	printf("%d\n", ret);
	return 0;
}
