#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 505;
int a[MAXN];
vin v[2];
int n;

template <typename A> int csize(A c) { return c.size(); }

int main() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] >= 2) {
			v[0].push_back(i);
			cnt += a[i];
		} else {
			v[1].push_back(i);
		}	// (a == 1)
	}
	int chain = 2*(csize(v[0]) - 1);
	if (csize(v[1]) > cnt-chain) {
		puts("NO");
		return 0;
	}	// Too many leaves
	int d = csize(v[0]) - 1 + std::min(csize(v[1]), 2);
	int e = csize(v[0]) - 1 + csize(v[1]);
	printf("YES %d\n%d\n", d, e);
	for (int i = 1; i < csize(v[0]); ++i) {
		printf("%d %d\n", v[0][i-1], v[0][i]);
	}
	if (v[1].empty()) {
		return 0;
	}
	if (csize(v[0]) >= 2) {
		--a[v[0].front()];
		--a[v[0].back()];
	}
	for (int i = 1; i+1 < csize(v[0]); ++i) {
		a[v[0][i]] -= 2;
	}
	int j = 0;
	printf("%d %d\n", v[1].front(), v[0].back());
	--a[v[0].back()];
	for (int i = 1; i < csize(v[1]); ++i) {
		while ((j < csize(v[0])) && !a[v[0][j]]) ++j;
		printf("%d %d\n", v[1][i], v[0][j]);
		--a[v[0][j]];
	}
	return 0;
}
