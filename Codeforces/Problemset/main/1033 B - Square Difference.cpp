#include <cmath>
#include <cstdio>
typedef long long lld;
lld a, b;
int T;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf(" %lld%lld", &a, &b);
		if ((a-b) > 1LL) {
			puts("NO");
			continue;
		}
		lld m = a+b;
		int s = sqrt(m);
		bool p = true;
		for (int i = 2; i <= s; ++i) {
			if ((m % i) == 0) {
				p = false;
				break;
			}
		}
		puts(p ? "YES" : "NO");
	}
	return 0;
}
