#include <cstdio>
#include <cstring>
#include <utility>
#define MMS(x, y) memset((x), (y), sizeof(x))
#define X first
#define Y second
typedef std::pair<int,int> pii;
const int MAXN = 53;
const pii moves[4] = {	// NESW
	{ 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 }
};
char buff[MAXN][MAXN]{ };
int flood[MAXN][MAXN]{ };
pii queue[MAXN* MAXN]{ };
int visit[MAXN][MAXN]{ };
pii cur, des, nxt, qtr{ }, src;
int M, N;

template <typename T>
inline T& get(T (&A)[MAXN][MAXN], const pii& P) {
	return A[P.Y][P.X];
}

inline bool in_range(const pii& P) {
	return (0 <= P.X) && (P.X < M) && (0 <= P.Y) && (P.Y < N);
}

int bfs(int (&A)[MAXN][MAXN], const bool& flag)
{
	while(qtr.X < qtr.Y)
	{
		cur = queue[qtr.X++];
		for(int k = 0; k < 4; ++k)
		{
			nxt = { cur.X + moves[k].X, cur.Y + moves[k].Y };
			if(!in_range(nxt) || (get(buff, nxt) == 'X') ||
				(get(A, nxt) <= get(A, cur)+1) ) continue;
			A[nxt.Y][nxt.X] = A[cur.Y][cur.X] + 1;
			if( flag && get(buff, nxt) == 'D') return get(A, nxt);
			if(!flag || (A[nxt.Y][nxt.X] < get(flood, nxt)))
				queue[qtr.Y++] = nxt;
		}
	}
	return 0;
}

int main()
{
	scanf(" %d%d", &N, &M);
	MMS(flood, 0x3F), MMS(visit, 0x3F);
	for(int i = 0; i < N; ++i)
	{
		scanf(" %s", buff[i]);
		for(int j = 0; j < M; ++j)
			if(buff[i][j] == '*')
			{
				queue[qtr.Y++] = { j, i };
				flood[i][j] = 0;
			}
			else if(buff[i][j] == 'S')
				src = { j, i };
			else if(buff[i][j] == 'D')
				des = { j, i };
	}
	buff[src.Y][src.X] = '.';
	flood[des.Y][des.X] = -1;
	bfs(flood, 0); // Run Flooding BFS
	flood[des.Y][des.X] = MAXN*MAXN;
	qtr = { };
	queue[qtr.Y++] = src;
	visit[src.Y][src.X] = 0;
	if(bfs(visit, 1)) // Run to Beaver Dam
		printf("%d\n", visit[des.Y][des.X]);
	else
		puts("KAKTUS");
	return 0;
}