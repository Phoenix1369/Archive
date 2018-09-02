#include <cstdio>
int cnt=0, n;

int main()
{
	scanf("%d", &n);
	while(n)
	{
		++cnt;
		n >>= 1;
	}
	printf("%d\n", cnt);
	return 0;
}

