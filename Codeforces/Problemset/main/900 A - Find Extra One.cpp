#include <algorithm>
#include <cstdio>
int cnt[2]{ };
int N, x;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf(" %d%*d", &x);
		++cnt[x > 0];
	}
	puts((std::min(cnt[0],cnt[1]) <= 1) ? "Yes" : "No");
	return 0;
}