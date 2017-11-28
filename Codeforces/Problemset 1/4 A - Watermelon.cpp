#include <cstdio>
int N;

int main()
{
	scanf("%d", &N);
	puts(((N & 1) || (N < 3)) ? "NO" : "YES");
	return 0;
}