#include <cstdio>
#include <utility>
#include <vector>
const int INFN = 0x3F3F3F3F;
const int MAXN = 5005;
int    dp[MAXN][MAXN]{ };
int    up[MAXN][MAXN]{ };
int M, N, T;

struct Pair { int X, Y; };
std::vector<Pair> graph[MAXN]{ };

void display(int idx, int cur)
{
	if(idx) display(idx-1, up[idx][cur]);
	printf("%d ", cur);
}

int main()
{
	scanf(" %d%d%d", &N, &M, &T);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;
		scanf(" %d%d%d", &u, &v, &w);
		graph[u].push_back({ v, w });
	}
	for(int i = 0; i <= N; ++i)
	for(int j = 0; j <= N; ++j)
		dp[i][j] = INFN;
	dp[0][1] = 0;
	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j <= N; ++j) if(dp[i-1][j] < T)
		for(auto nxt: graph[j])
		{
			int cost = dp[i-1][j] + nxt.Y;
			if((cost <= T) && (cost < dp[i][nxt.X]))
			{
				dp[i][nxt.X] = cost;
				up[i][nxt.X] = j;
			}
		}
	}
	for(int i = N-1; i >= 0; --i) if(dp[i][N] <= T)
	{
		printf("%d\n", i+1);
		display(i, N);
		putchar('\n');
		break;
	}
	return 0;
}