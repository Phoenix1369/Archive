#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
lld a[MAXN]{ };
int b[MAXN<<1];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	int beg = -1;
	int M = *std::max_element(b, b+n);
	for(int i = 0; i < n; ++i)
	{
		b[i+n] = b[i];
		if((b[i] == M) && (b[i+n-1] < M))
			beg = i+n;
	}
	if(beg == -1)
	{
		puts(M ? "NO" : "YES");
		if(!M)
			for(int i = 0; i < n; ++i)
				printf("1 ");
		return 0;
	}
	a[beg-n+1] = b[beg];
	for(int i = 0; i < n; ++i)
	{
		int j = beg-i;
		if(j >= n)
			a[j-n] = b[j] + a[j-n+1];
		else
			a[j] = b[j] + a[j+1];
		if(j == n)
			a[n] = a[0];
	}
	a[beg-n] -= b[beg];
	puts("YES");
	for(int i = 0; i < n; ++i)
		printf("%lld ", a[i]);
	return 0;
}
