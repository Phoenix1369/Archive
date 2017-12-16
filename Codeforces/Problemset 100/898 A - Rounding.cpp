#include <cstdio>
int hi, lo, N;

int main()
{
	scanf("%d", &N);
	lo = N/10*10; hi = lo+10;
	printf("%d\n", (N-lo < hi-N) ? lo : hi);
	return 0;
}