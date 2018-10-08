#include <algorithm>
#include <cstdio>
int x[3], y[3];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) {
		scanf(" %d%d", &x[i], &y[i]);
	}
	if (x[1] > x[2]) std::swap(x[1], x[2]);
	if (y[1] > y[2]) std::swap(y[1], y[2]);
	if (((x[1] < x[0]) && (x[0] < x[2])) ||
		((y[1] < y[0]) && (y[0] < y[2])) )
		puts("NO");
	else
		puts("YES");
	return 0;
}
