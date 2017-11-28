#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1E5+5;
int color[MAXN]{ };
vin graph[MAXN]{ };
int upper[MAXN]{ };
int cnt[2]{ };
int N;

void dfs(int cur)
{
	++cnt[color[cur]];
	for(auto nxt: graph[cur]) if(nxt != upper[cur])
	{
		color[nxt] = color[cur] ^ 1;
		upper[nxt] = cur;
		dfs(nxt);
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i < N; ++i)
	{
		int u, v;
		scanf(" %d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	color[1] = upper[1] = 0;
	dfs(1);
	// Multiply Colours, Exclude Current Edges
	printf("%lld\n", 1LL * cnt[0] * cnt[1] - N + 1);
	return 0;
}
