#include <cstdio>
typedef long long lld;
const int MAXN = 51;
const int MAXS = MAXN*MAXN;
int  card[MAXN]{ };
lld    dp[MAXN][MAXS]{ }; // [Len][Sum]
int A, N; // Len*Avg = Sum

int main()
{
	scanf(" %d%d", &N, &A);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &card[i]);
	dp[0][0] = 1; // Base Case
	for(int i = 1; i <= N; ++i)
	for(int len = N; len >= 0; --len)
	for(int sum = 0; sum < MAXS; ++sum) if(dp[len][sum]) // O(N^4)
		dp[len+1][sum+card[i]] += dp[len][sum];
	lld ret = 0;
	for(int len = 1; len <= N; ++len)
		ret += dp[len][len*A];
	printf("%lld\n", ret);
	return 0;
}