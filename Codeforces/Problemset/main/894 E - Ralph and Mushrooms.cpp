#include <cmath>
#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
typedef long long lld;
const int MAXN = 1E6+5;
int dfsid[MAXN]{ };
int dfslo[MAXN]{ };
lld final[MAXN]{ };
vin   scc[MAXN]{ };
bool seen[MAXN]{ };
int dfsct=1;
int M, N, S;
vin stack;

struct Edge { int v, w; };
std::vector<Edge> graph[MAXN]{ };

inline lld sum (int n) { return 1LL*n*(n+1)/2; }
inline lld sum2(int n) { return 1LL*n*(n+1)*(n+2)/6; }

void dfs(int cur)
{	// Tarjan's SCC Algorithm
	int dlo;
	seen[cur] = true;
	stack.push_back(cur);
	dfsid[cur] = dfslo[cur] = dlo = dfsct++;
	for(auto nxt: graph[cur])
	{
		if(!dfsid[nxt.v])
			dfs(nxt.v);
		if(seen[nxt.v])	// Within same SCC
			dlo = std::min(dfslo[nxt.v], dlo);
	}
	dfslo[cur] = std::min(dlo, dfslo[cur]);
	if(dfsid[cur] != dfslo[cur]) return;
	while(true)
	{	// Contract SCC
		int nxt = stack.back();
		scc[dfsid[cur]].push_back(nxt);
		dfslo[nxt] = dfslo[cur];
		seen[nxt] = false;
		stack.pop_back();
		if(nxt == cur) break;
	}
}

void dfs2(int cur)
{	// Implicit DP on DAG
	lld res = 0LL;
	seen[cur] = true;
	for(auto nod: scc[cur])
	for(auto nxt: graph[nod]) if(dfslo[nxt.v] != cur)
	{	// Maximize Single External Edge
		if(!seen[dfslo[nxt.v]])
			dfs2(dfslo[nxt.v]);
		res = std::max(final[dfslo[nxt.v]] + nxt.w, res);
	}
	else
	{	// Exhaust Internal Edges
		int pass = sqrt(2*nxt.w);
		while(sum(pass) > nxt.w) --pass;
		final[cur] += 1LL*nxt.w*(pass+1) - sum2(pass);
	}
	final[cur] += res;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		graph[u].push_back({ v, w });
	}
	scanf("%d", &S);
	dfs(S);
	dfs2(dfslo[S]);
	printf("%lld\n", final[dfslo[S]]);
	return 0;
}