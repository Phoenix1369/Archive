#include <cstdio>
#include <utility>
#include <vector>
typedef std::pair<int,int> pii;
typedef std::vector<int> vin;
const int MAXN = 1e6+5;
vin a[MAXN], g[MAXN];
int d[MAXN]{ }, ret[MAXN];
int n, x, y;

void augment(int i, int j, int v)
{
	a[i][j] += v;
	if(pii(a[i][j], j) > pii(a[i][d[i]], d[i]))
		d[i] = j;
}

void dfs(int cur, int prv=0)
{
	for(int nxt: g[cur]) if(nxt != prv)
	{
		dfs(nxt, cur);
		bool sw = (a[cur].size() < a[nxt].size());
		int mnd = (sw ? cur : nxt);
		int mxd = (sw ? nxt : cur);
		int mns = a[mnd].size();
		int mxs = a[mxd].size();
		// Merge: Small -> Large
		for(int i = 0; i < mns; ++i)
			augment(mxd, mxs-i-1, a[mnd][mns-i-1]);
		if(!sw) continue;
		a[cur] = std::move(a[nxt]);
		d[cur] = d[nxt];
	}
	a[cur].push_back(1);
	if(!g[cur].empty())
		augment(cur, a[cur].size()-1, 0);
	ret[cur] = a[cur].size()-d[cur]-1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		scanf(" %d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		printf("%d\n", ret[i]);
	return 0;
}
