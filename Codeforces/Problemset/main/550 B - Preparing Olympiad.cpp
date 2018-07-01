#include <algorithm>
#include <cstdio>
const int MAXN = 15;
int	P[MAXN]{ };
int ans=0, K, L, N, R, X;

int main()
{
	scanf(" %d%d%d%d", &N, &L, &R, &X);
	for(int i = 0; i < N; ++i)
		scanf("%d", &P[i]);
	K = (1 << N);
	for(int mask = 0; mask < K; ++mask)
	{
		int cnt=0, max=P[0], min=P[N-1], sum=0;
		for(int bit = 0; bit < N; ++bit)
			if((mask >> bit) & 1)
			{
				max = std::max(P[bit], max);
				min = std::min(P[bit], min);
				sum += P[bit];
				++cnt;
			}
		if((cnt >= 2) && (L <= sum) && (sum <= R) && (max-min >= X)) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}
