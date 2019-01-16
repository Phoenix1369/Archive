#include <cstdio>
#include <vector>
typedef long long lld;
typedef std::vector<int> vin;
const int INFN = 1e9+7;
const int MAXN = 1e5+5;
vin g[MAXN];
int s[MAXN];
int n, p;
bool yes=true;
lld ret=0LL;

void dfs(int cur, int sum=0) {
	if (!yes) return;
	if (s[cur] == -1) {
		s[cur] = INFN;
		for (auto nxt: g[cur]) {
			s[cur] = std::min(s[nxt], s[cur]);
		}
		if (g[cur].empty()) {
			s[cur] = sum;
		}
	}
	if (sum > s[cur]) {
		yes = false;
		return;
	}
	ret += s[cur] - sum;
	for (auto nxt: g[cur]) {
		dfs(nxt, s[cur]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &p);
		g[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &s[i]);
	}
	dfs(1);
	if (yes) {
		printf("%lld\n", ret);
	} else {
		puts("-1");
	}
	return 0;
}
