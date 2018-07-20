#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#define MMS(a,n,v) for(int i = 1; i <= n; a[i++] = v);
#define x first
#define y second
typedef std::pair<int,int> pii;
typedef std::vector<int> vin;
const int MAXN = 3e5+5;
int color[MAXN]{ };	// Component (BCC)
vin graph[MAXN]{ };
vin brt[MAXN]{ };	// Bridge Tree
int dis[MAXN]{ };	// Distance of BRT
int* low = color;	// DFS Lowest
int* pre = dis;		// DFS Preorder
std::set<pii> bridges;
int bcc, far, ord, m, n;

pii make_edge(int u, int v)
{
	if(u > v) std::swap(u, v);
	return std::make_pair(u, v);
}

void dfs(int cur, int prv)
{	// Find Articulation Bridges
	low[cur] = pre[cur] = ++ord;
	for(auto& nxt: graph[cur]) if(nxt != prv)
	{
		if(!pre[nxt])
		{
			dfs(nxt, cur);
			if(low[nxt] == pre[nxt])
				bridges.insert(make_edge(cur, nxt));
		}
		low[cur] = std::min(low[nxt], low[cur]);
	}
}

void dfs2(int cur)
{	// Contract Biconnected Components
	color[cur] = bcc;
	for(auto nxt: graph[cur])
		if(!bridges.count(make_edge(cur, nxt)) && !color[nxt])
			dfs2(nxt);
}

void dfs3(int cur)
{
	for(auto nxt: brt[cur]) if(dis[nxt] == -1)
	{
		dis[nxt] = dis[cur]+1;
		dfs3(nxt);
	}
	if(dis[cur] > dis[far])
		far = cur;
}

void run_dfs3()
{
	MMS(dis, bcc, -1);
	dis[far] = 0;
	dfs3(far);
}

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < m; ++i)
	{
		int x, y;
		scanf(" %d%d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bcc = ord = 0;
	dfs(1, 0);
	MMS(color, n, 0);
	for(int i = 1; i <= n; ++i)
		for(auto j: graph[i]) if(bridges.count(make_edge(i, j)))
		{	// Articulation Bridge
			if(!color[i]) { ++bcc; dfs2(i); }
			if(!color[j]) { ++bcc; dfs2(j); }
			brt[color[i]].push_back(color[j]);
		}
	far = color[1];
	run_dfs3();
	run_dfs3();
	printf("%d\n", dis[far]);
	return 0;
}