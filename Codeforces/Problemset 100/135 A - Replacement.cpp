#include <algorithm>
#include <cstdio>
const int MAXN = 1E5+5;
int	A[MAXN]{ };
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	std::sort(A+1, A+N+1);
	A[0] = 1;
	if(A[N] == 1)
		A[N-1] = 2;
	for(int i = 0; i < N; ++i)
		printf("%d%c", A[i], (i==N-1)?'\n':' ');
	return 0;
}