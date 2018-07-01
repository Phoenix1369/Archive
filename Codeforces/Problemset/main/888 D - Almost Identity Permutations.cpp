#include <algorithm>
#include <cstdio>
#include <numeric>
typedef long long lld;
lld mul[5] = { 1, 1, 1, 2, 9 };
lld dp[5]{ };
int K, N;

lld choose(int k)
{
	lld ret = 1LL;
	for(int i = 0; i < k; ++i)
		ret *= (N-i);
	for(int i = 1; i <= k; ++i)
		ret /= i;
	return ret;
}

int main()
{
	scanf(" %d%d", &N, &K);
	dp[1] = 1;
	for(int k = 2; k <= K; ++k)
		dp[k] = choose(k) * mul[k] + dp[k-1];
	printf("%lld\n", dp[K]);
	return 0;
}
