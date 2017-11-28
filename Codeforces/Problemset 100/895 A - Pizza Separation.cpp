#include <algorithm>
#include <cstdio>
const int MAXN = 360;
int	A[MAXN+1]{ };
int N, ret=MAXN;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for(int i = 1; i <= N; ++i)
		A[i] += A[i-1];
	for(int i = 1; i <= N; ++i)
	for(int j = i; j <= N; ++j)
		ret = std::min(std::abs(MAXN - 2*(A[j]-A[i-1])), ret);
	printf("%d\n", ret);
	return 0;
}
