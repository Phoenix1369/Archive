#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXN = 5005;
int color[MAXN]{ }; // Component (SCC)
vin graph[MAXN]{ };
int indeg[MAXN]{ }; // In-degree (SCC)
vin trans[MAXN]{ }; // Transpose
bool seen[MAXN]{ };
int m, n, s;
vin tsort;

// Kosaraju's Algorithm - SCC

void dfs(int cur)
{
	seen[cur] = true;
	for(auto nxt: graph[cur])
		if(!seen[nxt]) dfs(nxt);
	tsort.push_back(cur);
}

void dfs2(int cur, int rep)
{
	color[cur] = rep;
	for(auto nxt: trans[cur])
		if(!color[nxt])
			dfs2(nxt, rep);
}

int main()
{
	scanf(" %d%d%d", &n, &m, &s);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		scanf(" %d%d", &u, &v);
		graph[u].push_back(v);
		trans[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i)
		if(!seen[i])
			dfs(i);
	std::reverse(ALL(tsort));
	int rep = 0;
	for(auto node: tsort)
		if(!color[node])
			dfs2(node, ++rep);
	for(int i = 1; i <= n; ++i)
		for(auto j: graph[i])
			if(color[i] != color[j])
				++indeg[color[j]];
	int ret = 0;
	for(int i = 1; i <= rep; ++i)
		if(!indeg[i] && (i != color[s]))
			++ret;
	printf("%d\n", ret);
	return 0;
}