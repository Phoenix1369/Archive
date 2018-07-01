#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#define MEM(x, y) memset((x), (y), sizeof(x))
#define X first
#define Y second
typedef std::pair<int,int> pii;
const int MAXN = 1E5+5;
int    dp[MAXN][2]{ };
pii array[MAXN]{ };
int N;

int solve(int d, int r, bool s)
{
	if(dp[d][s] != -1)
		return dp[d][s];
	if(d == N-1)
		return 1;
	int t = 0, u = solve(d+1, array[d].X, true);
	if(r < array[d].X - array[d].Y) ++u;
	if(array[d].X + array[d].Y < array[d+1].X)
		t = solve(d+1, array[d].X + array[d].Y, false) + 1;
	return dp[d][s] = std::max(t, u);
}

int main()
{
	scanf("%d", &N);
	MEM(dp, -1);
	for(int i = 0; i < N; ++i)
		scanf(" %d%d", &array[i].X, &array[i].Y);
	printf("%d", solve(1, array[0].X, true)+1);
	return 0;
}