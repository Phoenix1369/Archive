#include <cstdio>
#include <utility>
#include <vector>
#define X first
#define Y second
typedef std::pair<int,int> pii;
typedef std::vector<int> vin;
typedef std::vector<pii> vip;
const int MAXN = 2E5+5;
int depth[MAXN]{ };
pii edges[MAXN]{ };
vip graph[MAXN]{ };
vip final; // Edge Pairs Taken
int M, N;

bool dfs(int cur)
{	// DFS Spanning Tree
	vin use;
	int src=0, upp=-1;
	for(auto nxt: graph[cur])
		if(!depth[nxt.X])
		{
			depth[nxt.X] = depth[cur] + 1;
			if(dfs(nxt.X)) use.push_back(nxt.Y);
		}
		else if(depth[nxt.X] > depth[cur])
			use.push_back(nxt.Y);
		else if(depth[nxt.X] == depth[cur] - 1)
			upp = nxt.Y; // Parent Node
	if(use.size() & 1U)
	{	// Take Parent's Edge
		if(upp != -1)	// Not Root Node
			final.emplace_back(upp, use[0]);
		src = 1;
	}
	for(int i = src; i < (int)use.size(); i += 2)
		final.emplace_back(use[i], use[i+1]);
	return !(use.size() & 1U);
}

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		scanf(" %d%d", &u, &v);
		graph[u].emplace_back(v, i);
		graph[v].emplace_back(u, i);
		edges[i] = { u, v };
	}
	for(int i = 1; i <= N; ++i) if(!depth[i])
	{
		depth[i] = 1;
		dfs(i);
	}
	printf("%u\n", final.size());
	for(auto itr: final)
	{
		pii A = edges[itr.X], B = edges[itr.Y];
		if(A.X == B.X)
			std::swap(A.X, A.Y);	// { a, b } { a, c }
		else if(A.X == B.Y)
			std::swap(A, B);	// { a, b } { c, a }
		else if(A.Y == B.Y)
			std::swap(B.X, B.Y);	// { b, a } { c, a }
		printf("%d %d %d\n", A.X, A.Y, B.Y);
	}
	return 0;
}
