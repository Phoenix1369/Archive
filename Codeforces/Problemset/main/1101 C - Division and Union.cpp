#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
int l[MAXN], r[MAXN];
int ans[MAXN], end[MAXN], id[MAXN];
int n, T;

int main() {
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf(" %d%d", &l[i], &r[i]);
			id[i] = i;
		}
		std::sort(id, id+n, [](int a, int b) {
			return (l[a] < l[b]) || ((l[a] == l[b]) && (r[a] < r[b]));
		});
		int res = 0;
		end[res] = r[id[0]];
		for (int i = 0; i < n; ++i) {
			if (end[res] < l[id[i]]) ++res;
			end[res] = std::max(r[id[i]], end[res]);
			ans[id[i]] = res;
		}
		if (res) {
			for (int i = 0; i < n; ++i) {
				printf("%d ", ans[i] ? 1 : 2);
			}
			putchar('\n');
		} else {
			puts("-1");
		}
	}
	return 0;
}
