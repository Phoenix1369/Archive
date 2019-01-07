#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1e5+5;
char s[MAXN];
int cnt, gold;
int n;
vin seg;

void flush(int i) {
	if ((seg.size() & 1) == 0) {
		gold += cnt;
	}
	seg.push_back(cnt);
	cnt = 0;
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	if (s[0] != 'G') {
		seg.push_back(0);
	}
	cnt = gold = 0;
	for (int i = 0; i < n; ++i) {
		if (i && (s[i] != s[i-1])) {
			flush(i);
		}
		++cnt;
	}
	flush(n);
	if ((seg.size() & 1) == 0) {
		seg.push_back(0);
	}
	int len = seg.size();
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		if (i & 1) {
			if (seg[i] == 1) {
				int au = seg[i-1] + seg[i+1];
				ret = std::max(au + (au < gold), ret);
			}
		} else {
			ret = std::max(seg[i] + (seg[i] < gold), ret);
		}
	}
	printf("%d\n", ret);
	return 0;
}
