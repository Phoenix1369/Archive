#include <algorithm>
#include <bitset>
#include <cstdio>
#include <utility>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second
typedef std::pair<int,int> pii;
typedef std::vector<pii> vip;
const int MAXC = 30;
std::bitset<MAXC> rec;
int   ptr[MAXC]{ };
vip	S[MAXC]{ };
int   sub[MAXC]{ };
int C, M=0, N, ret=0;
vip tem;

int main()
{
	scanf(" %d%d", &N, &C);
	for(int i = 0; i < N; ++i)
	{
		pii dur; int chan;
		scanf(" %d%d%d", &dur.X, &dur.Y, &chan);
		S[--chan].push_back(dur);
	}
	for(int i = 0; i < C; ++i)
	{	// Merge Adjacent
		tem = S[i];
		S[i].clear();
		std::sort(ALL(tem));
		for(int j = 0; j < (int)tem.size(); ++j)
			if(S[i].empty() || (S[i].back().Y < tem[j].X))
				S[i].push_back(tem[j]);
			else
				S[i].back().Y = tem[j].Y;
		if(!S[i].empty())
			M = std::max(S[i].back().Y, M);
	}
	for(int t = 1; t <= M; ++t)
	{	// Maximum Bottleneck
		for(int i = 0; i < MAXC; ++i)
			if((ptr[i] < (int)S[i].size()) && (t == S[i][ptr[i]].X))
				rec.set(i);
		ret = std::max(rec.count(), (std::size_t)ret);
		for(int i = 0; i < MAXC; ++i)
			if((ptr[i] < (int)S[i].size()) && (t == S[i][ptr[i]].Y))
			{
				rec.reset(i);
				++ptr[i];
			}
	}
	printf("%d\n", ret);
	return 0;
}
