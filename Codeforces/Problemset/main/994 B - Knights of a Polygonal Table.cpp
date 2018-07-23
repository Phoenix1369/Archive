#include <algorithm>
#include <cstdio>
#include <map>
typedef long long lld;
const int MAXN = 1e5+5;
std::map<int,int> set;
lld ret[MAXN]{ };
int k, n;

struct Knight { int c, i, p; } kni[MAXN];

int main()
{
	scanf(" %d%d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", &kni[i].p);
	for(int i = 0; i < n; ++i)
		scanf("%d", &kni[i].c);
	for(int i = 0; i < n; ++i)
		kni[i].i = i;
	std::sort(kni, kni+n, [](const Knight& lft, const Knight& rgt) {
		return lft.p < rgt.p;
	});
	lld sum = 0LL;
	for(int i = 0; i < n; ++i)
	{
		++set[kni[i].c];
		sum += kni[i].c;
		ret[kni[i].i] = sum;
		if(i >= k)
		{
			int min = set.begin()->first;
			if(!--set[min])
				set.erase(min);
			sum -= min;
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%lld\n", ret[i]);
    return 0;
}
