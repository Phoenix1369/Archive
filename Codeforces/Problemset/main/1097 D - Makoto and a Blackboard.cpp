#include <algorithm>
#include <cmath>
#include <cstdio>
typedef long long lld;
const int LOGN = 51;
const int MOD = 1e9+7;
int dp[2][LOGN], inv[LOGN];
lld n;
int k;

int fpm(int b, int e) {
	int p = 1;
	while (e) {
		if (e & 1) {
			p = 1LL*p*b % MOD;
		}
		b = 1LL*b*b % MOD;
		e >>= 1;
	}
	return p;
}

void init() {
	inv[1] = 1;
	for (int i = 2; i < LOGN; ++i) {
		inv[i] = fpm(i, MOD-2);
	}
}

int solve(lld p, int a) {
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < LOGN; ++j) {
		dp[i][j] = 0;
	}
	dp[0][a] = 1;
	for (int h = 1; h <= k; ++h) {
		int i = (h & 1);
		for (int j = a; j >= 0; --j) {
			dp[i][j] = 1LL * inv[j+1] * dp[i^1][j] % MOD;
			if (j < a) {
				dp[i][j] = (1LL*dp[i][j] + dp[i][j+1]) % MOD;
			}
		}
	}
	int prod=1, ret=0;
	for (int j = 0; j <= a; ++j) {
		ret = (1LL * dp[k&1][j] * prod % MOD + ret) % MOD;
		prod = 1LL * prod * p % MOD;
	}
	return ret;
}

int main() {
	scanf(" %lld%d", &n, &k);
	int s = sqrt(n);
	int ret = 1;
	init();
	for (int i = 2; i <= s; ++i) if ((n % i) == 0) {
		int a;
		for (a = 0; !(n % i); ++a) n /= i;
		ret = 1LL * ret * solve(i, a) % MOD;
	}
	if (n > 1) {
		ret = 1LL * ret * solve(n, 1) % MOD;
	}
	printf("%d\n", ret);
	return 0;
}
