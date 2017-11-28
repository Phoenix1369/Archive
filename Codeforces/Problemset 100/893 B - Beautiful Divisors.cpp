#include <cstdio>
int K, N, ret=1;

int main()
{
	scanf("%d", &N);
	for(int k = 0; K <= N; ++k)
	{
		K = ((1<<(k+1))-1)*(1<<k);
		if((N % K) == 0)
			ret = K;
	}
	printf("%d\n", ret);
	return 0;
}
