#include <cstdio>
int bill[5] = { 100, 20, 10, 5, 1 };
int n, ret=0;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < 5; ++i)
	{
		ret += n / bill[i];
		n %= bill[i];
	}
	printf("%d\n", ret);
    return 0;
}
