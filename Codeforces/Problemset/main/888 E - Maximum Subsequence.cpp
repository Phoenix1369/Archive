#include <cstdio>
#include <set>
const int HALF = 18;
const int MAXN = 37;
int	A[MAXN]{ };
std::set<int> cache;
int M, N;

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
		A[i] %= M;
	}
	int n = std::min(N, HALF);
	int L = 1 << n;
	for(int mask = 1; mask < L; ++mask)
	{
		int agg = 0;
		for(int bit = 0; bit < n; ++bit)
			if((mask >> bit) & 1)
				agg = (1LL * agg + A[bit]) % M;
		cache.insert(agg);
	}
	int ret = *cache.rbegin();
	if(N <= HALF) return printf("%d\n", ret) & 0;
	int nn = N-HALF;
	int LL = 1 << nn;
	for(int mask = 1; mask < LL; ++mask)
	{
		int agg = 0;
		for(int bit = 0; bit < nn; ++bit)
			if((mask >> bit) & 1)
				agg = (1LL * agg + A[bit+n]) % M;
		ret = std::max(agg, ret);
		int val = M-agg-1;
		auto ptr = cache.lower_bound(val);
		if((ptr != cache.begin()) &&
			((ptr == cache.end()) || (*ptr > val)))
			--ptr;
		if(ptr != cache.end())
			ret = std::max((agg+*ptr) % M, ret);
	}
	printf("%d\n", ret);
	return 0;
}
