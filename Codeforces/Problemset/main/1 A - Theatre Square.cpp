#include <cstdio>
int A, M, N;

int main()
{
	scanf(" %d%d%d", &N, &M, &A);
	printf("%lld\n", 1LL * ((N+A-1)/A) * ((M+A-1)/A));
	return 0;
}