#include <algorithm>
#include <cstdio>
#include <map>
typedef long long lld;
const int MAXN = 2E5+5;
lld ret[MAXN]{ };
std::map<lld,int> diff;
int cnt=0, N;
lld prv=1E18;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		lld x, y;
		scanf(" %lld%lld", &x, &y);
		prv = std::min(x, prv);
		++diff[x];
		--diff[y+1];
	}
	for(auto pts: diff)
	{
		ret[cnt] += pts.first - prv;
		cnt += pts.second;
		prv = pts.first;
	}
	for(int i = 1; i <= N; ++i)
		printf("%lld ", ret[i]);
	putchar('\n');
	return 0;
}
