#include <cstdio>
typedef long long lld;
int K;

int main()
{
	scanf("%d", &K);
	lld pre_sum = 1LL*K*(K-1)/2;
	lld src = pre_sum*2+1;
	printf("%lld\n", src*K + pre_sum*2);
	return 0;
}
