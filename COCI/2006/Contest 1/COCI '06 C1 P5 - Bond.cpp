#include <algorithm>
#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 20;
vin   sub[MAXN]{ }; // Subsets
double dp[2][1<<MAXN]{ };
int L, N, tem;
double A;

int main()
{
	scanf("%d", &N); L=1<<N;
	for(int mask = 1; mask < L; ++mask)
		sub[__builtin_popcount(mask)].push_back(mask);
	for(int h=1, i=1; h <= N; ++h, i^=1)
	{
		for(int j = 0; j < N; ++j)
		{
			scanf("%d", &tem);
			dp[i][1<<j] = tem / 100.0;
		}
		if(h == 1) continue;
		for(auto& mask: sub[h])
			for(int bit = 0; bit < N; ++bit) if((mask >> bit) & 1)
				dp[i][mask] = std::max(dp[i^1][mask & ~(1<<bit)] * dp[i][1<<bit], dp[i][mask]);
	}
	printf("%.6f\n", dp[N&1][L-1] * 100.0);
	return 0;
}