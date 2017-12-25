#include <cstdio>
typedef long long lld;
int cnt=0;
lld X, Y;

int main()
{
	scanf("%lld%lld", &X, &Y);
	while(X <= Y) X *= 2, ++cnt;
	printf("%d\n", cnt);
	return 0;
}