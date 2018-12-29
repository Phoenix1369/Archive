#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
#define FIND(x, y) (std::find(ALL(x), y) != (x).end())
typedef std::vector<int> vin;
const int MAXN = 2e5+5;
vin graph[MAXN]{ };
bool seen[MAXN]{ };
int n;

void dfs(int cur) {
	if (seen[cur]) return;
	seen[cur] = true;
	printf("%d ", cur);
	if (FIND(graph[graph[cur][0]], graph[cur][1])) {
		dfs(graph[cur][0]);
	} else {
		dfs(graph[cur][1]);
	}
}

int main() {
	scanf("%d", &n);
	if (n == 3) {
		puts("1 2 3");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		int u, v;
		scanf(" %d%d", &u, &v);
		graph[i].push_back(u);
		graph[i].push_back(v);
	}
	dfs(1);
	putchar('\n');
	return 0;
}
