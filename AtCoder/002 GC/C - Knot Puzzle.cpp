#include <cstdio>
const int MAXN = 1E5+5;
int array[MAXN]{ };
int L, M, N;

int main()
{
	scanf(" %d%d", &N, &L); M = -1;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &array[i]);
		if(array[i-1]+array[i] >= L)
			M = i-1;
	}
	if(M != -1)
	{
		puts("Possible");
		for(int i = 1; i < M; ++i)
			printf("%d\n", i);
		for(int i = N-1; i >= M; --i)
			printf("%d\n", i);
	}
	else
		puts("Impossible");
	return 0;
}