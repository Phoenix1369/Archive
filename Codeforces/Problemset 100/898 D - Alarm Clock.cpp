#include <algorithm>
#include <cstdio>
const int MAXN = 2E5+5;
int	A[MAXN]{ };
bool  off[MAXN]{ };
int K, M, N;

int main()
{
	scanf(" %d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	std::sort(A+1, A+N+1);
	int cnt=1, head=1, ret=0, tail=1;
	while(head <= N)
	{
		while((tail < N) && (cnt < K))
			++cnt, ++tail;
		if((cnt == K) && (A[tail]-A[head] < M))
			++ret, off[tail] = true, --cnt;
		if((tail == N) || (cnt == K))
		{
			if(!off[head]) --cnt;
			do { ++head; } while((head < N) && off[head]);
		}
	}
	printf("%d\n", ret);
	return 0;
}