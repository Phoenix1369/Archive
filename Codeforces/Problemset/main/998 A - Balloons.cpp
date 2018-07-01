#include <algorithm>
#include <cstdio>
const int MAXN = 12;
int A[MAXN]{ };
int M=MAXN-1, N;

int main()
{
	scanf("%d", &N);
	A[M]=1005;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
		if(A[i] < A[M])
			M = i;
	}
	std::sort(A, A+N);
	if((N == 1) || ((N == 2) && (A[0] == A[1])))
		puts("-1");
	else
		printf("1\n%d\n", M+1);
    return 0;
}