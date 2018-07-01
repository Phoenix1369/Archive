#include <cstdio>
int M, N;

int main()
{
	scanf(" %d%d", &M, &N);
	printf("%d\n", N * (M >> 1) + (M & 1) * (N >> 1));
	return 0;
}