#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXN = 5E4+5;
bool	A[MAXN]{ };
int  best[MAXN][2]{ }; // best[i][j]: Visit zoo[i], carry type[j]
int	S[MAXN]{ };
vin D[MAXN][2]{ };
int d, M, N, T;
char C;

struct SegmentTree
{
	int data[MAXN<<2]{ };
	int lazy[MAXN<<2]{ };

	void point(int f, int l, int r, int i, int v)
	{
		int g=f<<1, m=(l+r)>>1;
		propagation(f, g, l, r);
		if((r < i) || (i < l))	return;
		if(l == r) { data[f]=v;	return; }
		point(g  , l  , m, i, v);
		point(g|1, m+1, r, i, v);
		data[f] = std::max(data[g], data[g|1]);
	}

	int  query(int f, int l, int r, int x, int y)
	{
		int g=f<<1, m=(l+r)>>1;
		propagation(f, g, l, r);
		if((x <= l) && (r <= y))
			return data[f];
		if((r < x) || (y < l)) return 0;
		return std::max(
			query(g  , l  , m, x, y),
			query(g|1, m+1, r, x, y)
		);
	}

	void range(int f, int l, int r, int x, int y)
	{
		int g=f<<1, m=(l+r)>>1;
		propagation(f, g, l, r);
		if((x <= l) && (r <= y))
		{
			++lazy[f];
			propagation(f, g, l, r);
			return;
		}
		if((r < x) || (y < l)) return;
		range(g  , l  , m, x, y);
		range(g|1, m+1, r, x, y);
		data[f] = std::max(data[g], data[g|1]);
	}

	void reset(int f, int l, int r)
	{
		data[f] = lazy[f] = 0;
		if(l == r) return;
		int g=f<<1, m=(l+r)>>1;
		reset(g  , l  , m);
		reset(g|1, m+1, r);
	}

private:
	void propagation(int f, int g, int l, int r)
	{
		if(!lazy[f]) return;
		data[f] += lazy[f];
		if(l != r)
		{
			lazy[g  ] += lazy[f];
			lazy[g|1] += lazy[f];
		}
		lazy[f] = 0;
	}
} segtr[2];

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{	// Observe C/E and D/M are indistinguishable
		scanf(" %d%d", &M, &N);
		for(int i = 1; i <= M; ++i)
		for(int j = 0; j < 2; ++j)
			D[i][j].clear();
		for(int j = 0; j < 2; ++j)
			segtr[j].reset(1, 1, M);
		for(int i = 1; i <= N; ++i)
		{
			scanf(" %c", &C);
			A[i] = (C == 'C') || (C == 'E');
		}
		for(int i = 1; i <= N; ++i)
			scanf("%d", &S[i]);
		for(int i = 1; i <= N; ++i)
		{
			scanf("%d", &d);
			D[d][A[i]].push_back(i);
		}
		for(int i = 1; i <= M; ++i)
		for(int j = 0; j <  2; ++j)
		{
			std::sort(ALL(D[i][j]), [&](const int& l, const int& r) {
				return S[l] > S[r];	// Latest Start first
			});
			best[i][j] = best[i-1][j];
			for(auto pos: D[i][j]) if(S[pos] < i)
			{
				segtr[j^1].range(1, 1, M, 1, S[pos]);
				best[i][j] = std::max(segtr[j^1].query(1, 1, M, 1, S[pos]), best[i][j]);
			}
			segtr[j].point(1, 1, M, i, best[i][j]);
		}
		int cnt = 1;
		for(int i = 1; i <= M; ++i)
		{
			int at = std::max(best[i][0], best[i][1]);
			for(; cnt <= at; ++cnt)
				printf("%d ", i);
		}
		for(; cnt <= N; ++cnt)
			printf("-1 ");
		putchar('\n');
	}
	return 0;
}