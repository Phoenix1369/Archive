#include <cstdio>
typedef long long lld;
int n, q, x, y;

int main()
{
	scanf(" %d%d", &n, &q);
	int nh = n/2;
	lld nnh = (1LL*n*n+1)/2;
	for(int h = 0; h < q; ++h)
	{
		scanf(" %d%d", &x, &y);
		int sum = x+y;
		lld ret = 1LL*(x-1)*nh + (y-1)/2 + 1;
		if(n & 1)
		{
			if(sum & 1)
				ret += (x-1)/2;
			else
				ret += x/2;
		}
		if(sum & 1)
			ret += nnh;
		printf("%lld\n", ret);
	}
	return 0;
}
