#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int cnt[MAXN]{ };
int A, M=0, N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		M = std::max(++cnt[A], M);
	}
	printf("%d\n", M);
	return 0;
}
