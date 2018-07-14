#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1E5+5;
int L[MAXN]{ };
int R[MAXN]{ };
lld sum=0LL;
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &L[i]);
	for(int i = 0; i < N; ++i)
		scanf("%d", &R[i]);
	for(int i = 1; i < N; ++i)
	{
		if(R[i-1] <= L[i])
		{
			R[i] = L[i];
			sum += L[i]-R[i-1];
		}
		else if(L[i-1] >= R[i])
		{
			L[i] = R[i];
			sum += L[i-1]-R[i];
		}
		else
		{
			L[i] = std::max(L[i-1], L[i]);
			R[i] = std::min(R[i-1], R[i]);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
