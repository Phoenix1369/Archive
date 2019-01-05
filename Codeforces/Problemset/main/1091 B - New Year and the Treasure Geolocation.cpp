#include <cstdio>
typedef long long lld;
lld X=0, Y=0;
int n, x, y;

int main() {
	scanf("%d", &n);
	for (int j = 0; j < 2; ++j)
	for (int i = 0; i < n; ++i) {
		scanf(" %d%d", &x, &y);
		X += x;
		Y += y;
	}
	printf("%lld %lld\n", X / n, Y / n);
	return 0;
}
