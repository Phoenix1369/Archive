#include <algorithm>
#include <cstdio>
const int MAXM = 2e4+5;
const int MAXN = 50;
int lot[4][MAXN];
int k, m=0, n;
bool yes;

struct Dir { static const int N=0, E=1, S=2, W=3; };
struct Pair { int x, y; };
const  Pair move[4] = {{0,-1},{+1,0},{0,+1},{-1,0}};
struct Triple { int i, r, c; } out[MAXM];

int& get_lot(const Pair& p) { return lot[p.y][p.x]; }

Pair go(const Pair& f, const int k)
{	// Shift car (g) into blank (f)
	const Pair g = { f.x+move[k].x, f.y+move[k].y };
	if(get_lot(f) || !get_lot(g))
		return g;
	out[m++] = { get_lot(g), f.y+1, f.x+1 };
	std::swap(get_lot(f), get_lot(g));
	yes = true;
	return g;
}

void park(const Pair& cur)
{	// Slide car vertically
	if(!get_lot(cur) || (get_lot(cur) != lot[cur.y^1][cur.x]))
		return;
	Pair s = { cur.x, cur.y^1 };
	get_lot(s) = 0;	// Clear parking spot
	int dir = (cur.y & 1) ? Dir::S : Dir::N;
	go(s, dir);
	get_lot(s) = 0;	// Clear car (swapped in)
}

void advance(Pair& cur, int idx, int dA, int dB)
{
	Pair nxt = go(cur, (idx ? dA : dB));
	park(cur);
	cur = nxt;
}

int tesla()
{	// Trivial clearance
	Pair zero = {-1,-1};
	for(int j = 0; j < n; ++j)
	for(int i = 1; i <= 2; ++i)
	{
		Pair cur = { j, i };
		park(cur);
		if(!lot[i][j] && (zero.x == -1))
			zero = { j, i };
	}
	if(zero.x == -1)
		return -1;
	// Reset to top-left corner
	if(zero.y > 1)
		zero = go(zero, Dir::N);
	while(zero.x > 0)
		zero = go(zero, Dir::W);
	// Conveyor Belt
	Pair cur = zero;
	yes = true;
	while(yes)
	{
		yes = false;
		for(int i = 0; i < 2; ++i)
		{	// Clockwise rotation of SPACE
			for(int j = 1; j < n; ++j)
				advance(cur, i, Dir::W, Dir::E);
			advance(cur, i, Dir::N, Dir::S);
		}
	}
	return m;
}

int main()
{
	scanf(" %d%d", &n, &k);
	for(int i = 0; i < 4; ++i)
	for(int j = 0; j < n; ++j)
		scanf("%d", &lot[i][j]);
	printf("%d\n", tesla());
	for(int i = 0; i < m; ++i)
		printf("%d %d %d\n", out[i].i, out[i].r, out[i].c);
    return 0;
}
