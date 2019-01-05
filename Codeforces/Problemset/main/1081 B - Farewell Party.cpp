#include <cstdio>
const int MAXN = 1e5+5;
int a[MAXN], b[MAXN]{ }, c[MAXN]{ };
int n;

void solve() {
	for (int i = 1; i <= n; ++i) {
		if (c[i] % i) {
			puts("Impossible");
			return;
		}
	}
	int cnt = 0;
	puts("Possible");
	for (int i = 0; i < n; ++i) {
		if ((c[a[i]] % a[i]) == 0) {
			b[a[i]] = ++cnt;
		}
		printf("%d ", b[a[i]]);
		--c[a[i]];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] = n-a[i];
		++c[a[i]];
	}
	solve();
	return 0;
}
