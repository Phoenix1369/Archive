#include <cstdio>
#include <unordered_set>
const int MAXN = 5005;
int a[MAXN];
int b[MAXN]{ };
int cnt[MAXN]{ };
int k, n;

int main() {
	// |maximum_count| <= k
	scanf(" %d%d", &n, &k);
	int maxc = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		++cnt[a[i]];
		b[a[i]] = -1;
		if (cnt[a[i]] >= cnt[maxc]) {
			maxc = a[i];
		}
	}
	if (cnt[maxc] > k) {
		puts("NO");
		return 0;
	}
	int pos = 0;
	puts("YES");
	for (int i = 0; i < n; ++i) if (b[a[i]] == -1) {
		b[a[i]] = pos;
		pos = (pos + cnt[a[i]]) % k;
	}
	for (int i = 0; i < n; ++i) {
		++b[a[i]];
		printf("%d ", b[a[i]]);
		b[a[i]] %= k;
	}
	putchar('\n');
	return 0;
}
