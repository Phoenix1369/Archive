#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int BASE = 10;
const int MAXR = 1E6+5;
vin	G[BASE];
int   pos[MAXR]{ };
int Q;

int main()
{
	for(int i = 1; i < BASE; ++i)
		G[pos[i] = i].push_back(i);
	for(int i = BASE; i < MAXR; ++i)
	{
		int N=i, P=1;
		for(int N = i; N > 1; N /= BASE)
		{
			int R = (N % BASE);
			if( R) P *= R;
		}
		G[pos[i] = pos[P]].push_back(i);
	}
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		int k, l, r;
		scanf(" %d%d%d", &l, &r, &k);
		printf("%d\n", std::upper_bound(ALL(G[k]), r) - std::lower_bound(ALL(G[k]), l));
	}
	return 0;
}