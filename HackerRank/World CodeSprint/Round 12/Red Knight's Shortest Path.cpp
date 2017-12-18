#include <cstdio>
const int MAXN = 205;
const char * ch[6] = { "UL", "UR", "R", "LR", "LL", "L" };
int 	D[MAXN][MAXN]{ }; // Distance
short	S[MAXN][MAXN]{ }; // Step Taken
int qtr[2], N;

struct Pair { int X, Y; } P[MAXN][MAXN], queue[MAXN* MAXN], snk, src;
const  Pair moves[6] = { {-1,-2}, {+1,-2}, {+2,0}, {+1,+2}, {-1,+2}, {-2,0} };

bool in_range(const Pair& p)
{
	return (0 <= p.X) && (p.X < N) && (0 <= p.Y) && (p.Y < N);
}

void traceback(const Pair& cur)
{
	if((cur.X == src.X) && (cur.Y == src.Y)) return;
	traceback(P[cur.Y][cur.X]);
	printf(ch[S[cur.Y][cur.X]]);
	putchar(' ');
}

bool bfs()
{
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < N; ++j)
		D[i][j] = -1;
	qtr[0] = qtr[1] = 0;
	D[src.Y][src.X] = 0;
	queue[qtr[1]++] = src;
	while(qtr[0] < qtr[1])
	{
		Pair cur = queue[qtr[0]++];
		for(int k = 0; k < 6; ++k)
		{
			Pair nxt = { cur.X+moves[k].X, cur.Y+moves[k].Y };
			if(!in_range(nxt) || (D[nxt.Y][nxt.X] != -1)) continue;
			D[nxt.Y][nxt.X] = D[cur.Y][cur.X] + 1;
			P[nxt.Y][nxt.X] = cur;
			S[nxt.Y][nxt.X] = k;
			queue[qtr[1]++] = nxt;
			if((nxt.X == snk.X) && (nxt.Y == snk.Y))
			{
				printf("%d\n", D[snk.Y][snk.X]);
				traceback(snk);
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf(" %d%d%d%d%d", &N, &src.Y, &src.X, &snk.Y, &snk.X);
	if(!bfs()) puts("Impossible");
	return 0;
}