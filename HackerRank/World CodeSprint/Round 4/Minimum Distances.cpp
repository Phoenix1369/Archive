#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
int	A[MAXN]{ };
int M=MAXN, N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	for(int i = 0; i < N; ++i)
	for(int j = i+1; j < N; ++j)
		if(A[i] == A[j])
		{
			M = std::min(j-i, M);
			break;
		}
	if(M != MAXN)
		printf("%d\n", M);
	else
		puts("-1");
	return 0;
}