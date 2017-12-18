#include <algorithm>
#include <cstdio>
const int BUCK = 505; // Bucket Size > sqrt(N)
const int MAXF = 40;
const int MAXN = 1E5+5;
const int MOD  = 1E9;
int	A[MAXN]{ };
int	F[MAXF]{ };
int  freq[BUCK][MAXF+5]{ };
int  incr[BUCK]{ };
int N, Q;

inline int  aggreg(int real) { return (real < MAXF) ? F[real] : 0; }

inline void update(int k, int i)
{
	if(A[i] == MAXF) return;
	--freq[k][A[i]++];
	++freq[k][A[i]];
}

int main()
{
	F[0] = 1;
	for(int i = 1; i < MAXF; ++i)
		F[i] = 1LL*F[i-1]*i % MOD;
	scanf(" %d%d", &N, &Q);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		A[i] = std::min(MAXF, A[i]);
		++freq[i/BUCK][A[i]];
	}
	for(int _ = 0; _ < Q; ++_)
	{
		int cmd, l, r;
		scanf(" %d%d%d", &cmd, &l, &r);
		int beg = (l+BUCK-1)/BUCK;
		int cur = l/BUCK;
		int end = (r+1)/BUCK;
		if(cmd == 1)
		{	// Range Update
			if(beg < end)
			{
				for(int k = beg; k < end; ++k)
					++incr[k];
				for(int i = l; i < beg*BUCK; ++i)
					update(cur, i);
				for(int i = end*BUCK; i <= r; ++i)
					update(end, i);
			}
			else
				for(int i = l; i <= r; ++i)
					update(i/BUCK, i);
		}
		else if(cmd == 2)
		{	// Range Query
			int ret = 0;
			if(beg < end)
			{
				for(int k = beg; k < end; ++k)
					for(int j = 1; j+incr[k] < MAXF; ++j)
						ret = (1LL*F[j+incr[k]]*freq[k][j] % MOD + ret) % MOD;
				for(int i = l; i < beg*BUCK; ++i)
					ret = (1LL*aggreg(A[i]+incr[cur]) + ret) % MOD;
				for(int i = end*BUCK; i <= r; ++i)
					ret = (1LL*aggreg(A[i]+incr[end]) + ret) % MOD;
			}
			else
				for(int i = l; i <= r; ++i)
					ret = (1LL*aggreg(A[i]+incr[i/BUCK]) + ret) % MOD;
			printf("%d\n", ret);
		}
		else	// (cmd == 3)
		{	// Point Update - Normalize Bucket
			int u = std::max(cur*BUCK, 1);
			int v = std::min((cur+1)*BUCK-1, N);
			for(int k = 0; k <= MAXF; ++k)
				freq[cur][k] = 0;
			for(int i = u; i <= v; ++i)
				A[i] = std::min(MAXF, A[i]+incr[cur]);
			incr[cur] = 0;
			A[l] = std::min(MAXF, r);
			for(int i = u; i <= v; ++i)
				++freq[cur][A[i]];
		}
	}
	return 0;
}