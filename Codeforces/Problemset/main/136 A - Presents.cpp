#include <cstdio>
const int MAXN = 105;
int	A[MAXN]{ };
int B, N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &B);
		A[B] = i;
	}
	for(int i = 1; i <= N; ++i)
		printf("%d%c", A[i], (i==N)?'\n':' ');
	return 0;
}