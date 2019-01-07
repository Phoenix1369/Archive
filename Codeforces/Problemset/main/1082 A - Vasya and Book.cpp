#include <algorithm>
#include <cmath>
#include <cstdio>
const int MAXP = 2e9;
int d, n, t, x, y;
int T;

int solve() {
	--x; --y;
	int diff = std::abs(x-y);
	if ((diff % d) == 0) {
		return diff / d;
	}
	int res = MAXP;
	if ((y % d) == 0) {
		res = std::min((x+d-1) / d + (y / d), res);
	}
	diff = (n-y-1);
	if ((diff % d) == 0) {
		res = std::min((n-x-1+d-1) / d + (diff / d), res);
	}
	return (res < MAXP) ? res : -1;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf(" %d%d%d%d", &n, &x, &y, &d);
		printf("%d\n", solve());
	}
	return 0;
}
