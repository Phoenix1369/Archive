#include <cstdio>
int A[1005]{ };
int N, ret=0;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for(int i = 2; i <  N; ++i)
		if(	((A[i-1] < A[i]) && (A[i+1] < A[i])) ||
			((A[i-1] > A[i]) && (A[i+1] > A[i])) )
			++ret;
	printf("%d\n", ret);
	return 0;
}
