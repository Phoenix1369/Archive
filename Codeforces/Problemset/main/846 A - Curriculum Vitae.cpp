#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int	A[MAXN]{ };
int	P[MAXN]{ };
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for(int i = 1; i <= N; ++i)
		P[i] = A[i] + P[i-1];
	int ret = N;
	for(int i = 0; i <= N; ++i) // Remove Ones [0,i] and Zeroes [i+1,N]
		ret = std::min(P[i] + (N-i) - (P[N] - P[i]), ret);
	printf("%d\n", N-ret);
	return 0;
}
