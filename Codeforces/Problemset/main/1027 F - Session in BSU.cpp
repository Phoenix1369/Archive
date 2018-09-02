#include <cstdio>
#include <map>
#include <set>
const int MAXN = 1e6+5;
const int MAXU = MAXN<<1;
int a[MAXN], b[MAXN];
std::map<int,int> c;	// Coordinate Compression
int d[MAXU], e[MAXU];	// DSU: id, edges
int m[MAXU], m2[MAXU], s[MAXU];	// max, max2nd, size
int n, ret=0;

int find(int x)
{
	int y = x;
	while(y != d[y])
		y = d[y];
	while(x != y)
	{
		int z = d[x];
		d[x] = y;
		x = z;
	}
	return x;
}

void unite(int u, int v)
{
	u = find(u);
	v = find(v);
	++e[v];
	if(u == v) return;
	d[u] = v;
	e[v] += e[u];
	s[v] += s[u];
	std::set<int> heap = { m[u], m2[u], m[v], m2[v] };
	m[v] = *heap.rbegin();
	heap.erase(m[v]);
	m2[v] = *heap.rbegin();
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf(" %d%d", &a[i], &b[i]);
		c[a[i]] = c[b[i]] = 0;
	}
	int cnt=0;
	for(auto& itr: c)
		itr.second = ++cnt;
	for(int i = 1; i <= cnt; ++i)
		d[i]=i, e[i]=0, s[i]=1;
	for(int i = 0; i < n; ++i)
	{
		int ca = c.at(a[i]);
		m[ca] = a[i];
		m2[ca] = 0;
		a[i] = ca;
		int cb = c.at(b[i]);
		m[cb] = b[i];
		m2[cb] = 0;
		b[i] = cb;
	}
	for(int i = 0; i < n; ++i)
		unite(a[i], b[i]);
	for(int i = 1; i <= cnt; ++i) if(i == d[i])
		if(e[i] == s[i]-1)
			ret = std::max(m2[i], ret);
		else if(e[i] == s[i])
			ret = std::max(m[i], ret);
		else
			return puts("-1"), 0;
	printf("%d\n", ret);
	return 0;
}
