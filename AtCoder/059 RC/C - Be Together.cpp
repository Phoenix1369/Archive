#include <cstdio>
#include <map>
#define SQR(x) ((x)*(x))
std::map<int, int> cnt;
int ans=2E9, N, tem;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &tem);
		++cnt[tem];
	}
	for(int itr = -100; itr <= 100; ++itr)
	{	// Brute Force all Destinations
		tem = 0;
		for(auto& jtr: cnt)
			tem += SQR(jtr.first - itr) * jtr.second;
		ans = std::min(tem, ans);
	}
	printf("%d\n", ans);
	return 0;
}