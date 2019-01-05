#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
int cnt[MAXN]{ };	// special v-count
int dsu[MAXN], x[MAXN];
int k, m, n;
int soln;

struct Edge {
	int u, v, w;
	bool operator < (const Edge& other) const {
		return w < other.w;
	}
};
std::vector<Edge> edges;

int found(int a) {
	int b = a;
	while (b != dsu[b]) b = dsu[b];
	while (a != dsu[a]) {
		int tmp = dsu[a];
		dsu[a] = b;
		a = tmp;
	}
	return a;
}

void unite(const Edge& e) {
	int u = dsu[e.u];
	int v = dsu[e.v];
	dsu[u] = dsu[v];
	cnt[v] += cnt[u];
	if (cnt[v] == k) {
		soln = e.w;
	}
}

int main() {
	scanf(" %d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d", &x[i]);
		cnt[x[i]] = 1;
	}
	for (int i = 0; i < m; ++i) {
		Edge e;
		scanf(" %d%d%d", &e.u, &e.v, &e.w);
		edges.push_back(std::move(e));
	}
	// build MST
	std::sort(ALL(edges));
	std::iota(dsu+1, dsu+n+1, 1);
	soln = 0;
	for (const auto& e: edges) {
		if (found(e.u) != found(e.v)) {
			unite(e);
			if (soln) break;
		}	// special vertices connected
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", soln);
	}
	return 0;
}
