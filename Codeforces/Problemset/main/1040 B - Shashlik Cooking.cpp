#include <algorithm>
#include <cstdio>
int k, n;

int main()
{
	scanf(" %d%d", &n, &k);
	int m = 2*k+1;
	int q = n/m;
	int r = n-m*q;
	int b = k+1;
	if(r)
	{
		if(r <= k)
		{
			b -= (k+1)-r;
			++q;
		}
		else
			++q;
	}
	b = std::max(1,b);
	printf("%d\n", q);
	for(int i = 0; i < q; ++i)
		printf("%d ", b+i*m);
	putchar('\n');
	return 0;
}
// 7 2
// o O o o | o o O
// 5 1
// o O o | o O
// 6 2
// O o o | o o O
