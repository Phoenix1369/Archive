#include <cstdio>
#include <map>
const int MAXN = 2e5+5;
const int MOD = 998244353;
std::map<int,int> end;
int a[MAXN];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		end[a[i]] = i;
	}
	int pos = 0;
	int ret = 1;
	for (int i = 0; i < n; ++i) {
		pos = std::max(end.at(a[i]), pos);
		if ((pos == i) && (i+1 < n)) {
			ret = 2LL * ret % MOD;
		}	// exclude final segment
	}
	printf("%d\n", ret);
	return 0;
}
