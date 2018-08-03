#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <utility>
#define CODE "fighting_the_zombies"
#define x first
#define y second
typedef long long lld;
typedef std::pair<int,int> pii;
const int MAXN = 50;
typedef std::bitset<MAXN> bit;
bit cache[MAXN][MAXN]{ };
pii     Z[MAXN]{ };
int N, R, T;

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d", &N, &R);
		for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			cache[i][j].reset();
		for(int i = 0; i < N; ++i)
			scanf(" %d%d", &Z[i].x, &Z[i].y);
		for(int i = 0; i < N; ++i)
		for(int j = i; j < N; ++j)
		{	// "Destroy" square defined by two zombies
			if(std::abs(Z[i].x-Z[j].x) > R) continue;
			if(std::abs(Z[i].y-Z[j].y) > R) continue;
			pii P = {
				std::min(Z[i].x, Z[j].x),
				std::max(Z[i].y, Z[j].y)
			};
			for(int k = 0; k < N; ++k)
			{	// Included zombies
				if((Z[k].x < P.x) || (P.x+R < Z[k].x)) continue;
				if((Z[k].y > P.y) || (P.y-R > Z[k].y)) continue;
				cache[i][j].set(k);
			}
			if(i != j)
				cache[j][i] = cache[i][j];
		}
		int ret = 0;
		for(int i = 0; i < N; ++i)
		for(int j = i; j < N; ++j)
		for(int k = i; k < N; ++k)
		for(int l = k; l < N; ++l) // Union of squares [i,j] <= [k,l]
			ret = std::max((int)(cache[i][j] | cache[k][l]).count(), ret);
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}
