#include <cstdio>
const int MAXN = 1e6+5;
char buff[MAXN]{ };
bool ge0[MAXN]{ };
bool ge2[MAXN]{ };
bool gn2[MAXN]{ };	// (>= -2)
int sum[MAXN]{ };
int n;

int main() {
	scanf("%d", &n);
	scanf(" %s", buff+1);

	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1];
		if (buff[i] == '(')
			++sum[i];
		else
			--sum[i];
	}
	ge2[n+1] = gn2[n+1] = true;
	for (int i = n; i >= 1; --i) {
		ge2[i] = (ge2[i+1] & (sum[i] >= +2));
		gn2[i] = (gn2[i+1] & (sum[i] >= -2));
	}
	ge0[0] = true;

	int ret = 0;
	for (int i = 1; ge0[i-1] && (i <= n); ++i) {
		ge0[i] = (ge0[i-1] & (sum[i] >= 0));
		if (buff[i] == '(') {
			if (ge2[i] && (sum[n] == +2)) ++ret;
		} else {
			if (gn2[i] && (sum[n] == -2)) ++ret;
		}
	}
	printf("%d\n", ret);
	return 0;
}
