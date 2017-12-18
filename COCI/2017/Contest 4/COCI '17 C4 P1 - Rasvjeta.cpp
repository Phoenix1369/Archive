#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
bool	S[MAXN]{ };
int K, M, N, X;

int main()
{
	scanf(" %d%d%d", &N, &M, &K);
	for(int i = 0; i < M; ++i)
	{
		scanf("%d", &X);
		int end = std::min(N, X+K);
		for(int j = std::max(1, X-K); j <= end; ++j)
			S[j] = true;
	}
	int ret = 0;
	for(int i = 1; i <= N; ++i) if(!S[i])
	{
		for(int j = std::min(K*2, N-i); j >= 0; --j)
			S[i+j] = true;
		++ret;
	}
	printf("%d\n", ret);
	return 0;
}