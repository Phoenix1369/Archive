#include <cstdio>
int d, l, q, r;

int main() {
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf(" %d%d%d", &l, &r, &d);
		printf("%d\n", (d < l) ? d : (((r / d) + 1) * d));
	}
	return 0;
}
