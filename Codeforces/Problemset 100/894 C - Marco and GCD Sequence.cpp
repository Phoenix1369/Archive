#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
int	A[MAXN]{ };
int M;

int main()
{
	scanf("%d", &M);
	for(int i = 0; i < M; ++i)
		scanf("%d", &A[i]);
	bool yes = true;
	for(int i = 1; i < M; ++i)
		yes &= !(A[i] % A[0]);
	if(!yes) return puts("-1"), 0;
	int N = 2*M-1;
	printf("%d\n%d ", N, A[0]);
	for(int i = 1; i < M; ++i)
		printf("%d %d ", A[i], A[0]);
	putchar('\n');
	return 0;
}
