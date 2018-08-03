#include <cstdio>
int a, n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		a -= (a & 1) ^ 1;
		printf("%d ", a);
	}
    return 0;
}
