#include <cstdio>
const int LOGN = 32;
int cnt[LOGN]{ };
int A, N, Q;

int log_2(int num)
{
	int res;
	for(res = 0; (num & 1) == 0; ++res)
		num >>= 1;
	return res;
}

int main()
{
	scanf(" %d%d", &N, &Q);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		++cnt[log_2(A)];
	}
	int amt, ret, sum;
	for(int i = 0; i < Q; ++i)
	{
		scanf("%d", &amt);
		ret = sum = 0;
		for(int j = LOGN-1; (j >= 0) && (sum < amt); --j)
			if(sum + (1LL<<j) * cnt[j] <= amt)
			{
				sum += (1LL<<j) * cnt[j];
				ret += cnt[j];
			}
			else
			{
				int mul = (amt-sum)>>j;
				ret += mul;
				sum += mul<<j;
			}
		if(sum < amt)
			ret = -1;
		printf("%d\n", ret);
	} 
	return 0;
}
