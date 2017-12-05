#include <cstdio>
const int LIM = 1E9+5;
int d, mul, N, Q, T;

int main()
{
	scanf("%d", &T);
	for(int i = 0; i < T; ++i)
	{
		mul = 1;
		scanf(" %d%d", &N, &Q);
		for(int j = 0; j < N; ++j)
		{
			scanf("%d", &d);
			if(1LL*d*mul < LIM)
				mul *= d;
			else	mul = LIM;
		}
		for(int j = 0; j < Q; ++j)
		{
			scanf("%d", &d);
			printf("%d ", d / mul);
		}
		putchar('\n');
	}
	return 0;
}
