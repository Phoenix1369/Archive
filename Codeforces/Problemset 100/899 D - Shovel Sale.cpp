#include <cstdio>
typedef long long lld;
int N, ret=0, T=1;

int main()
{
	scanf("%d", &N);
	int end = 2*N-1;
	for(T = 1; 10LL*T-1 <= end; T *= 10);
	for(lld sum = T-1; sum <= end; sum += T)
		if(sum > N)
			ret += (sum-1)/2 - (sum-N-1);
		else
			ret += (sum-1)/2;
	printf("%d\n",	ret);
	return 0;
}