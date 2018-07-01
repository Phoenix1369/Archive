#include <algorithm>
#include <cstdio>
#include <numeric>
const int MAXN = 25;
int	A[MAXN]{ };
int     B[MAXN]{ };
int C, N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	std::iota(B, B+N, 0);
	std::sort(B, B+N, [&](int l, int r){ return A[l] < A[r]; });
	C = A[B[0]];
	for(int i = 1; i < N; ++i)
		A[B[i-1]] = A[B[i]];
	A[B[N-1]] = C;
	for(int i = 0; i < N; ++i)
		printf("%d ", A[i]);
	putchar('\n');
	return 0;
}