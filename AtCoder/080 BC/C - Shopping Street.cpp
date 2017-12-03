#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int	F[MAXN]{ };
int	P[MAXN][11]{ };
int L=1<<10, N, tem;

int bit_count(int n) { return (n) ? __builtin_popcount(n) : 0; }

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < 10; ++j)
	{
		scanf("%d", &tem);
		F[i] |= tem<<j;
	}
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < 11; ++j)
		scanf("%d", &P[i][j]);
	int ret = -1E9;
	for(int mask = 1; mask < L; ++mask)
	{
		int res = 0;
		for(int i = 0; i < N; ++i)
			res += P[i][bit_count(mask & F[i])];
		ret = std::max(res, ret);
	}
	printf("%d\n", ret);
	return 0;
}
