#include <cstdio>
#include <set>
#define SZ(x) ((int)(x).size())
typedef std::set<int> sin;
const int MAXN = 2e5+5;
int q[MAXN], x[MAXN], y[MAXN];
sin g[MAXN];
int k, m, n;
sin trip;

void dfs(int cur)
{
    if((SZ(g[cur]) >= k) || !trip.count(cur))
		return;
    trip.erase(cur);
    for(auto nxt: g[cur])
         dfs(nxt);
	g[cur].clear();
}

int main()
{
    scanf(" %d%d%d", &n, &m, &k);
    for(int i = 0; i < m; ++i)
    {
		scanf(" %d%d", &x[i], &y[i]);
        g[x[i]].insert(y[i]);
        g[y[i]].insert(x[i]);
    }
    for(int i = 1; i <= n; ++i)
        trip.insert(i);
    for(int i = 1; i <= n; ++i)
        dfs(i);
    for(int i = m-1; i >= 0; --i)
    {
        q[i] = SZ(trip);
        g[x[i]].erase(y[i]);
        g[y[i]].erase(x[i]);
        dfs(x[i]);
        dfs(y[i]);
    }
    for(int i = 0; i < m; ++i)
		printf("%d\n", q[i]);
    return 0;
}

