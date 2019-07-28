#include <cstdio>
int a, N, ret=0;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &a);
		ret += a-1;
	}
	printf("%d\n", ret);
	return 0;
}
