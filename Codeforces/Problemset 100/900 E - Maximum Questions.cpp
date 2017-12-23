#include <algorithm>
#include <cstdio>
#include <utility>
typedef std::pair<int,int> pii;
const int MAXC = 1E5+5;
char buff[MAXC]{ };
pii    dp[MAXC]{ };	// pair[beauty,-replace]
int	T[MAXC][3]{ };	// char[a,b,?]
int M, N;

int main()
{
	scanf(" %d%s%d", &N, buff+1, &M);
	for(int i = 1; i <= N; ++i)
	{
		if(buff[i] != 'b')
			T[i][0] = T[i-1][1] + 1;
		if((buff[i] != 'a') && T[i-1][0])
			T[i][1] = T[i-1][0] + 1;
		T[i][2] = T[i-1][2] + (buff[i] == '?');
	}
	for(int i = M; i <= N; ++i)
	{
		if(T[i][(M & 1) ^ 1] >= M) // Start of `T` string
			dp[i] = std::max(pii(dp[i-M].first+1, dp[i-M].second - (T[i][2] - T[i-M][2])), dp[i]);
		dp[i] = std::max(dp[i-1], dp[i]);
	}
	printf("%d\n", -dp[N].second);
	return 0;
}