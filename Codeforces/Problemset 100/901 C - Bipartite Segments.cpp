#include <algorithm>
#include <cstdio>
#include <vector>
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 3E5+5;
int	A[MAXN]{ }; // Bipartite Subgraph on Segment [i,A[i]]
int dfsid[MAXN]{ };
int dfslo[MAXN]{ };
vin graph[MAXN]{ };
int    mn[MAXN]{ };
int    mx[MAXN]{ };
lld	P[MAXN]{ };
bool seen[MAXN]{ };
int    up[MAXN]{ };
int a, b, dfsct=1;
int M, N, Q;

void dfs(int cur)
{	// Cycle Finding
	dfsid[cur] = dfslo[cur] = dfsct++;
	for(auto nxt: graph[cur]) if(!dfsid[nxt])
	{
		up[nxt] = cur;
		dfs(nxt);
	}
	for(auto nxt: graph[cur]) if(nxt != up[cur])
		dfslo[cur] = std::min(dfslo[nxt], dfslo[cur]);
}

void dfs2(int cur)
{	// Cycle Extrema
	seen[cur] = true;
	for(auto nxt: graph[cur])
		if(!seen[nxt] && (dfslo[nxt] == dfslo[cur]))
			dfs2(nxt);
	mn[dfslo[cur]] = std::min(cur, mn[dfslo[cur]]);
	mx[dfslo[cur]] = std::max(cur, mx[dfslo[cur]]);
}

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		scanf(" %d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i <= N; ++i)
		if(!dfsid[i]) dfs(i);
	for(int i = 1; i <= N; ++i)
		A[i] = N;
	for(int i = 1; i <= N; ++i)
		if(!seen[i] && (dfsid[i] != dfslo[i]))
		{
			mn[dfslo[i]] = mx[dfslo[i]] = i;
			dfs2(i);
			A[mn[dfslo[i]]] = mx[dfslo[i]]-1;
		}
	for(int i = N-1; i >= 1; --i)
		A[i] = std::min(A[i+1], A[i]);
	for(int i = 1; i <= N; ++i)
		P[i] = (A[i]-i+1) + P[i-1];
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		scanf(" %d%d", &a, &b);
		int ptr = std::max(std::min(std::upper_bound(A+1, A+N+1, b)-A, b+1), a);
		int k = b-ptr+1;
		printf("%lld\n", 1LL*k*(k+1)/2 + P[ptr-1]-P[a-1]);
	}
	return 0;
}