#include <cstdio>
const int MAXN = 1e5+5;
int a[MAXN]{ };
int min=1e9, n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (min > a[i])
			min = a[i];
	}
	int beg = min % n;
	for(int i = 0; i < n; ++i)
	{
		if(a[beg] <= min)
			return printf("%d\n", beg+1) & 0;
		beg = (beg+1) % n;
		++min;
	}
    return 0;
}
