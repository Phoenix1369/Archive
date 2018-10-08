#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1e5+5;
int a[MAXN];
vin g[MAXN];
int ret[MAXN][2]; // Alice, Bob
int n;

int dfs(int cur, int p) {
	if (ret[cur][p] != -1) {
		return ret[cur][p];
	}
	int res = 0;
	for (int nxt: g[cur]) {
		res |= !dfs(nxt, p^1);
	}
	return ret[cur][p] = res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int m = a[i];
		for (int j = i+m; j <= n; j += m) {
			if (a[j] > m) {
				g[m].push_back(a[j]);
			}
		}
		for (int j = i-m; j >= 1; j -= m) {
			if (a[j] > m) {
				g[m].push_back(a[j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		ret[i][0] = ret[i][1] = (g[i].empty() ? 0 : -1);
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i, 0);
	}
	for (int i = 1; i <= n; ++i) {
		putchar('A' + (ret[a[i]][0] ^ 1));
	}
	return 0;
}
