#include <cstdio>
#include <queue>
#include <utility>
#define X first
#define Y second
typedef std::pair<int,int> pii;
const int MAXN = 505;
const pii moves[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
char grid[MAXN][MAXN]{ };
bool seen[MAXN][MAXN]{ };
pii snk, src;
int M, N;
char C;

bool in_range(pii P)
{
	return (1 <= P.X) && (P.X <= M) && (1 <= P.Y) && (P.Y <= N);
}

bool dfs()
{
	std::queue<pii> queue;
	queue.push(src);
	seen[src.Y][src.X] = true;
	while(!queue.empty())
	{
		pii cur = queue.front();
		queue.pop();
		for(int k = 0; k < 4; ++k)
		{
			pii nxt = { cur.X + moves[k].X, cur.Y + moves[k].Y };
			if(!in_range(nxt)) continue;
			if((grid[nxt.Y][nxt.X] == '.') && !seen[nxt.Y][nxt.X])
			{
				queue.push(nxt);
				seen[nxt.Y][nxt.X] = true;
			}
			else if(nxt == snk)
				return true;
		}
	}
	return false;
}

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
		scanf(" %s", grid[i]+1);
	scanf(" %d%d%d%d", &src.Y, &src.X, &snk.Y, &snk.X);
	int fresh = 0;
	for(int i = snk.Y-1; i <= snk.Y+1; ++i)
	for(int j = snk.X-1; j <= snk.X+1; ++j)
	{
		pii tem = { j, i };
		if((tem == snk) || !in_range(tem)) continue;
		if((grid[i][j] == '.') ^ (src == tem)) ++fresh;
	}
	bool yes = dfs() && ((grid[snk.Y][snk.X] == '.') ? (fresh >= 2) : (fresh >= 1));
	puts(yes ? "YES" : "NO");
	return 0;
}
