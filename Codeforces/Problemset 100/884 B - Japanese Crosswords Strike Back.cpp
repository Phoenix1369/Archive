#include <cstdio>
int A, N, X;

int main()
{
	scanf(" %d%d", &N, &X);
	int ret = N-1;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		ret += A;
	}
	puts((ret == X) ? "YES" : "NO");
	return 0;
}