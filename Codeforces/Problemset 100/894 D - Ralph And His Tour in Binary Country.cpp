#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) std::begin(x), std::end(x)
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 1E6+5;
int	D[MAXN]{ };	// Distance from Root=[1]
int	E[MAXN]{ };	// Edge: node[i]<->parent[i]
vin graph[MAXN]{ };	// Descendants sorted by Depth
std::vector<lld> psum[MAXN]{ }; // Prefix Sum of Distances
int H, N, Q, src;

void merge(int cur, const vin& lhs, const vin& rhs)
{
	auto jtr = lhs.begin(), ktr = rhs.begin();
	while((jtr != lhs.end()) && (ktr != rhs.end()))
		if(D[*jtr] <= D[*ktr])
			graph[cur].push_back(*jtr++);
		else
			graph[cur].push_back(*ktr++);
	graph[cur].reserve(graph[cur].size() + (lhs.end()-jtr) + (rhs.end()-ktr));
	graph[cur].insert(graph[cur].end(), jtr, lhs.end());
	graph[cur].insert(graph[cur].end(), ktr, rhs.end());
}

void dfs(int cur, int acc)
{	// Sort Descendants by Depth
	if(cur > N) return;
	D[cur] = acc + E[cur];
	int nxt = cur<<1;
	dfs(nxt  , D[cur]);
	dfs(nxt|1, D[cur]);

	graph[cur] = { cur };
	if(nxt+1 <= N)
		merge(cur, graph[nxt], graph[nxt+1]);
	else if(nxt <= N)
		graph[cur].insert(graph[cur].end(), ALL(graph[nxt]));

	psum[cur].reserve(graph[cur].size());
	for(auto jtr: graph[cur])
		if(jtr == cur)
			psum[cur].push_back(0);
		else
			psum[cur].push_back(psum[cur].back() + D[jtr] - D[cur]);
}

lld aggregate(int node, int path)
{	// Sum of Descendants
	auto ptr = std::upper_bound(ALL(graph[node]), D[node]+H-path,
		[&](int val, int elm){ return val < D[elm]; });
	int idx = ptr - graph[node].begin();
	return 1LL*(H-path)*idx - psum[node][idx-1];
}

lld dfs2(int cur, int len, lld acc)
{	// Traverse Upwards
	len += E[cur];
	if((cur <= 1) || (len >= H))
		return acc;
	acc += H-len;	 // Include Parent Node of [cur,nxt]
	int nxt = cur^1; // Extract Sibling
	if((nxt <= N) && (len + E[nxt] < H))
		acc += aggregate(nxt, len+E[nxt]);
	return dfs2(cur>>1, len, acc);
}

int main()
{
	scanf(" %d%d", &N, &Q);
	for(int i = 2; i <= N; ++i)
		scanf("%d", &E[i]);
	dfs(1, 0);
	for(int _ = 0; _ < Q; ++_)
	{
		scanf(" %d%d", &src, &H);
		printf("%lld\n", dfs2(src, 0, aggregate(src, 0)));
	}
	return 0;
}
