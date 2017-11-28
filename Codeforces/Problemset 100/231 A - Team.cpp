#include <cstdio>
int N, num, ret=0;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int sum = 0;
		for(int j = 0; j < 3; ++j)
		{
			scanf("%d", &num);
			sum += num;
		}
		if(sum > 1) ++ret;
	}
	printf("%d\n", ret);
	return 0;
}
