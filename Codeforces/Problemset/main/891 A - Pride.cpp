#include <cstdio>
const int MAXN = 2017;
int	A[MAXN]{ };
int	G[MAXN][MAXN]{ };
int N, one=0;

template <typename T> T gcd(T a, T b) { return (b) ? gcd(b, a % b) : a; }

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		if(A[i] == 1) ++one;
		G[i][i] = A[i];
	}
	if(one) return printf("%d\n", N-one) & 0;
	for(int i = 1; i <= N; ++i)
	for(int j = i+1; j <= N; ++j)
		G[i][j] = gcd(A[j], G[i][j-1]);
	for(int k = 1; k <= N; ++k)
		for(int i = 1; i+k <= N; ++i)
			if(G[i][i+k] == 1)
				return printf("%d\n", N+k-1) & 0;
	puts("-1");
	return 0;
}
