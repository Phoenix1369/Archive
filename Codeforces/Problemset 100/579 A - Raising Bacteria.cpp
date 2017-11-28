#include <cstdio>
int N;

int main()
{
	scanf("%d", &N);
	printf("%d\n", __builtin_popcount(N));
	return 0;
}
