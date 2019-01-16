#include <algorithm>
#include <cstdio>
#include <string>
#define ALL(x) (x).begin(), (x).end()
typedef std::string str;
const int MAXC = 4;
const int MAXN = 3e5+5;
const char * acgt = "ACGT";
char buff[MAXN];
str ans[MAXN], s[MAXN];
int m, n;
str dyn;

int best;
str ret;
bool cr;

void augment(int sum, bool flag) {
	if (sum >= best) return;
	best = sum;
	ret = dyn;
	cr = flag;
}

void format(int a, int end, bool second, int row) {
	for (int b = 0; b < end; ++b) {
		ans[(row < 0) ? b : row] += dyn[(a&1)*2 + ((b&1)^second)];
	}
}

void solve_cols(bool out) {
	int sum = 0;
	for (int j = 0; j < m; ++j) {
		int cnt[2]{ };
		for (int i = 0; i < n; ++i) {
			if (s[i][j] != dyn[(j&1)*2 + (i&1)]) ++cnt[0];
			if (s[i][j] != dyn[(j&1)*2 + ((i&1)^1)]) ++cnt[1];
		}
		sum += std::min(cnt[0], cnt[1]);
		if (out) format(j, n, (cnt[1] <= cnt[0]), -1);
	}
	augment(sum, true);
}

void solve_rows(bool out) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int cnt[2]{ };
		for (int j = 0; j < m; ++j) {
			if (s[i][j] != dyn[(i&1)*2 + (j&1)]) ++cnt[0];
			if (s[i][j] != dyn[(i&1)*2 + ((j&1)^1)]) ++cnt[1];
		}
		sum += std::min(cnt[0], cnt[1]);
		if (out) format(i, m, (cnt[1] <= cnt[0]), i);
	}
	augment(sum, false);
}

int main() {
	scanf(" %d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", buff);
		s[i] = buff;
	}
	best = m * n;
	dyn = ret = acgt;
	cr = false;
	do {
		solve_cols(false);
		solve_rows(false);
	} while (std::next_permutation(ALL(dyn)));
	dyn = ret;	// Only read from [dyn]amic permutation
	if (cr) {
		solve_cols(true);
	} else {
		solve_rows(true);
	}
	for (int i = 0; i < n; ++i) {
		puts(ans[i].c_str());
	}
	return 0;
}
