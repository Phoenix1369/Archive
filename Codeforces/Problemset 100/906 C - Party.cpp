#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 22;
const int MAXS = 1<<MAXN;
int	A[MAXN]{ };
bool conn[MAXS]{ };
int all, best, M, N, u, v;

int bct(int n) { return (n) ? __builtin_popcount(n) : 0; }

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i)
		A[i] |= 1<<i;
	for(int i = 0; i < M; ++i)
	{
		scanf("%d%d", &u, &v); --u, --v;
		A[u] |= 1<<v;
		A[v] |= 1<<u;
	}
	int lim=1<<N;
	all = best = lim-1;
	for(int i = 0; i < N; ++i)
		all &= A[i];
	if(all == best)
		return puts("0"), 0;
	for(int i = 0; i < N; ++i)
		conn[1<<i] = true;
	for(int mask = 0; mask < lim; ++mask) if(conn[mask])
	{
		int nxt = 0;
		for(int i = 0; i < N; ++i)
			if((mask>>i) & 1)
				nxt |= A[i];
		for(int i = 0; i < N; ++i)
			if((nxt>>i) & 1)
				conn[mask|(1<<i)] |= conn[mask];
		int oth = mask ^ (lim-1);
		if(((nxt & oth) == oth) && (bct(mask) < bct(best)))
			best = mask;
	}
	printf("%d\n", bct(best));
	for(int i = 0; i < N; ++i)
		if((best>>i) & 1)
			printf("%d ", i+1);
	putchar('\n');
	return 0;
}