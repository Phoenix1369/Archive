#include <algorithm>
#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 2E5+5;
int color[MAXN]{ };
vin graph[MAXN]{ };
int K=0, N;

void dfs(int cur, int prv)
{
	int C = 1;
	K = std::max(color[cur], K);
	for(auto nxt: graph[cur]) if(!color[nxt])
	{
		while((C == color[prv]) || (C == color[cur])) C++;
		color[nxt] = C++;
		dfs(nxt, cur);
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i < N; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	color[1] = 1;
	dfs(1, 1);
	printf("%d\n", K);
	for(int i = 1; i <= N; ++i)
		printf("%d%c", color[i], (i==N)?'\n':' ');
	return 0;
}