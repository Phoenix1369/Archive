#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#define MMS(x, y) memset((x), (y), sizeof(x))
typedef long long lld;
const int MAXN = 2017;
int	K[MAXN]{ };
std::deque<int> S[2];
int cnt[2][2]{ };
int M, N, T;

struct Point { int X, Y, ink; } P[MAXN];

void transfer(int pos)
{	// Transfers Point from [cur^1] -> [cur]
	++cnt[pos  ][P[S[pos^1].front()].ink];
	--cnt[pos^1][P[S[pos^1].front()].ink];
	S[pos  ].push_back(S[pos^1].front());
	S[pos^1].pop_front();
}

void radial_sweep(int cur, const int& i)
{	// 0->cur, 1 -> cur^1
	while(!S[cur^1].empty())
	{	// Rotate Line about P[i]
		lld cross =	1LL * (P[S[cur].front()].X - P[i].X) * (P[S[cur^1].front()].Y - P[i].Y) -
				1LL * (P[S[cur].front()].Y - P[i].Y) * (P[S[cur^1].front()].X - P[i].X);
		if( cross < 0LL) break;
		transfer(cur);
	}
	transfer(cur^1);
}

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf(" %d%d", &N, &M);
		int ret = (M += N);
		for(int i = 0; i < M; ++i)
		{
			scanf(" %d%d", &P[i].X, &P[i].Y);
			P[i].ink = !!(i >= N);
		}
		for(int i = 0; i < M; ++i)
		{	// Radial Line Sweep
			for(int j = 0; j < M-1; ++j)
				K[j] = j + (j >= i);
			std::sort(K, K+M-1, [&](const int& l, const int& r)
			{	// Counter-clockwise, from East (3
				if((P[l].Y - P[i].Y >= 0) && (P[r].Y - P[i].Y < 0))
					return true;
				if((P[l].Y - P[i].Y < 0) && (P[r].Y - P[i].Y >= 0))
					return false;
				// Right-hand Rule: [l,r] on the same side of the line
				lld cross =	1LL * (P[l].X - P[i].X) * (P[r].Y - P[i].Y) -
						1LL * (P[l].Y - P[i].Y) * (P[r].X - P[i].X);
				return (cross > 0LL);
			});
			// S[0,1] = points above,below P[i]
			S[0].clear();
			S[1].clear();
			MMS(cnt, 0);
			++cnt[0][P[i].ink];
			for(int j = 0; j < M-1; ++j)
			{
				bool dex = (P[K[j]].Y < P[i].Y);
				++cnt[dex][P[K[j]].ink];
				S[dex].push_back(K[j]);
			}
			// Break Condition: Tracks S[0] over S[1]
			int beg = S[0].empty();
			int src = S[beg].front();
			do {	// Try to place P[i] on either side of the line
				int one = std::min(cnt[0][0]+cnt[1][1], cnt[0][1]+cnt[1][0]);
				--cnt[0][P[i].ink], ++cnt[1][P[i].ink];
				int two = std::min(cnt[0][0]+cnt[1][1], cnt[0][1]+cnt[1][0]);
				ret = std::min(ret, std::min(one, two));
				++cnt[0][P[i].ink], --cnt[1][P[i].ink];
				// Sweeps on S[0] if possible else S[1]
				radial_sweep(S[0].empty(), i);
			} while(S[beg].empty() || (S[beg].front() != src));
		}
		printf("%d\n", ret);
	}
	return 0;
}