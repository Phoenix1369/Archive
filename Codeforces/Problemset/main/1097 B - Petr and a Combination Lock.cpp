#include <cstdio>
const int MAXN = 20;
int a[MAXN];
int n;

bool solve() {
	int L = 1<<n;
	for (int mask = 0; mask < L; ++mask) {
		int ptr = 0;
		for (int bit = 0; bit < n; ++bit) {
			if ((mask >> bit) & 1) {
				ptr += a[bit];
			} else {
				ptr -= a[bit];
			}
		}
		if ((ptr % 360) == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	puts(solve() ? "YES" : "NO");
	return 0;
}
