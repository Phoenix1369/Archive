#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 1e5+5;
int a[MAXN], lft[MAXN]{ }, rgt[MAXN]{ };
vin other;
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if(!lft[a[i]])
			lft[a[i]] = i;
		rgt[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		if(rgt[a[i]] == i)
			other.push_back(i);
	lld ret=0LL;
	for(int i = 1; i <= n; ++i)
		if(lft[a[i]] == i)
			ret += other.end() - std::lower_bound(ALL(other), i+1);
	printf("%lld\n", ret);
	return 0;
}