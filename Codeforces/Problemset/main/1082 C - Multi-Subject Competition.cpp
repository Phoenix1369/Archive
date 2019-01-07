#include <algorithm>
#include <cstdio>
#include <functional>
#include <unordered_set>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXM = 1e5+5;
std::unordered_set<int> on;
vin c[MAXM];
int m, n, r, s;
int cur, ret;

int main() {
	scanf(" %d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf(" %d%d", &s, &r);
		c[s].push_back(r);
	}
	on.reserve(m);
	for (int i = 1; i <= m; ++i) if (!c[i].empty()) {
		std::sort(ALL(c[i]), std::greater<int>());
		for (int j = 1; j < (int)c[i].size(); ++j) {
			c[i][j] += c[i][j-1];
		}
		on.insert(i);
	}
	cur = ret = 0;
	for (unsigned j = 0; !on.empty(); ++j) {
		for (auto itr = on.begin(); itr != on.end();) {
			if ((j == c[*itr].size()) || (c[*itr][j] < 0)) {
				if (j) cur -= c[*itr][j-1];
				itr = on.erase(itr);
				continue;
			}
			cur += c[*itr][j];
			if (j) cur -= c[*itr][j-1];
			++itr;
		}
		ret = std::max(cur, ret);
	}
	printf("%d\n", ret);
	return 0;
}
