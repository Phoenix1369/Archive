#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>
const int D = 4;
const int MAXC = 105;
char buff[MAXC]{ };
char grid[MAXC][MAXC]{ };
int dir[D], L, M, N;

struct Pair { int X, Y; } pos[2], src;
const Pair moves[D] = { {0,-1}, {+1,0}, {0,+1}, {-1,0} };

bool in_range(const Pair& T)
{
	return (1 <= T.X) && (T.X <= M) && (1 <= T.Y) && (T.Y <= N);
}

bool bfs()
{
	pos[1] = src;
	for(int i = 0; i < L; ++i)
	{
		int k = (i & 1);
		Pair del = moves[dir[buff[i]-'0']];
		pos[k] = { pos[k^1].X+del.X, pos[k^1].Y+del.Y };
		if(!in_range(pos[k]) || (grid[pos[k].Y][pos[k].X] == '#'))
			break;
		if(grid[pos[k].Y][pos[k].X] == 'E')
			return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
		scanf(" %s", grid[i]+1);
	scanf(" %s", buff);
	L = strlen(buff);
	for(int i = 1; i <= N; ++i)
	for(int j = 1; j <= M; ++j)
		if(grid[i][j] == 'S')
			src = { j, i };
	int ret = 0;
	std::iota(dir, dir+D, 0);
	do {
		if(bfs()) ++ret;
	} while(std::next_permutation(dir, dir+D));
	printf("%d\n", ret);
	return 0;
}