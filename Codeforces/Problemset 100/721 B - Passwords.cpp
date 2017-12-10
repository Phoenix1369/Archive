#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXN = 105;
int	A[MAXN]{ };
char buff[MAXN]{ };
int K, N;

inline int f(int x) { return x + (x / K) * 5 + 1; }

int main()
{
	scanf(" %d%d", &N, &K);
	for(int i = 0; i <= N; ++i)
	{
		scanf(" %s", buff);
		A[i] = strlen(buff);
	}
	std::sort(A, A+N);
	int eq = std::upper_bound(A, A+N, A[N]) - A;
	int lt = std::lower_bound(A, A+N, A[N]) - A;
	printf("%d %d\n", f(lt), f(eq-1));
	return 0;
}