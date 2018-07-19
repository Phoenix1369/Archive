#include <cstdio>
const int MAXN = 105;
int a[MAXN]{ };
int d, n;

int main()
{
	scanf(" %d%d", &n, &d);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int d2=d*2, ret=2;
	for(int i = 1; i < n; ++i)
	{
		int dis = a[i] - a[i-1];
		if(dis > d2)
			ret += 2;
		else if(dis == d2)
			++ret;
	}
	printf("%d\n", ret);
    return 0;
}