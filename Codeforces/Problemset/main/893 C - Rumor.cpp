#include <cstdio>
#include <vector>
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 1E5+5;
int    au[MAXN]{ };
vin graph[MAXN]{ };
bool  vis[MAXN]{ };
int best, M, N;
lld ret=0LL;

void dfs(int cur)
{
	vis[cur] = true;
	if(au[cur] < au[best])
		best = cur;
	for(auto nxt: graph[cur]) if(!vis[nxt])
		dfs(nxt);
}

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &au[i]);
	for(int i = 1; i <= M; ++i)
	{
		int u, v;
		scanf(" %d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= N; ++i) if(!vis[i])
	{
		best = i;
		dfs(i);
		ret += au[best];
	}
	printf("%lld\n", ret);
	return 0;
}
