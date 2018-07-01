#include <cstdio>
const int MAXN = 5005;
const int MOD = 1E9+7;
int dp[2][MAXN]{ };
int cnt=0, N, way=0;
bool prv=false;
char C;

int main()
{
	scanf("%d", &N);
	dp[0][0] = 1;
	for(int h = 1; h <= N; ++h)
	{
		int i = (h & 1);
		scanf(" %c", &C);
		if(prv)
		{
			for(int j = 0; j < cnt; ++j)
				dp[i][j+1] = dp[i^1][j];
			dp[i][0] = 0;
		}
		else
		{
			for(int j = cnt, sum = 0; j >= 0; --j)
			{
				sum = (sum+dp[i^1][j]) % MOD;
				dp[i][j] = sum;
			}
		}
		cnt += (prv = (C == 'f'));
	}
	for(int i = 0; i <= cnt; ++i)
		way = (way+dp[N&1][i]) % MOD;
	printf("%d\n", way);
	return 0;
}