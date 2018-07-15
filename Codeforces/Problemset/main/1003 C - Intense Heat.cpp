#include <algorithm>
#include <cstdio>
const int MAXN = 5005;
int A[MAXN]{ };
double ret=0.0;
int K, N;

int main()
{
	scanf(" %d%d", &N, &K);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		A[i] += A[i-1];
	}
	for(int i = K; i <= N; ++i)
	for(int j = i-K; j >= 0; --j)
		ret = std::max(1.0 * (A[i]-A[j]) / (i-j), ret);
	printf("%.6f\n", ret);
	return 0;
}
