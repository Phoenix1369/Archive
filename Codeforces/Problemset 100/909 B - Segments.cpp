#include <cstdio>
int h, N;

int main()
{
	scanf("%d", &N); h = N/2;
	printf("%d\n", (h+1)*(N-h));
	return 0;
}