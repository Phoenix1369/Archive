#include <algorithm>
#include <cstdio>
const int LOGN = 30;
int cnt[LOGN]{ };
int b, k, n;

int main() {
	scanf(" %d%d", &n, &k);
	int b = __builtin_popcount(n);

	if ((n < k) || (k < b)) {
		puts("NO");
		return 0;
	}

	int msb = 0;
	for (int i=0, j=1; i < LOGN; ++i, j <<= 1) {
		if (n & j) {
			++cnt[i];
			msb = i;
		}
	}
	for (int i = msb; (i > 0) && (b < k); --i) {
		int d = std::min(k-b, cnt[i]);
		cnt[i-1] += d*2;
		cnt[i] -= d;
		b += d;
	}
	puts("YES");
	for (int i = 0; i < LOGN; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			printf("%d ", (1 << i));
		}
	}
	putchar('\n');
	return 0;
}
