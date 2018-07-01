#include <cstdio>
typedef long long lld;
int A, D, N, ret=0;
lld high, luba;

int main()
{
	scanf(" %d%d", &N, &D);
	bool valid = true;
	high = luba = 0LL;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		high += A;
		luba += A;
		if(high > D) high = D;
		if(!A && (luba < 0))
		{
			if(high < 0)
			{
				high = D;
				++ret;
			}
			luba = 0;
		}
		if(luba > D) valid = false;
	}
	if(!valid) return puts("-1"), 0;
	printf("%d\n", ret);
	return 0;
}
