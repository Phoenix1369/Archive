#include <cstdio>
#include <set>
typedef long long lld;
const int MAXN = 2e5+5;
int cnt[MAXN]{ };
int inc[MAXN]{ };
int a[MAXN];
std::set<int> need;
int c, m, n;

int main()
{
	scanf(" %d%d", &n, &m);
	c = n / m;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		++cnt[a[i] % m];
	}
	for(int i = 0; i < m; ++i)
		if(cnt[i] < c)
			need.insert(i);
	lld ret = 0LL;
	for(int i = 0; i < n; ++i)
	{
		int j = a[i] % m, mov;
		if(cnt[j] > c)
		{
			auto ktr = need.lower_bound(j);
			if(ktr == need.end())
			{
				ktr = need.lower_bound(0);
				mov = *ktr + m - j;
			}
			else
				mov = *ktr - j;
			a[i] += mov;
			ret += mov;
			if(++cnt[*ktr] == c)
				need.erase(ktr);
			--cnt[j];
		}
	}
	printf("%lld\n", ret);
	for(int i = 0; i < n; ++i)
		printf("%d ", a[i]);
    return 0;
}
