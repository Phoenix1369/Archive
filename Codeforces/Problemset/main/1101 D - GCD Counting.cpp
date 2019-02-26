#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXN = 2e5+5;
int a[MAXN];
int  dist[MAXN]{ };
vin G[MAXN], pfs[MAXN], subtr[MAXN];
// graph, prime factors, subtree
int n, root;
vin V;

void init() {
	for (int i = 2; i < MAXN; ++i) if (pfs[i].empty()) {
		for (int j = i; j < MAXN; j += i) {
			pfs[j].push_back(i);
		}
	}
}

void dfs(int cur, int p) {
	V.push_back(cur);
	for (auto nxt: G[cur]) {
		if (dist[nxt] || (a[nxt] % p)) continue;
		dist[nxt] = dist[cur] + 1;
		dfs(nxt, p);
	}
	if (dist[cur] > dist[root]) {
		root = cur;
	}
}

void run(int p) {
	for (auto v: V) {
		dist[v] = 0;
	}
	V.clear();
	dist[root] = 1;
	dfs(root, p);
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (auto p: pfs[a[i]]) {
			subtr[p].push_back(i);
		}
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf(" %d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ret = 0;
	for (int p = 2; p < MAXN; ++p) {
		for (auto i: subtr[p]) if (!dist[i]) {
			root = i;
			run(p);
			run(p);	// twice
			V.clear();
			ret = std::max(dist[root], ret);
		}
		for (auto i: subtr[p]) {
			dist[i] = 0;
		}
	}
	printf("%d\n", ret);
	return 0;
}
