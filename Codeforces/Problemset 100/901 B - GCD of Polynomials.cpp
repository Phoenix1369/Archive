#include <cstdio>
const int MAXN = 155;
int  P[2][MAXN] = { {1}, {0,1} };
int N;

void print(int K)
{
	printf("%d\n", K);
	for(int i = 0; i <= K; ++i)
		printf("%d ", P[K&1][i]);
	putchar('\n');
}

int main()
{
	scanf("%d", &N);
	for(int h=0, i=2; i <= N; h ^= 1, ++i)
		for(int j = 1; j <= i; ++j)
			P[h][j] = (P[h^1][j-1] + P[h][j]) & 1;
	print(N);
	print(N-1);
	return 0;
}