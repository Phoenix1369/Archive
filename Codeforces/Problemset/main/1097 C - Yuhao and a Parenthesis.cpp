#include <cstdio>
#include <cstring>
#include <map>
const int MAXC = 5e5+5;
std::map<int,int> cnt[3];
char s[MAXC];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", s);
		int len = strlen(s);
		int lvl[2]{ };
		bool bad = false;
		for (int j = 0; j < len; ++j) {
			(s[j] == '(') ? ++lvl[0] : --lvl[0];
			if (lvl[0] < 0) bad = true;
		}
		bool dab = false;
		for (int j = len-1; j >= 0; --j) {
			(s[j] == '(') ? ++lvl[1] : --lvl[1];
			if (lvl[1] > 0) dab = true;
		}
		if (bad && dab) continue;
		if (bad) {
			++cnt[1][lvl[0]];
		} else if (lvl[0]) {
			++cnt[0][lvl[0]];
		} else {
			++cnt[2][0];
		}
	}
	int ret = cnt[2][0] / 2;
	for (auto itr: cnt[0]) {
		int key = -itr.first;
		if (cnt[1].count(key)) {
			ret += std::min(cnt[1].at(key), itr.second);
		}
	}
	printf("%d\n", ret);
	return 0;
}
