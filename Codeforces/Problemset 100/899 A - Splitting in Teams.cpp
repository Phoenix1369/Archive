#include <algorithm>
#include <cstdio>
int cnt[2]{ };
int A, M, N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		++cnt[A&1];
	}
	M = std::min(cnt[0], cnt[1]);
	printf("%d\n", M+(cnt[1]-M)/3);
	return 0;
}