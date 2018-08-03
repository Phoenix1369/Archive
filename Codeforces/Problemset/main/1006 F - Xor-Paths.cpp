#include <cstdio>
#include <unordered_map>
typedef long long lld;
const int MAXN = 20;
std::unordered_map<lld,int> cnt[MAXN][MAXN]{ };
lld a[MAXN][MAXN]{ };
int half, whole;
lld k, ret=0LL;
int m, n;

void dfs_dr(int i, int j, int step, lld val)
{
	val ^= a[i][j];
	if(step == half)
	{
		++cnt[i][j][val];
		return;
	}
	if(i < n-1) dfs_dr(i+1, j, step+1, val);
	if(j < m-1) dfs_dr(i, j+1, step+1, val);
}

void dfs_ul(int i, int j, int step, lld val)
{
	if(step == whole-half)
	{
		lld key = k^val;
		if(cnt[i][j].count(key))
			ret += cnt[i][j].at(key);
		return;
	}
	val ^= a[i][j];
	if(i > 0) dfs_ul(i-1, j, step+1, val);
	if(j > 0) dfs_ul(i, j-1, step+1, val);
}

int main()
{
	scanf(" %d%d%lld", &n, &m, &k);
	whole = n+m-2;
	half = (whole+1)/2;
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
		scanf("%lld", &a[i][j]);
	dfs_dr(0, 0, 0, 0);
	dfs_ul(n-1, m-1, 0, 0);
	printf("%lld\n", ret);
	return 0;
}
