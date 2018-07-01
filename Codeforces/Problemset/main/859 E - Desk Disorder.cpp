#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 2E5+5;
const int MOD  = 1E9+7;
int final[MAXN]{ };
int graph[MAXN]{ }; // Single Child
bool  low[MAXN]{ };
int   val[MAXN]{ };
bool  vis[MAXN]{ };
int N, ret=1;

vin G[MAXN]{ };

int dfs(int cur)
{
	if(!graph[cur]) // Hit the Base of a Leaf
	{
		final[cur] += val[cur];
		return 1;
	}
	G[graph[cur]].push_back(cur); // Reverse Graph
	if(vis[graph[cur]])
	{
		if(!graph[graph[cur]]) // Sink Node with Multiple Sources
			final[graph[cur]] += val[cur];
		return 1;	// Entering Old Loop (multiple roots) ->O<-
	}
	if(val[graph[cur]])	// Current Self-Loop -> Cycle
		return (cur == graph[cur]) ? 1 : 2;	// Rotate Along Cycle
	val[graph[cur]] = val[cur] + 1;
	int res = dfs(graph[cur]);
	vis[graph[cur]] = true;
	return res;
}

int dfs2(int cur)
{
	int rkt = 1;
	for(auto nxt: G[cur])
		rkt += dfs2(nxt);
	return rkt;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int u, v;
		scanf(" %d%d", &u, &v);
		// Allow Self-Loops!
		graph[u] = v;
		low[v] = true;
	}
	N <<= 1;
	for(int i = 1; i <= N; ++i) if(!low[i]) // Root of Tree
	{	// Only Chains + Loops
		val[i] = 1;
		ret = 1LL * ret * dfs(i) % MOD;
		vis[i] = true;
	}
	for(int i = 1; i <= N; ++i) if(!val[i])
	{	// Arbitrarily Begin at a Cycle
		val[i] = 1;
		ret = 1LL * ret * dfs(i) % MOD;
		vis[i] = true;
	}
	for(int i = 1; i <= N; ++i) if(!graph[i])
		ret = 1LL * ret * dfs2(i) % MOD; // Source of Tree
	printf("%d\n", ret);
	return 0;
}
