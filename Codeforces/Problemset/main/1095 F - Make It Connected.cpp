#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int MAXN = 2e5+5;
lld	a[MAXN], dsu[MAXN], star[MAXN];
lld best;
int m, n;

struct Edge {
	int x, y;
	lld w;
	bool operator < (const Edge& other) const {
		return w < other.w;
	}
};
std::vector<Edge> edges;

int found(int p) {
	int q = p;
	while (q != dsu[q]) q = dsu[q];
	while (p != dsu[p]) {
		int r = dsu[p];
		dsu[p] = q;
		p = r;
	}
	return p;
}

void unite(const Edge& e) {
	int x = found(e.x);
	int y = found(e.y);
	if (x == y) return;

	if (star[x] > star[y]) std::swap(x, y);
	if (e.w >= star[y]) return;

	best += e.w - star[y];
	dsu[y] = dsu[x];
}

int main() {
	scanf(" %d%d", &n, &m);
	int r = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (a[i] < a[r]) r = i;
	}
	star[r] = 0LL;
	for (int i = 1; i <= n; ++i) if (i != r) {
		star[i] = a[i] + a[r];
	}
	for (int i = 0; i < m; ++i) {
		Edge e;
		scanf(" %d%d%lld", &e.x, &e.y, &e.w);
		if (e.x == r) {
			star[e.y] = std::min(e.w, star[e.y]);
		} else if (e.y == r) {
			star[e.x] = std::min(e.w, star[e.x]);
		} else if (e.w < a[e.x] + a[e.y]) {
			edges.push_back(e);
		}
	}
	best = 0LL;
	for (int i = 1; i <= n; ++i) {
		best += star[i];
	}
	std::sort(ALL(edges));
	std::iota(dsu+1, dsu+n+1, 1);
	for (const auto& e: edges) {
		unite(e);
	}
	printf("%lld\n", best);
	return 0;
}
