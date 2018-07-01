#include <cstdio>
int N, A, B;

int main()
{
	scanf(" %d%d%d", &N, &A, &B);
	for(int i = 0; i*A <= N; ++i)
		if((N - i*A) % B == 0)
			return printf("YES\n%d %d\n", i, (N - i*A) / B) & 0;
	puts("NO");
	return 0;
}