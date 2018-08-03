#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 2e5+5;
vin graph[MAXN]{ };
int pos[MAXN], sze[MAXN];
int n, p, q;
vin pre;

void dfs(int cur)
{
	pos[cur] = pre.size();
	pre.push_back(cur);
	sze[cur] = 1;
	for(int nxt: graph[cur])
	{
		dfs(nxt);
		sze[cur] += sze[nxt];
	}
}

int main()
{
	scanf(" %d%d", &n, &q);
	for(int i = 2; i <= n; ++i)
	{
		scanf("%d", &p);
		graph[p].push_back(i);
	}	// Children are sorted
	dfs(1);
	for(int i = 0; i < q; ++i)
	{
		int k, u;
		scanf(" %d%d", &u, &k);
		if(k <= sze[u])
			printf("%d\n", pre[pos[u]+k-1]);
		else
			puts("-1");
	}
    return 0;
}
