#include <cstdio>
int a, n, x, y;

int solve() {
	if (x > y) return n;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (a <= x) c++; // Language
	}
	return (c+1) / 2;
}

int main() {
	scanf(" %d%d%d", &n, &x, &y);
	printf("%d\n", solve());
	return 0;
}
