#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1E4+5;
int	C[MAXN]{ };
vin graph[MAXN]{ };
int N, ret=0, u;

void dfs(int cur, int col)
{
	if(C[cur] !=  col) ++ret;
	for(auto nxt: graph[cur])
		dfs(nxt, C[cur]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 2; i <= N; ++i)
	{
		scanf("%d", &u);
		graph[u].push_back(i);
	}
	for(int i = 1; i <= N; ++i)
		scanf("%d", &C[i]);
	dfs(1, 0);
	printf("%d\n", ret);
	return 0;
}