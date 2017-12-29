#include <algorithm>
#include <cstdio>
int A, B, M=0, N;

int main()
{
	scanf("%d%d%d", &N, &A, &B);
	for(int i = 1; i < N; ++i)
		M = std::max(std::min(A / i, B / (N-i)), M);
	printf("%d\n", M);
	return 0;
}