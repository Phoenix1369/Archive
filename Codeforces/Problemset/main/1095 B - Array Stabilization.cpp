#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
int a[MAXN]{ };
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a+n);
	printf("%d\n", std::min(a[n-1]-a[1], a[n-2]-a[0]));
	return 0;
}
