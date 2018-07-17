#include <cstdio>
int a, k, n;

int main()
{
	scanf(" %d%d", &n, &k);
	int ls=-1, rs=-2;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		if(a > k)
		{
			if(ls == -1)
				ls = i;
			rs = i;
		}
	}
	printf("%d\n", ls+n-rs-1);
    return 0;
}
