#include <cstdio>
#define CODE "let_it_flow"
const int MAXN = 1005;
const int MOD = 1e9+7;
char grid[3][MAXN]{ };
int N, T;

bool bad(int i, int j) { return grid[i][j] == '#'; }
bool eyy(int i, int j) { return grid[i][j] == '.'; }

int flow()
{
	if((N & 1) || bad(0,0) || bad(1,0) || bad(1,N-1) || bad(2,N-1))
		return 0;
	if(N == 2)
		return 1;
	int last=N-1, ret=1;
	for(int j = 1; j < last; j += 2)
	{
		if(bad(1,j) || bad(1,j+1) ||
			((bad(0,j) || bad(0,j+1)) && (bad(2,j) || bad(2,j+1))))
			return 0;
		if(eyy(0,j) && eyy(0,j+1) && eyy(2,j) && eyy(2,j+1))
			ret = 2LL*ret % MOD;
	}
	return ret;
}

int main()
{
	// freopen(CODE "_sample_input.txt", "r", stdin);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);
		for(int i = 0; i < 3; ++i)
			scanf(" %s", grid[i]);
		printf("Case #%d: %d\n", t, flow());
	}
    return 0;
}
