#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
int  flag[MAXN][MAXN]{ };
char grid[MAXN][MAXN]{ };
int   ray[MAXN][MAXN][4]{ }; // NESW
int m, n, ret=0;

void set_rect(int a, int b, int x, int y)
{	// Rectangular update
	++flag[a][b];
	--flag[a][y];
	--flag[x][b];
	++flag[x][y];
}

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf(" %s", grid[i]+1);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if(grid[i][j] == '*')
	{
		ray[i][j][0] = ray[i-1][j][0] + 1; // [N]
		ray[i][j][3] = ray[i][j-1][3] + 1; // [W]
	}
	for(int i = n; i >= 1; --i)
	for(int j = m; j >= 1; --j) if(grid[i][j] == '*')
	{
		ray[i][j][1] = ray[i][j+1][1] + 1; // [E]
		ray[i][j][2] = ray[i+1][j][2] + 1; // [S]
		ray[i][j][0] = std::min(
			std::min(ray[i][j][0], ray[i][j][1]),
			std::min(ray[i][j][2], ray[i][j][3])
		);
		--ray[i][j][0];
	}
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if((grid[i][j] == '*') && ray[i][j][0])
	{	// Greedily place maximal star at each tile
		int k = ray[i][j][0];
		set_rect(i-k, j, i+k+1, j+1);
		set_rect(i, j-k, i+1, j+k+1);
		++ret;
	}
	// Propagate difference array
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j)
		flag[i][j] += flag[i-1][j];
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j)
		flag[i][j] += flag[i][j-1];
	// Solve
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if(grid[i][j] == '*')
		if(!flag[i][j])
			return puts("-1"), 0;
	printf("%d\n", ret);
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= m; ++j) if(ray[i][j][0])
		printf("%d %d %d\n", i, j, ray[i][j][0]);
	return 0;
}
