#include <cstdio>
int N;

int main()
{
	scanf("%d", &N);
	int ch = (N+1)>>1;
	printf("%d\n%d", (N & 1) ^ ((N>>1) & 1), ch);
	if(N & 1) printf(" 1");
	if(N & 2) printf(" %d", ch);
	int k = (N & 1) + 1;
	for(int i = k; i*2 < N; i += 2)
		printf(" %d %d", i, N+k-i);
	putchar('\n');
	return 0;
}