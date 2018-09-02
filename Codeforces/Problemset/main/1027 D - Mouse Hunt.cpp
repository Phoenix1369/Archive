#include <algorithm>
#include <cstdio>
const int MAXN = 2e5+5;
int c[MAXN], g[MAXN];
int indeg[MAXN]{ }, sum[MAXN]{ };
bool seen[MAXN]{ };
int head, n;

void dfs(int cur)
{
	seen[cur] = true;
	if(!seen[g[cur]])
		dfs(g[cur]);
	else
		head = g[cur];
	if(head)
		c[cur] = std::min(c[g[cur]], c[cur]);
	if(cur == head)
	{
		sum[cur] = c[g[cur]];
		g[cur] = cur;
		head = 0;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &g[i]);
		sum[g[i]] += c[i];
		++indeg[g[i]];
	}
	// Sink node: min(sum of incident edges, cost of sink node)
	// Sink loop: min(cost along cycle)
	for(int i = 1; i <= n; ++i)
		if(!indeg[i])
			head=0, dfs(i);
	for(int i = 1; i <= n; ++i)
		if(!seen[i])
			head=0, dfs(i);
	int ret = 0;
	for(int i = 1; i <= n; ++i) if(g[i] == i)
		ret += std::min(sum[i], c[i]);
	printf("%d\n", ret);
	return 0;
}
