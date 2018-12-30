#include <algorithm>
#include <cstdio>
typedef long long lld;
const char * h = "hard";
const lld INFN = 1e18;
const int MAXK = 4;
const int MAXN = 1e5+5;
int a[MAXN];
char buff[MAXN];
lld dp[MAXN][MAXK+1];
int n;

int main() {
	scanf("%d", &n);
	scanf(" %s", buff+1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= MAXK; ++j) {
		dp[i][j] = INFN;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 0; j < MAXK; ++j) {
		if (j && (buff[i] == h[j-1])) {
			// a. match  + increase prefix (keep)
			// b. differ = maintain prefix
			dp[i][j] = std::min(dp[i-1][j-1], dp[i-1][j]);
		} else if (buff[i] == h[j]) {
			// c. match  + maintain prefix (delete)
			dp[i][j] = dp[i-1][j] + a[i];
		} else {
			dp[i][j] = dp[i-1][j];
		}	// b. differ = maintain prefix
	}
	printf("%lld\n", *std::min_element(dp[n], dp[n] + MAXK));
	return 0;
}
