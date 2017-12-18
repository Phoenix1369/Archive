#include <algorithm>
#include <cstdio>
const int MAXM = 15;
const int MAXN = 105;
int	V[MAXN][MAXM]{ };
int K, M, N;

inline int bc(int n) { return n ? __builtin_popcount(n) : 0; }

int dupvote(int nope)
{
	int cnt[MAXM]{ };
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < M; ++j)
		if(((nope>>V[i][j]) & 1) == 0)
		{
			++cnt[V[i][j]];
			break;
		}
	int res = 0;
	for(int i = 1; i < M; ++i)
		if(cnt[i] > cnt[res])
			res = i;
	return res;
}

int main()
{
	scanf(" %d%d%d", &N, &M, &K); --K;
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < M; ++j)
	{
		scanf("%d", &V[i][j]);
		--V[i][j];
	}
	printf("%d\n", dupvote(0)+1);
	int ans=M, L = 1<<M;
	for(int mask = 0; mask < L; ++mask)
	{
		if((mask>>K) & 1) continue;
		if(dupvote(mask) == K)
			ans = std::min(bc(mask), ans);
	}
	printf("%d\n",	ans);
	return 0;
}