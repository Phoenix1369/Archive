#include <algorithm>
#include <cstdio>
int bx, by, n, x, y;
char c;

int main() {
	scanf("%d", &n);
	bx = by = 0;
	for (int i = 0; i < n; ++i) {
		scanf(" %c%d%d", &c, &x, &y);
		if (x > y) std::swap(x, y);
		switch (c) {
		case '+':
			bx = std::max(x, bx);
			by = std::max(y, by);
			break;
		case '?':
			puts(((bx <= x) && (by <= y)) ? "YES" : "NO");
			break;
		}
	}
	return 0;
}
