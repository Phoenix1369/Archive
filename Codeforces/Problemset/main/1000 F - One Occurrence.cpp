#include <algorithm>
#include <cstdio>
const int MAXN = 5e5+5;
struct Tri { int l, r, s; } query[MAXN]{ };
int a[MAXN], prv[MAXN], res[MAXN];
int last[MAXN]{ };
int n, q;

struct SegmentTree
{
	int data[MAXN<<2];

	void build()
	{
		build(1, 1, n);
	}

	int get(int i, int j)
	{
		return get(1, 1, n, i, j);
	}

	void set(int i)
	{	// Invalidate Previous Bound
		set(1, 1, n, prv[i], n+1);
	}
private:
	void build(int f, int l, int r)
	{
		if(l == r)
		{
			data[f] = l;
			return;
		}
		int g=f<<1, m=(l+r)>>1;
		build(g  , l  , m);
		build(g|1, m+1, r);
		data[f] = data[g|(prv[data[g|1]] < prv[data[g]])];
	}

	int get(int f, int l, int r, int i, int j)
	{
		if((j < l) || (r < i)) return n+1;
		if((i <= l) && (r <= j))
			return data[f];
		int g=f<<1, m=(l+r)>>1;
		int lft = get(g  , l  , m, i, j);
		int rgt = get(g|1, m+1, r, i, j);
		return (prv[lft] < prv[rgt]) ? lft : rgt;
	}

	void set(int f, int l, int r, int i, int v)
	{
		if((i < l) || (r < i)) return;
		if(l == r)
		{
			data[f] = v;
			return;
		}
		int g=f<<1, m=(l+r)>>1;
		set(g  , l  , m, i, v);
		set(g|1, m+1, r, i, v);
		data[f] = data[g|(prv[data[g|1]] < prv[data[g]])];
	}
} segtr;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		prv[i] = last[a[i]];
		last[a[i]] = i;
	}
	prv[n+1] = n+1;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i)
	{
		scanf(" %d%d", &query[i].l, &query[i].r);
		query[i].s = i;
	}
	std::sort(query, query+q, [](const Tri& lft, const Tri& rgt) {
		return (lft.r != rgt.r) ? (lft.r < rgt.r) : (lft.l < rgt.l);
	});
	segtr.build();
	for(int i=1, j=0; (i <= n) && (j < q); ++i)
	{
		segtr.set(i);
		for(; (j < q) && (query[j].r == i); ++j)
		{
			int pos = segtr.get(query[j].l, i);
			if(prv[pos] < query[j].l)
				res[query[j].s] = a[pos];
			else
				res[query[j].s] = 0;
		}
	}
	for(int i = 0; i < q; ++i)
		printf("%d\n", res[i]);
    return 0;
}