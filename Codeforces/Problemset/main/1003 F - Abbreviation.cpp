#include <algorithm>
#include <cstdio>
#include <cstring>
const int HASH[] = { 999000911, 999000991 };
const int MAXC = 1e5+5;
const int MAXN = 305;
const int MOD = 1e9+7;
int id[MAXN], seg[MAXN][MAXN];
int len[MAXN]{ };
char w[MAXC];
int n;

int main()
{
	scanf("%d", &n);
	int best=0, sum = n-1;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", w);
		len[i] = strlen(w);
		id[i] = 0;
		for(int j = 0; j < len[i]; ++j)
			id[i] = ((1LL*HASH[0]*id[i] % MOD) + w[j]) % MOD;
		len[i] += len[i-1];
	}
	sum += len[n];
	for(int i = 1; i <= n; ++i)
		seg[i][i] = id[i];
	for(int i = 1; i <= n; ++i)
	for(int j = i+1; j <= n; ++j)
		seg[i][j] = ((1LL*HASH[1]*seg[i][j-1] % MOD) + id[j]) % MOD;
	// Greedily match
	for(int i = 1; i <= n; ++i)
	for(int j = 0; i+j <= n; ++j) // Segment Length
	{
		int cnt = 1;
		for(int k = i+j+1; k+j <= n; ++k)
			if(seg[i][i+j] == seg[k][k+j])
			{
				k += j;
				++cnt;
			}
		if(cnt > 1)
			best = std::max((len[i+j]-len[i-1]-1)*cnt, best);
	}
	printf("%d\n", sum-best);
	return 0;
}
