#include <algorithm>
#include <cstdio>
#include <numeric>
const int MAXN = 1e6+5;
const int MOD = 998244353;
int f[MAXN];
int p[MAXN];
int n;

void bf() {
	int K = 4;
	std::iota(p, p+K, 1);
	do {
		for (int i = 0; i < K; ++i) {
			printf("%d ", p[i]);
		}
		putchar('\n');
	} while (std::next_permutation(p, p+K));
}

int solve() {
	if (n <= 2) return n;
	// bf();
	// g(4) = 56
	// |pre| * ((n-|pre|)! - 1) * n
	// + n*n! - n + 1
	// * (n-1) * (n-2) * (n-3) * ... * 2
	// n = 4
	// lcp(0) = n! = 24
	// lcp(1) = n * ((n-1)! - 1) = n! - n = 20
	// lcp(2) = n * (n-1) * ((n-2)! - 1) = n! - n*(n-1) = 12
	// ...
	// lcp(n-2) = ...
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i] = 1LL * f[i-1] * i % MOD;
	}
	int ret = 1LL * f[n] * (n-1) % MOD;
	int mul = n;
	int nsub2 = n-2;
	for (int i = 1; i <= nsub2; ++i) {
		ret = (1LL * ret - mul + MOD) % MOD;
		mul = 1LL * mul * (n - i) % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	printf("%d\n", solve());
	return 0;
}
