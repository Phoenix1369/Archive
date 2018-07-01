#include <cstdio>
int M, N, ret=0;

int main()
{
	scanf(" %d%d", &N, &M);
	// Team A: 2p <= n, p <= m
	// Team B: 2q <= m, q <= n
	// Maximize: 2p+q + 2q+p -> 3(p+q)
	// printf("%d\n", std::min((M+N)/3, std::min(M, N));
	while(M && N && ((M > 1) || (N > 1)))
	{
		while(N && (M > N))
		{
			M -= 2;
			--N;
			++ret;
		}
		while(M && (N > M))
		{
			N -= 2;
			--M;
			++ret;
		}
		while((M == N) && (M > 2))
		{
			M -= 3;
			N -= 3;
			ret += 2;
		}
		if((M == N) && (M == 2))
			M -= 2, --N, ++ret;
	}
	printf("%d\n", ret);
	return 0;
}
