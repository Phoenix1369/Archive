#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef std::pair<lld,lld> pii;
typedef std::vector<pii> vip;
const int MAXN = 1e5+5;
const int MAXS = 2e5+1;
vip memo[MAXS];
lld x[MAXN];
int n;

bool solve() {
	// init
	for (int a = 1; a < MAXS; ++a) {
		for (int b = a+1, d; (d = (1LL*b*b - 1LL*a*a)) < MAXS; ++b) {
			memo[d].emplace_back(1LL*a*a, 1LL*b*b);
		}
	}
	// exec
	lld sum = 0LL;
	for (int i = 1; i < n; i += 2) {
		auto ptr = std::upper_bound(ALL(memo[x[i]]), pii{sum,MAXS});
		if (ptr == memo[x[i]].end()) {
			return false;
		}
		x[i-1] = ptr->first - sum;
		sum = ptr->second;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i += 2) {
		scanf("%lld", &x[i]);
	}
	if (solve()) {
		puts("Yes");
		for (int i = 0; i < n; ++i) {
			printf("%lld%c", x[i], (i==n-1) ? '\n' : ' ');
		}
	} else {
		puts("No");
	}
	return 0;
}
