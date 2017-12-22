#include <cstdio>
#include <set>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXN = 2E5+5;
vin graph[MAXN]{ };
int	R[MAXN]{ };
std::multiset<int> S[MAXN];
int N;

void dfs(int cur, int prv=0)
{
	for(auto nxt: graph[cur]) if(nxt != prv)
	{
		dfs(nxt, cur);
		if(S[cur].size() < S[nxt].size())
			S[cur].swap(S[nxt]);
		S[cur].insert(ALL(S[nxt]));
	}
	auto ptr = S[cur].upper_bound(-R[cur]);
	if( ptr != S[cur].end())
		S[cur].erase(ptr);
	S[cur].insert(-R[cur]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &R[i]);
	for(int i = 1; i <  N; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1);
	printf("%d\n", N-(int)S[1].size());
	return 0;
}