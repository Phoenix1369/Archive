#include <algorithm>
#include <cstdio>
const int MAXN = 105;
bool flag[MAXN][MAXN]{ };
char grid[MAXN][MAXN]{ };
int   out[MAXN][MAXN]{ };
int m, n, ret=0;

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf(" %s", grid[i]+1);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if(grid[i][j] == '*')
	{
		int d = 1;
		while(	(1 <= i-d) && (i+d <= n) &&
				(1 <= j-d) && (j+d <= m) &&
				(grid[i-d][j] == '*') && (grid[i+d][j] == '*') &&
				(grid[i][j-d] == '*') && (grid[i][j+d] == '*')) ++d;
		if(d == 1) continue;
		// Greedily place maximal star at each tile
		for(int k = 0; k < d; ++k)
			flag[i-k][j] = flag[i+k][j] = flag[i][j-k] = flag[i][j+k] = true;
		out[i][j] = --d;
		++ret;
	}
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if(grid[i][j] == '*')
		if(!flag[i][j])
			return puts("-1"), 0;
	printf("%d\n", ret);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if(out[i][j])
		printf("%d %d %d\n", i, j, out[i][j]);
	return 0;
}
