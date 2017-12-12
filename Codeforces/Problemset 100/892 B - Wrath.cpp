#include <algorithm>
#include <cstdio>
const int MAXN = 1E6+5;
int	L[MAXN]{ };
int live, N, ret;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &L[i]);
	live = N; ret = 0;
	for(int i = N-1; i >= 0; --i)
	{
		if(i < live) ++ret;
		live = std::min(i-L[i], live);
	}
	printf("%d\n", ret);
	return 0;
}