#include <algorithm>
#include <cstdio>
#include <functional>
#include <unordered_map>
typedef long long lld;
const int MAXN = 5e5+5;
int a[MAXN], c[MAXN], d[MAXN];
bool parity;
int n;

int erdos_gallai(int x) {
	//	https://en.wikipedia.org/wiki/Erdos-Gallai_theorem
	int j, pos;
	for (j = 1; (j <= n) && (a[j] > x); ++j) d[j] = a[j];
	d[j] = x;
	for (pos = j; j <= n; ++j) d[j+1] = a[j];

	int N = n+1;
	lld lhs=0, rhs=0;
	bool yes = false;
	for (int i = 0; i <= N; ++i) {
		c[i] = 0;
	}
	for (int i = 1; i <= N; ++i) {
		if (d[i] <= N) ++c[d[i]];
	}
	int cnt = N - c[0];
	for (int k = 1; k <= N; ++k) {
		lhs += d[k];
		rhs += 1LL*k*(k-1);
		rhs += cnt;
		rhs -= std::min(d[k], k);
		if (lhs > rhs) {
			return (pos <= k) ? +1 : -1;
		}	// a[n+1] too ? large : small
		cnt -= c[k];
		if ((k < d[k]) && (d[k] <= N)) {
			--c[d[k]];
			--cnt;
		}
		rhs -= 1LL*k*(k-1);
	}
	return 0;
}

int bisect(bool head) {
	// Binary search on parity
	int lo = (parity);
	int hi = n+2;
	while (lo < hi) {
		int x = (lo+hi) / 2;
		if ((x & 1) != parity) {
			--x;
		}
		if (head) {
			if (erdos_gallai(x) >= 0) {
				hi = x;
			} else {
				lo = x+2;
			}
		} else {
			if (erdos_gallai(x) <= 0) {
				lo = x+2;
			} else {
				hi = x;
			}
		}
	}
	return lo;
}

int main() {
	scanf("%d", &n);
	lld handshake = 0LL;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		handshake += a[i];
	}
	std::sort(a+1, a+n+1, std::greater<int>())s;
	parity = (handshake & 1);
	int lo = bisect(true);
	int hi = bisect(false);
	if (lo < hi) {
		for (int i = lo; i < hi; i += 2) {
			printf("%d ", i);
		}
		putchar('\n');
	} else {
		puts("-1");
	}
	return 0;
}
