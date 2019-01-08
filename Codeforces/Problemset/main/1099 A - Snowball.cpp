#include <algorithm>
#include <cstdio>
const int MAXH = 105;
int rock[MAXH]{ };
int d, h, u, w;

int main() {
	scanf(" %d%d", &w, &h);
	for (int i = 0; i < 2; ++i) {
		scanf(" %d%d", &u, &d);
		rock[d] = u;
	}
	for (int i = h; i >= 1; --i) {
		w += i;
		w -= std::min(rock[i], w);
	}
	printf("%d\n", w);
	return 0;
}
