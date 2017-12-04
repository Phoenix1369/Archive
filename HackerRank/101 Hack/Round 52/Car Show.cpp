#include <cstdio>
#include <set>
#include <unordered_map>
typedef long long lld;
const int MAXN = 1E5+5;
int	A[MAXN]{ };
lld  memo[MAXN]{ }; // memo[l]: Distinct Subarrays starting at `l`
int  next[MAXN]{ };
std::unordered_map<int,int> pos;
std::set<int> end;
int N, Q;

inline bool f(int p, int R)
{
	return memo[p]-memo[p-1] > (R-p+1);
}

inline lld sigma(int K) { return 1LL*K*(K+1)>>1; }

int main()
{
	scanf(" %d%d", &N, &Q);
	pos.reserve(N);
	for(int i = 1; i <= N; ++i)
		next[i] = N+1;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		if(pos.count(A[i]))
			next[pos.at(A[i])] = i;
		pos[A[i]] = i;
	}
	int tail = 1;
	for(int i = 1; i <= N; ++i)
	{	// Two-Pointers Algorithm
		end.insert(next[tail]);
		if(tail <= N) ++tail;
		while(tail < *end.begin())
		{
			end.insert(next[tail]);
			++tail;
		}
		memo[i] = tail-i;
		end.erase(next[i]);
		if(tail > i+1) --tail;
	}
	for(int i = 1; i <= N; ++i)
		memo[i] += memo[i-1];
	int hi, L, lo, R;
	for(int _ = 0; _ < Q; ++_)
	{
		scanf(" %d%d", &L, &R);
		lo = L, hi = R+1;
		while(lo < hi)
		{	// Binary Search
			int ce = (lo+hi)>>1;
			if(f(ce, R))
				hi = ce;
			else
				lo = ce+1;
		}
		// Subtract subarrays extending past R
		printf("%lld\n", memo[lo-1]-memo[L-1]+sigma(R-lo+1));
	}
	return 0;
}
