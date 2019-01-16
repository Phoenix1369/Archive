#include <cstdio>
int n;

int main() {
	scanf("%d", &n);
	printf("%lld\n", (1LL*n*(n+1)/2) & 1);
	return 0;
}
