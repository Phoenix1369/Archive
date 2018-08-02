#include <algorithm>
#include <cstdio>
const int MAXT = 1e6+5;
int cnt[MAXT]{ }, qnt[MAXT];
bool seen[MAXT];
int a, t, v=0;

struct Pair { int x, y; } q, Q[MAXT];
const  Pair move[4] = {{0,-1},{+1,0},{0,+1},{-1,0}};

bool verify(int n, int m, int x, int y)
{
	int mh=(m+1)/2, nh=(n+1)/2;
	if((x < 1) || (x > nh) || (y < 1) || (y > mh))
		return false;
	--x, --y;
	for(int i = 0; i <= v; ++i)
		qnt[i] = cnt[i];
	for(int i = 0; i < t; ++i)
		seen[i] = false;
	q={0,0};
	seen[x*m+y] = true;
	Q[q.y++] = {x,y};
	while(q.x < q.y)
	{
		Pair cur = Q[q.x++];
		for(int k = 0; k < 4; ++k)
		{
			Pair nxt = { cur.x+move[k].x, cur.y+move[k].y };
			if((nxt.x < 0) || (nxt.x >= n) || (nxt.y < 0) || (nxt.y >= m))
				continue;
			int c = nxt.x*m+nxt.y;
			if(seen[c])
				continue;
			int d = std::abs(x-nxt.x) + std::abs(y-nxt.y);
			if(--qnt[d] < 0)
				return false;
			seen[c] = true;
			Q[q.y++] = nxt;
		}
	}
	printf("%d %d\n%d %d\n", n, m, ++x, ++y);
	return true;
}

int main()
{
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		scanf("%d", &a);
		v = std::max(a, v);
		++cnt[a];
	}
	int x = 1;
	for(int i = 1; i <= v; ++i)
		if(cnt[i] != i*4)
		{
			x = i;
			break;
		}
	for(int i = 1; i*i <= t; ++i) if((t % i) == 0)
	{
		int j = t / i;
		int y = i+j-v-x;
		if(verify(i, j, x, y) || verify(j, i, x, y))
			return 0;
	}
	puts("-1");
	return 0;
}
