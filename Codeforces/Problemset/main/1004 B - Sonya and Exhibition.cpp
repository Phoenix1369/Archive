#include <cstdio>
int n;

int main()
{
	scanf(" %d", &n);
	for(int i = 0; i < n; ++i)
		putchar('0'+(i&1));
	putchar('\n');
	return 0;
}