#include <cstdio>
const int DAYS = 86400;
int A, N, T;

int main()
{
	scanf(" %d%d", &N, &T);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A);
		T -= DAYS - A;
		if(T <= 0) return printf("%d\n", i) & 0;
	}
	return 0;
}