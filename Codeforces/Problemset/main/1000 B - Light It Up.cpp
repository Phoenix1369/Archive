#include <algorithm>
#include <cstdio>
const int MAXN = 1E5+5;
int A[MAXN]{ };
int lhs[MAXN]{ };
int rhs[MAXN]{ };
int N, ret=0;

int main()
{
	scanf("%d", &N);
	scanf("%d", &A[N+1]);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for(int i = 1; i <= N+1; i += 2)
		ret += A[i]-A[i-1];
	lhs[1] = A[1];
	for(int i = 2; i <= N+1; ++i)
		lhs[i] = lhs[i-2] + A[i]-A[i-1];
	rhs[N] = A[N+1]-A[N];
	for(int i = N-1; i >= 0; --i)
		rhs[i] = rhs[i+2] + A[i+1]-A[i];
	for(int i = 1; i <= N; i += 2)
		if(A[i+1]-A[i] > 1)
			ret = std::max(lhs[i]+rhs[i]-1, ret);
	printf("%d\n", ret);
	return 0;
}
