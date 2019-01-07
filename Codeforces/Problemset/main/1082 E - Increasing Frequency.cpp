#include <algorithm>
#include <cstdio>
const int MAXN = 5e5+5;
int lazy[MAXN]{ }, memo[MAXN]{ };
int a, c, n;
int cnt, diff;

int main() {
	scanf(" %d%d", &n, &c);
	cnt = diff = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		if (a == c) {
			++cnt;
		} else {
			lazy[a] -= cnt - memo[a];
			lazy[a] = std::max(0, lazy[a]);
			++lazy[a];
			memo[a] = cnt;
		}	// Kadane's algorithm (parallel)
		diff = std::max(lazy[a], diff);
	}
	printf("%d\n", cnt + diff);
	return 0;
}
