#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 4e5+5;
int d, k, n, v;
vin g[MAXN];

void add_edge(int u)
{
	++v;
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs(int cur, int lim)
{
	if(!lim || (v == n))
		return;
	while((v < n) && ((int)g[cur].size() < k))
	{
		add_edge(cur);
		dfs(v, lim-1);
	}
}

bool solve()
{
	if(d >= n)
		return false;
	v = 1;
	for(int i = 1; i <= d; ++i)
		add_edge(i);
	if(k == 1)
		return (n <= 2);
	for(int i = 1; i <= d; ++i)
		dfs(i, std::min(i-1, d-i+1));
	return (v == n);
}

int main()
{
	scanf(" %d%d%d", &n, &d, &k);
	bool ret = solve();
	puts(ret ? "YES" : "NO");
	if(ret)
		for(int i = 1; i <= n; ++i)
		for(int j: g[i]) if(i < j)
			printf("%d %d\n", i, j);
	return 0;
}
