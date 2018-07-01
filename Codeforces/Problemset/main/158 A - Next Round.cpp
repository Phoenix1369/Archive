#include <algorithm>
#include <cstdio>
int K, M, N;
int A[55];

int main()
{
	scanf(" %d%d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	M = std::max(A[K-1], 1);
	for(int i = 0; i < N; ++i) if(A[i] < M)
		return printf("%d\n", i) & 0;
	printf("%d\n", N);
	return 0;
}
