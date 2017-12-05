#include <algorithm>
#include <cstdio>
typedef long long lld;
const int INFN = 1E9+7;
const int MAXN = 1E5+5;
int   cnt[MAXN]{ };
lld    dp[MAXN][2]{ }; // [0,1] Cards Left
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &cnt[i]);
		for(int j = 0; j < 2; ++j)
			dp[i][j] = -INFN;
	}
	dp[1][cnt[1] & 1] = cnt[1]>>1;
	for(int i = 2; i <= N; ++i)
	{
		int half = cnt[i]>>1;
		if(cnt[i] & 1)
		{
			dp[i][0] = dp[i-1][1] + half + 1;
			dp[i][1] = std::max(dp[i-1][0], dp[i-1][1]) + half;
		}
		else
		{	// No Remaining Cards
			dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]) + half;
			if(cnt[i]) dp[i][1] = dp[i-1][1] + (cnt[i]-1)/2 + 1;
		}
		for(int j = 0; j < 2; ++j)
			if(dp[i][j] < 0) dp[i][j] = -INFN;
	}
	printf("%lld\n", std::max(dp[N][0], dp[N][1]));
	return 0;
}