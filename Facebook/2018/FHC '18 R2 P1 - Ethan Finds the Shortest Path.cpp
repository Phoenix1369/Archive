#include <algorithm>
#include <cstdio>
#define CODE "ethan_finds_the_shortest_path"
int K, N, T;

int sum(int n) { return n*(n+1)/2; }

int main()
{
	// freopen(CODE "_sample_input.txt", "r", stdin);
	// freopen("p1.in", "r", stdin);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d", &N, &K);
		if((K <= 2) || (N == 2))
		{
			printf("Case #%d: 0\n1\n", t);
			printf("1 %d %d\n", N, K);
			continue;
		}
		int M = std::min(K, N);
		printf("Case #%d: %d\n%d\n", t, sum(K-1)-sum(K-M)-K, M);
		for(int i = 1; i < M-1; ++i)
			printf("%d %d %d\n", i, i+1, K-i);
		printf("%d %d %d\n", M-1, N, K-M+1);
		printf("1 %d %d\n", N, K);
	}
	return 0;
}
/*
3
3 2
3 3
3 30
*/